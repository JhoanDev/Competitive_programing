#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <cuda_runtime.h>
#include <cuda.h>

#define THREADS_PER_BLOCK 256

int verificar_ordenacao(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

int maior_potencia_2(int n)
{
    if (n < 1)
        return 0;
    int pot = 1;
    while (pot <= n)
        pot *= 2;
    return pot;
}

int *gerar_array(int n, int *tamanho_total)
{
    int pot = maior_potencia_2(n);

    if (pot < n)
        pot <<= 1;

    if (tamanho_total != NULL)
        *tamanho_total = pot;

    int *arr = (int *)malloc(pot * sizeof(int));
    if (arr == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (INT_MAX / 10000000);
    }

    for (int i = n; i < pot; i++)
    {
        arr[i] = INT_MAX;
    }

    return arr;
}

void imprimir_array(int *arr, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (arr[i] == INT_MAX)
            printf("INF ");
        else
            printf("%d ", arr[i]);
    }
    printf("\n");
}

__global__ void bitonic_sort(int *arr, int stage, int bf_size)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int indice_parceiro = i ^ stage;
    if (indice_parceiro > i)
    {
        if (((i & bf_size) == 0 && arr[i] > arr[indice_parceiro]) ||
            ((i & bf_size) != 0 && arr[i] < arr[indice_parceiro]))
        {
            int temp = arr[i];
            arr[i] = arr[indice_parceiro];
            arr[indice_parceiro] = temp;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Uso: %s <tamanho_array>\n", argv[0]);
        exit(1);
    }

    int entrada_n = atoi(argv[1]);
    if (entrada_n <= 0)
    {
        printf("Erro: o tamanho do array deve ser um inteiro positivo.\n");
        exit(1);
    }

    srand(time(NULL));
    int tamanho_real;
    int *array = gerar_array(entrada_n, &tamanho_real);

    if (tamanho_real <= 32)
    {
        printf("Array original: ");
        imprimir_array(array, tamanho_real);
    }
    else
    {
        printf("Array gerado com tamanho %d (oculto por ser grande).\n", tamanho_real);
    }

    int *gpu_array;
    size_t tamanho_bytes = tamanho_real * sizeof(int);

    cudaMalloc((void **)&gpu_array, tamanho_bytes);
    cudaMemcpy(gpu_array, array, tamanho_bytes, cudaMemcpyHostToDevice);

    int blocksPerGrid = (tamanho_real + THREADS_PER_BLOCK - 1) / THREADS_PER_BLOCK;

    printf("Iniciando ordenação com Bitonic Sort em CUDA\tThreads por bloco: %d\tGrid de blocos: %d\n",
           THREADS_PER_BLOCK, blocksPerGrid);

    for (int bf_size = 2; bf_size <= tamanho_real; bf_size *= 2)
    {
        for (int stage = bf_size / 2; stage > 0; stage /= 2)
        {
            bitonic_sort<<<blocksPerGrid, THREADS_PER_BLOCK>>>(gpu_array, stage, bf_size);
        }
    }

    cudaMemcpy(array, gpu_array, tamanho_bytes, cudaMemcpyDeviceToHost);
    if (tamanho_real <= 32)
    {
        printf("Array ordenado: ");
        imprimir_array(array, tamanho_real);
    }
    int ordenado = verificar_ordenacao(array, tamanho_real);
    if (ordenado)
        printf("O array está corretamente ordenado.\n");
    else
        printf("Erro: o array não está ordenado corretamente.\n");
    free(array);
    cudaFree(gpu_array);
    return 0;
}