#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int maior_potencia_2(int n)
{
    if (n < 1)
        return 0;

    int pot = 1;
    while (pot <= n)
    {
        pot *= 2;
    }
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

void bitonic_sort_seq(int *arr, int n)
{
    int stage, bf_size, i;
    int indice_parceiro;

    for (bf_size = 2; bf_size <= n; bf_size *= 2)
    {
        for (stage = bf_size / 2; stage > 0; stage /= 2)
        {
            for (i = 0; i < n; i++)
            {
                indice_parceiro = i ^ stage;

                if (indice_parceiro > i)
                {
                    // A condição para a troca:
                    // 1. (i & bf_size) == 0: a direção desejada é CRESCENTE.
                    //    Troca se arr[i] > arr[indice_parceiro].
                    // 2. (i & bf_size) != 0: a direção desejada é DECRESCENTE.
                    //    Troca se arr[i] < arr[indice_parceiro].
                    
                    if (((i & bf_size) == 0 && arr[i] > arr[indice_parceiro]) ||
                        ((i & bf_size) != 0 && arr[i] < arr[indice_parceiro]))
                    {
                        int temp = arr[i];
                        arr[i] = arr[indice_parceiro];
                        arr[indice_parceiro] = temp;
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Uso: %s <tamanho_array>\n", argv[0]);
        return 1;
    }

    int entrada_n = atoi(argv[1]);
    if (entrada_n <= 0) {
        printf("Erro: o tamanho do array deve ser um inteiro positivo.\n");
        return 1;
    }

    srand(time(NULL));

    int tamanho_real;
    int *array = gerar_array(entrada_n, &tamanho_real);

    printf("\nArray original:\n");
    imprimir_array(array, tamanho_real);

    printf("\nIniciando ordenação com Bitonic Sort sequencial...\n");
    bitonic_sort_seq(array, tamanho_real);

    printf("\nArray ordenado:\n");
    imprimir_array(array, tamanho_real);

    free(array);
    return 0;
}
