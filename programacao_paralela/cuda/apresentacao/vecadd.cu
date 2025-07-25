#include <stdio.h>
#include <cuda.h>
#include <stdlib.h>
#include <time.h>

__global__ void Vec_add(
    const float x[], /* in */
    const float y[], /* in */
    float z[],       /* out */
    const int n      /* in */
)
{
    int my_elt = blockDim.x * blockIdx.x + threadIdx.x;

    if (my_elt < n)
    {
        z[my_elt] = x[my_elt] + y[my_elt];
    }
} /* Vec_add */

void Serial_vec_add(
    const float x[], /* in */
    const float y[], /* in */
    float cz[],      /* out */
    const int n      /* in */
)
{
    for (int i = 0; i < n; i++)
    {
        cz[i] = x[i] + y[i];
    }
} /* Serial_vec_add */

void Get_args(
    const int argc,   /* in */
    char *argv[],     /* in */
    int *n_p,         /* out */
    int *blk_ct_p,    /* out */
    int *th_per_blk_p /* out */
)
{
    if (argc != 4)
    {
        fprintf(stderr, "Uso: %s <num_elementos> <num_blocos> <threads_por_bloco>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    *n_p = strtol(argv[1], NULL, 10);
    *blk_ct_p = strtol(argv[2], NULL, 10);
    *th_per_blk_p = strtol(argv[3], NULL, 10);

    if (*n_p > (*blk_ct_p) * (*th_per_blk_p))
    {
        fprintf(stderr, "Erro: num_elementos (%d) maior que total de threads (%d = %d * %d).\n",
                *n_p, (*blk_ct_p) * (*th_per_blk_p), *blk_ct_p, *th_per_blk_p);
        exit(EXIT_FAILURE);
    }
}

void Allocate_vectors(
    float **x_p,  /* out */
    float **y_p,  /* out */
    float **z_p,  /* out */
    float **cz_p, /* out */
    int n         /* in */
)
{
    cudaMallocManaged(x_p, n * sizeof(float));
    cudaMallocManaged(y_p, n * sizeof(float));
    cudaMallocManaged(z_p, n * sizeof(float));

    *cz_p = (float *)malloc(n * sizeof(float));

} /* Allocate_vectors */

double Two_norm_diff(
    const float z[],  /* in */
    const float cz[], /* in */
    const int n       /* in */
)
{
    double diff, sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        diff = z[i] - cz[i];
        sum += diff * diff;
    }

    return sqrt(sum);

} /* Two_norm_diff */

void Free_vectors(
    float *x, /* in/out */
    float *y, /* in/out */
    float *z, /* in/out */
    float *cz /* in/out */
)
{
    cudaFree(x);
    cudaFree(y);
    cudaFree(z);

    free(cz);

} /* Free_vectors */

void Init_vectors(float *x,
                  float *y,
                  const int n /* in */)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        x[i] = (float)((double)rand() / RAND_MAX) * 1000;
        y[i] = (float)((double)rand() / RAND_MAX) * 1000;
    }
}

int main(int argc, char *argv[])
{
    int n, th_per_blk, blk_ct;
    float *x, *y, *z, *cz;
    double diff_norm;

    Get_args(argc, argv, &n, &blk_ct, &th_per_blk);
    Allocate_vectors(&x, &y, &z, &cz, n);
    Init_vectors(x, y, n);

    Vec_add<<<blk_ct, th_per_blk>>>(x, y, z, n);
    cudaDeviceSynchronize();

    Serial_vec_add(x, y, cz, n);
    diff_norm = Two_norm_diff(z, cz, n);
    printf("Norma-2 da diferença entre host e dispositivo = %e\n", diff_norm);

    Free_vectors(x, y, z, cz);
    return 0;
} /* main */