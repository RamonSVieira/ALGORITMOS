#include <stdio.h>

int existeparSoma(int array[], int valorSoma, int tamanhoVetor)
{
    for (int i = 0; i < tamanhoVetor; i++)
    {
        for (int j = i + 1; j < tamanhoVetor; j++)
        {
            if (array[i] + array[j] == valorSoma)
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
    int soma = 10;

    int existeSoma = existeparSoma(vetor, soma, tamanho);

    printf(existeSoma == 1 ? "Existe uma soma entre 2 valores doa array que resultem no valor requerido" : "Nao existe");
    return 0;
}