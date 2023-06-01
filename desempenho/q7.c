#include <stdio.h>
#include <time.h>

int encontrarArray(int array[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == value)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int vetor[] = {1, 0, -7, 2, 3, 4, 5, 67, 9, 1, 2};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int value = 67;

    clock_t inicio, fim;
    inicio = clock();

    int menor = encontrarArray(vetor, tamanho, value);
    fim = clock();
    printf("Tempo: %lld milisegundos.\n", (long long)((fim - inicio) * 1000) / CLOCKS_PER_SEC);
    printf("%d\n", menor);
}