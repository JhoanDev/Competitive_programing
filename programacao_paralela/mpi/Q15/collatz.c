#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define comm MPI_COMM_WORLD
#define MAX 100000000

#define TAG_TAREFA 1
#define TAG_RESULTADO 2
#define TAG_FIM 3

int collatz_passos(int n)
{
    int passos = 0;
    long long val = n;

    while (val != 1)
    {
        if (!(val & 1))
            val = val / 2;
        else
            val = 3 * val + 1;
        passos++;
    }
    return passos;
}

int main(int argc, char *argv[])
{
    int my_rank, comm_sz;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(comm, &my_rank);
    MPI_Comm_size(comm, &comm_sz);
    double start_time, end_time, min_time, max_time;

    MPI_Status status;

    MPI_Barrier(comm);
    start_time = MPI_Wtime();

    if (my_rank == 0)
    {
        int num_enviado = 1;
        int maior_passos = 0;
        int num_com_maior = 0;
        int resultado_recebido[2]; // [0] = número, [1] = passos

        for (int proc = 1; proc < comm_sz && num_enviado <= MAX; proc++, num_enviado++)
        {
            MPI_Send(&num_enviado, 1, MPI_INT, proc, TAG_TAREFA, comm);
        }

        int processos_ativos = comm_sz - 1;
        while (processos_ativos > 0)
        {
            MPI_Recv(resultado_recebido, 2, MPI_INT, MPI_ANY_SOURCE, TAG_RESULTADO, comm, &status);

            if (resultado_recebido[1] > maior_passos)
            {
                maior_passos = resultado_recebido[1];
                num_com_maior = resultado_recebido[0];
            }

            if (num_enviado <= MAX)
            {
                MPI_Send(&num_enviado, 1, MPI_INT, status.MPI_SOURCE, TAG_TAREFA, comm);
                num_enviado++;
            }
            else
            {
                MPI_Send(NULL, 0, MPI_INT, status.MPI_SOURCE, TAG_FIM, comm);
                processos_ativos--;
            }
        }

        printf("Maior número de passos: %d (Número: %d)\n", maior_passos, num_com_maior);
    }
    else
    {
        int tarefa_atual;
        int tarefa_proxima;
        int resultado_anterior[2]; // {numero, passos}
        MPI_Request req_envio_resultado, req_recebe_tarefa;

        MPI_Recv(&tarefa_atual, 1, MPI_INT, 0, TAG_TAREFA, comm, &status);

        while (status.MPI_TAG != TAG_FIM)
        {
            MPI_Irecv(&tarefa_proxima, 1, MPI_INT, 0, MPI_ANY_TAG, comm, &req_recebe_tarefa);

            int passos = collatz_passos(tarefa_atual);
            resultado_anterior[0] = tarefa_atual;
            resultado_anterior[1] = passos;

            MPI_Isend(resultado_anterior, 2, MPI_INT, 0, TAG_RESULTADO, comm, &req_envio_resultado);

            MPI_Wait(&req_recebe_tarefa, &status);
            tarefa_atual = tarefa_proxima;
            MPI_Wait(&req_envio_resultado, MPI_STATUS_IGNORE);
        }
    }

    end_time = MPI_Wtime();
    MPI_Reduce(&start_time, &min_time, 1, MPI_DOUBLE, MPI_MIN, 0, comm);
    MPI_Reduce(&end_time, &max_time, 1, MPI_DOUBLE, MPI_MAX, 0, comm);

    if (my_rank == 0)
    {
        printf("Tempo de execucao: %f segundos\n", max_time - min_time);
    }

    MPI_Finalize();
    return 0;
}