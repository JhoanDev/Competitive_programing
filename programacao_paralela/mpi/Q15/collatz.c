#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define comm MPI_COMM_WORLD
#define MAX 100000000

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
    int my_rank, comm_sz, tag_tarefa = 0, tag_num = 1, tag_passos = 2;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(comm, &my_rank);
    MPI_Comm_size(comm, &comm_sz);
    double start_time, end_time, min_time, max_time;

    MPI_Status status;
    MPI_Request req_envio1, req_envio2, req_recebe;

    MPI_Barrier(comm);
    start_time = MPI_Wtime();

    if (my_rank == 0)
    {
        int num_enviado = 1;
        int num_recebido, passos_recebidos;
        int maior_passos = 0;
        int num_com_maior = 0;

        for (int proc = 1; proc < comm_sz && num_enviado <= MAX; proc++, num_enviado++)
        {
            MPI_Isend(&num_enviado, 1, MPI_INT, proc, tag_tarefa, comm, &req_envio1);
            MPI_Wait(&req_envio1, MPI_STATUS_IGNORE);
        }

        int processos_ativos = comm_sz - 1;
        while (processos_ativos > 0)
        {
            MPI_Recv(&num_recebido, 1, MPI_INT, MPI_ANY_SOURCE, tag_num, comm, &status);
            MPI_Recv(&passos_recebidos, 1, MPI_INT, status.MPI_SOURCE, tag_passos, comm, MPI_STATUS_IGNORE);

            if (passos_recebidos > maior_passos)
            {
                maior_passos = passos_recebidos;
                num_com_maior = num_recebido;
            }

            if (num_enviado <= MAX)
            {
                MPI_Isend(&num_enviado, 1, MPI_INT, status.MPI_SOURCE, tag_tarefa, comm, &req_envio1);
                num_enviado++;
                MPI_Wait(&req_envio1, MPI_STATUS_IGNORE);
            }
            else
            {
                int fim = -1;
                MPI_Isend(&fim, 1, MPI_INT, status.MPI_SOURCE, tag_tarefa, comm, &req_envio1);
                processos_ativos--;
                MPI_Wait(&req_envio1, MPI_STATUS_IGNORE);
            }
        }

        printf("Maior número de passos: %d (Número: %d)\n", maior_passos, num_com_maior);
    }
    else
    {
        while (1)
        {
            int numero;
            MPI_Irecv(&numero, 1, MPI_INT, 0, tag_tarefa, comm, &req_recebe);
            MPI_Wait(&req_recebe, MPI_STATUS_IGNORE);

            if (numero == -1)
                break;

            int passos = collatz_passos(numero);

            MPI_Isend(&numero, 1, MPI_INT, 0, tag_num, comm, &req_envio1);
            MPI_Isend(&passos, 1, MPI_INT, 0, tag_passos, comm, &req_envio2);
            MPI_Wait(&req_envio1, MPI_STATUS_IGNORE);
            MPI_Wait(&req_envio2, MPI_STATUS_IGNORE);
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