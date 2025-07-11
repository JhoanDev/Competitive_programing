#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define max 10000
#define comm MPI_COMM_WORLD

void gen_data(int *array, int size);
void check_cyclic_distribution(int *local_data, int local_size, int my_rank, int comm_sz);
void check_block_distribution(int *local_data, int local_size, int my_rank, int comm_sz, int size_data);

int main(int argc, char *argv[])
{
    int my_rank, comm_sz, size_data, rest, local_size_data, i, chunk, j, c, offset;
    int *global_data = NULL, *local_data = NULL, *send_counts = NULL, *displs = NULL;
    double start_time, end_time, elapsed_time;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(comm, &comm_sz);
    MPI_Comm_rank(comm, &my_rank);

    if (my_rank == 0)
    {
        if (argc != 2)
        {
            fprintf(stderr, "Erro: Argumento ausente.\n");
            fprintf(stderr, "Uso: mpiexec -n <num_procs> %s <tamanho_do_array>\n", argv[0]);
            size_data = -1;
        }
        else
        {
            size_data = atoi(argv[1]);
            if (size_data <= 0)
            {
                fprintf(stderr, "Erro: O tamanho do array deve ser um número positivo.\n");
                size_data = -1;
            }
        }
    }

    MPI_Bcast(&size_data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (size_data <= 0)
    {
        MPI_Finalize();
        exit(1);
    }
    // espalhando em bloco
    chunk = size_data / comm_sz;
    rest = size_data % comm_sz;
    local_size_data = chunk + (my_rank < rest);
    local_data = (int *)malloc(local_size_data * sizeof(int));

    if (my_rank == 0)
    {
        global_data = (int *)malloc(size_data * sizeof(int));
        send_counts = (int *)malloc(comm_sz * sizeof(int));
        displs = (int *)malloc(comm_sz * sizeof(int));

        offset = 0;
        for (i = 0; i < comm_sz; i++)
        {
            send_counts[i] = chunk + (i < rest);
            displs[i] = offset;
            offset += send_counts[i];
        }

        gen_data(global_data, size_data);
    }

    MPI_Scatterv(global_data, send_counts, displs, MPI_INT, local_data, local_size_data, MPI_INT, 0, comm);
    MPI_Barrier(comm);
    // iniciando a juntar e redistribuir ciclicamente
    start_time = MPI_Wtime();

    MPI_Gatherv(local_data, local_size_data, MPI_INT, global_data, send_counts, displs, MPI_INT, 0, comm);
    if (my_rank == 0)
    {
        for (i = 0; i < comm_sz; i++)
        {
            c = chunk + (i < rest ? 1 : 0);

            MPI_Datatype cyclic_type;
            MPI_Type_vector(c, 1, comm_sz, MPI_INT, &cyclic_type);
            MPI_Type_commit(&cyclic_type);

            if (i == 0)
            {
                for (j = 0; j < c; j++)
                    local_data[j] = global_data[j * comm_sz];
            }
            else
                MPI_Send(global_data + i, 1, cyclic_type, i, i, comm);

            MPI_Type_free(&cyclic_type);
        }
    }
    else
        MPI_Recv(local_data, local_size_data, MPI_INT, 0, my_rank, comm, MPI_STATUS_IGNORE);
    

    end_time = MPI_Wtime();

    double global_start_time, global_end_time;

    MPI_Reduce(&start_time, &global_start_time, 1, MPI_DOUBLE, MPI_MIN, 0, comm);
    MPI_Reduce(&end_time, &global_end_time, 1, MPI_DOUBLE, MPI_MAX, 0, comm);

    if (my_rank == 0)
    {
        elapsed_time = global_end_time - global_start_time;
        printf("\nPara ir de uma distribuicao statica para ciclica demorou: %.5lfs\n", elapsed_time);
    }

    check_cyclic_distribution(local_data, local_size_data, my_rank, comm_sz);
    MPI_Barrier(comm);
    // juntando para ficar na orden inicial
    start_time = MPI_Wtime();
    if (my_rank == 0)
    {
        MPI_Datatype *recv_types = (MPI_Datatype *)malloc(comm_sz * sizeof(MPI_Datatype));
        if (recv_types == NULL)
            MPI_Abort(comm, 1);
        

        for (i = 0; i < comm_sz; i++)
        {
            int current_rank_local_size = chunk + (i < rest);
            int *blocklengths = (int *)malloc(current_rank_local_size * sizeof(int));
            int *displacements = (int *)malloc(current_rank_local_size * sizeof(int));

            if (blocklengths == NULL || displacements == NULL)
                MPI_Abort(comm, 1);

            for (j = 0; j < current_rank_local_size; j++)
            {
                blocklengths[j] = 1;
                displacements[j] = j * comm_sz + i;
            }

            MPI_Type_indexed(current_rank_local_size, blocklengths, displacements, MPI_INT, &recv_types[i]);
            MPI_Type_commit(&recv_types[i]);

            free(blocklengths);
            free(displacements);
        }

        for (i = 0; i < local_size_data; i++)
        {
            int indice = i * comm_sz;
            global_data[indice] = local_data[i];
        }

        for (i = 1; i < comm_sz; i++)
        {
            MPI_Recv(global_data, 1, recv_types[i], i, i, comm, MPI_STATUS_IGNORE);
            MPI_Type_free(&recv_types[i]);
        }
        MPI_Type_free(&recv_types[0]);
        free(recv_types);
    }
    else
        MPI_Send(local_data, local_size_data, MPI_INT, 0, my_rank, comm);

    // redistribuindo em blocos
    MPI_Scatterv(global_data, send_counts, displs, MPI_INT, local_data, local_size_data, MPI_INT, 0, comm);
    end_time = MPI_Wtime();

    MPI_Reduce(&start_time, &global_start_time, 1, MPI_DOUBLE, MPI_MIN, 0, comm);
    MPI_Reduce(&end_time, &global_end_time, 1, MPI_DOUBLE, MPI_MAX, 0, comm);

    if (my_rank == 0)
    {
        elapsed_time = global_end_time - global_start_time;
        printf("\nPara ir de uma distribuicao ciclica para statica demorou: %.5lfs\n", elapsed_time);
    }

    check_block_distribution(local_data, local_size_data, my_rank, comm_sz, size_data);

    if (my_rank == 0)
    {
        free(global_data);
        free(send_counts);
        free(displs);
    }

    free(local_data);

    MPI_Finalize();
    return 0;
}

void gen_data(int *array, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        array[i] = i;
    }
}

