#include <stdio.h>
#include <cuda.h>

__global__ void add(int *a, int *b, int *c, int n) {
    int i = threadIdx.x;
    if (i < n)
        c[i] = a[i] + b[i];
}

int main() {
    const int N = 5;
    int h_a[N] = {1, 2, 3, 4, 5};
    int h_b[N] = {10, 20, 30, 40, 50};
    int h_c[N];

    int *d_a, *d_b, *d_c;
    cudaMalloc((void**)&d_a, N * sizeof(int));
    cudaMalloc((void**)&d_b, N * sizeof(int));
    cudaMalloc((void**)&d_c, N * sizeof(int));

    cudaMemcpy(d_a, h_a, N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, N * sizeof(int), cudaMemcpyHostToDevice);

    add<<<1, N>>>(d_a, d_b, d_c, N);

    cudaMemcpy(h_c, d_c, N * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < N; ++i)
        printf("%d + %d = %d\n", h_a[i], h_b[i], h_c[i]);

    cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);
    return 0;
}
