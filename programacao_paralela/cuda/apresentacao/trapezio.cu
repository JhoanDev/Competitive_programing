#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <math.h>

__device__ __host__ float f(float x)
{
    return x * x * 4 + x + sqrt(x);
}

__global__ void Dev_trap(
    const float a, /* in */
    const float b, /* in */
    const float h, /* in */
    const int n,   /* in */
    float *trap_p  /* in/out */
)

{
    int my_i = blockDim.x * blockIdx.x + threadIdx.x;

    if (0 < my_i && my_i < n)
    {
        float my_x = a + my_i * h;
        float my_trap = f(my_x);
        atomicAdd(trap_p, my_trap);
    }
} /* Dev_trap */

float Serial_trap(
    const float a, /* in */
    const float b, /* in */
    const int n    /* in */
)
{
    float x, h = (b - a) / n;
    float trap = 0.5 * (f(a) + f(b));

    for (int i = 1; i <= n - 1; i++)
    {
        x = a + i * h;
        trap += f(x);
    }

    trap = trap * h;

    return trap;
} /* Serial_trap */

// Função wrapper que executa no Host (CPU)
void Trap_wrapper(
    const float a,       /* in */
    const float b,       /* in */
    const int n,         /* in */
    float *trap_p,       /* out */
    const int blk_ct,    /* in */
    const int th_per_blk /* in */
)
{
    *trap_p = 0.5 * (f(a) + f(b));
    float h = (b - a) / n;

    Dev_trap<<<blk_ct, th_per_blk>>>(a, b, h, n, trap_p);
    cudaDeviceSynchronize();

    *trap_p = h * (*trap_p);
} /* Trap_wrapper */

int main(int argc, char *argv[])
{
    const float a = 0.0;
    const float b = 10.0;
    const int n = 1024 * 1024 * 950; // 900 milhoẽs de trapézios
    const int blk_ct = 1024 * 950;
    const int th_per_blk = 1024;
    float *trap_p; // Ponteiro para o resultado

    cudaMallocManaged(&trap_p, sizeof(float));
    Trap_wrapper(a, b, n, trap_p, blk_ct, th_per_blk);

    printf("Com n = %d trapézios, a integral de %.2f a %.2f = %.5f\n", n, a, b, *trap_p);
    *trap_p = Serial_trap(a, b, n);
    printf("(Serial) Com n = %d trapézios, a integral de %.2f a %.2f = %.5f\n", n, a, b, *trap_p);
    
    cudaFree(trap_p);
    return 0;
}