#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <math.h>

#define THREADS_PER_BLOCK 256

__device__ __host__ double f(double x)
{
    return x * x + 4; 
}

__global__ void trap(const double a, const double h, const long long n, const int t, double *val_trap)
{
    int thread_id = blockIdx.x * blockDim.x + threadIdx.x;
    if (thread_id >= t) return;

    long long trap_per_thread = n / t;
    double local_sum = 0.0;
    double start_x = a + thread_id * trap_per_thread * h;

    int start_index = (thread_id == 0) ? 1 : 0;

    for (int i = start_index; i < trap_per_thread; i++)
    {
        double x = start_x + i * h;
        local_sum += f(x);
    }

    atomicAdd(val_trap, local_sum);
}
int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf("Uso correto: %s <qnt_threads> <qnt_trap> <a> <b>\n", argv[0]);
        exit(1);
    }

    int qnt_threads = atoi(argv[1]);
    long long count_trap = atoll(argv[2]);

    if (count_trap % qnt_threads != 0)
    {
        printf("Erro: A quantidade de trapézios (%lld) deve ser divisível pelo número de threads (%d).\n", count_trap, qnt_threads);
        exit(1);
    }

    double a = atof(argv[3]);
    double b = atof(argv[4]);
    double h = (b - a) / count_trap;
    double val = 0.5 * (f(a) + f(b));
    int blocks = (qnt_threads + THREADS_PER_BLOCK - 1) / THREADS_PER_BLOCK;

    double *d_val_trap;
    cudaMalloc((void **)&d_val_trap, sizeof(double));
    cudaMemcpy(d_val_trap, &val, sizeof(double), cudaMemcpyHostToDevice);

    trap<<<blocks, THREADS_PER_BLOCK>>>(a, h, count_trap, qnt_threads, d_val_trap);
    cudaDeviceSynchronize();

    cudaMemcpy(&val, d_val_trap, sizeof(double), cudaMemcpyDeviceToHost);
    cudaFree(d_val_trap);
    val = val * h;
    printf("Resultado da integral: %lf\n", val);

    return 0;
}