#include <stdio.h>
#include <cuda.h> 

__global__ void hello_blocks_threads() {
    int global_id = blockIdx.x * blockDim.x + threadIdx.x;
    printf("Hello from thread %d (block %d, thread %d)\n", global_id, blockIdx.x, threadIdx.x);
}

int main() {
    hello_blocks_threads<<<2, 3>>>(); 
    cudaDeviceSynchronize();
    return 0;
}
