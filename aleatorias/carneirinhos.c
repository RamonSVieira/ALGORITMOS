#include <stdio.h>

int main()
{
  int testes;
  scanf("%d", &testes);
  for (int t = 0; t < testes; t++)
  {
    int n, i, j;
    scanf("%d", &n);
    int carneirinhos[n];
    for (i = 0; i < n; ++i)
    {
      scanf("%d", &carneirinhos[i]);
    }

    int distintos = 0;
    for (i = 0; i < n; ++i)
    {
      int nao_repetido = 1;
      for (j = 0; j < i; ++j)
      {
        if (carneirinhos[j] == carneirinhos[i])
        {
          nao_repetido = 0;
          break;
        }
      }
      if (nao_repetido)
      {
        distintos++;
      }
    }
    printf("%d\n", distintos);
  }
  return 0;
}