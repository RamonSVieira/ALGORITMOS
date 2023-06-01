#include <stdio.h>
#include <time.h>

int primo(long long x)
{
    if (x == 1)
    {
        return 0;
    }

    if (x == 2)
        return 1;

    long long contador = 0;
    for (long long i = 3; i * i <= x; i += 2)
    {
        if (x % i == 0)
        {
            contador++;
        }
    }

    if (contador > 2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    long long n;
    n = 91989664481;
    clock_t inicio, fim;
    inicio = clock();
    int isPrimo = primo(n);
    fim = clock();
    printf("Tempo: %lld milisegundos.\n", (long long)((fim - inicio) * 1000) / CLOCKS_PER_SEC);
    if (isPrimo)
        printf("%d é primo.\n", n);
    else
        printf("%d não é primo.\n", n);
    return 0;
}