#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>
#include <pthread.h>

typedef struct {
    float *A, *B, *C;
    int device_id;
    int start_row;
    int rows_per_gpu;
    int N;
} ThreadData;

__global__ void add_matrices(const float *A, const float *B, float *C, int width) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < width && col < width) {
        int idx = row * width + col;
        C[idx] = A[idx] + B[idx];
    }
}

void *gpu_worker(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int N = data->N;

    cudaSetDevice(data->device_id);

    int chunk_size = data->rows_per_gpu * N;
    size_t bytes = chunk_size * sizeof(float);

    float *d_A, *d_B, *d_C;
    cudaMalloc((void **)&d_A, bytes);
    cudaMalloc((void **)&d_B, bytes);
    cudaMalloc((void **)&d_C, bytes);

    cudaMemcpy(d_A, data->A + data->start_row * N, bytes, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, data->B + data->start_row * N, bytes, cudaMemcpyHostToDevice);

    dim3 dimBlock(16, 16);
    dim3 dimGrid((N + 15) / 16, (data->rows_per_gpu + 15) / 16);

    add_matrices<<<dimGrid, dimBlock>>>(d_A, d_B, d_C, N);
    cudaDeviceSynchronize();

    cudaMemcpy(data->C + data->start_row * N, d_C, bytes, cudaMemcpyDeviceToHost);

    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <tamanho_N>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    if (N <= 0) {
        printf("Valor de N inválido.\n");
        return 1;
    }

    int num_gpus;
    cudaGetDeviceCount(&num_gpus);
    if (num_gpus == 0) {
        printf("Nenhuma GPU disponível.\n");
        return 1;
    }

    size_t size = N * N * sizeof(float);
    float *A = (float *)malloc(size);
    float *B = (float *)malloc(size);
    float *C = (float *)malloc(size);

    for (int i = 0; i < N * N; i++) {
        A[i] = 1.0f;
        B[i] = 2.0f;
    }

    pthread_t threads[num_gpus];
    ThreadData thread_data[num_gpus];

    int rows_processed = 0;
    for (int i = 0; i < num_gpus; i++) {
        int start_row = rows_processed;
        int rows_for_this_gpu = N / num_gpus;

        // Último pega o resto se N não for múltiplo de num_gpus
        if (i == num_gpus - 1)
            rows_for_this_gpu = N - start_row;

        thread_data[i] = (ThreadData){
            .A = A,
            .B = B,
            .C = C,
            .device_id = i,
            .start_row = start_row,
            .rows_per_gpu = rows_for_this_gpu,
            .N = N
        };

        pthread_create(&threads[i], NULL, gpu_worker, &thread_data[i]);
        rows_processed += rows_for_this_gpu;
    }

    for (int i = 0; i < num_gpus; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("C[0] = %f\n", C[0]);
    printf("C[N*N-1] = %f\n", C[N * N - 1]);

    free(A);
    free(B);
    free(C);

    return 0;
}