void check_cyclic_distribution(int *local_data, int local_size, int my_rank, int comm_sz)
{
    int local_flag = 0;
    for (int i = 0; i < local_size; i++)
    {
        if (local_data[i] == my_rank + i * comm_sz)
            local_flag = 1;
        else
        {
            local_flag = 0;
            break;
        }
    }

    int global_flag = 0;
    MPI_Reduce(&local_flag, &global_flag, 1, MPI_INT, MPI_SUM, 0, comm);

    if (my_rank == 0)
    {
        if (global_flag == comm_sz)
            printf("Distribuição cíclica correta para todos os processos.\n");
        else
            printf("Erro na distribuição cíclica em algum processo.\n");
    }
}

void check_block_distribution(int *local_data, int local_size, int my_rank, int comm_sz, int size_data)
{
    int rest = size_data % comm_sz;
    int start_index = (size_data / comm_sz) * my_rank + (my_rank < rest ? my_rank : rest);
    int local_flag = 1; 
    for (int i = 0; i < local_size; i++)
    {
        if (local_data[i] != start_index + i)
        {
            local_flag = 0;
            break;
        }
    }

    int global_flag = 0;
    MPI_Reduce(&local_flag, &global_flag, 1, MPI_INT, MPI_SUM, 0, comm);

    if (my_rank == 0)
    {
        if (global_flag == comm_sz)
            printf("Distribuição em bloco correta para todos os processos.\n");
        else
            printf("Erro na distribuição em bloco em algum processo.\n");
    }
}
