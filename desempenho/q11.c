#include <stdio.h>

int existeParSoma(int array[], int tamanho, int soma)
{
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = i + 1; j < tamanho; j++)
        {
            if (array[i] + array[j] == soma)
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int vetor[] = {0, 1, 2, 3, 4, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int soma = 11;

    int parEncontrado = existeParSoma(vetor, tamanho, soma);
    if (parEncontrado)
    {
        printf("Existe um par no array cuja soma é igual a %d.\n", soma);
    }
    else
    {
        printf("Não existe um par no array cuja soma é igual a %d.\n", soma);
    }

    return 0;
}