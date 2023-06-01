#include <stdio.h>
#include <time.h>

int menorArray(int array[], int n)
{
    int menor = array[0];

    for (int i = 1; i < n; i++)
    {
        if (array[i] < menor)
        {
            menor = array[i];
        }
    }
    return n;
}

int main()
{
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    clock_t inicio, fim;
    inicio = clock();

    int menor = menorArray(vetor, tamanho);
    fim = clock();
    printf("Tempo: %lld milisegundos.\n", (long long)((fim - inicio) * 1000) / CLOCKS_PER_SEC);
    printf("%d\n", menor);
    printf("%d\n", menor);
}