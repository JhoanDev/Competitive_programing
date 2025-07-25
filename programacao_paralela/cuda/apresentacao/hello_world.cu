#include <stdio.h>
#include <cuda.h> 

__global__ void Hello(void) {
    printf("Hello from thread %d!\n", threadIdx.x);
}

int main(int argc, char* argv[]) {
    int thread_count; 
    thread_count = strtol(argv[1], NULL, 10); 
    Hello<<<1, thread_count>>>();
    cudaDeviceSynchronize(); 
    return 0;
}
