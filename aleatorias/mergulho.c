#include <stdio.h>
#include <stdlib.h>

int main()
{
  int mergulhou, retornou, idVoluntarios, contador = 0;

  scanf("%d %d", &mergulhou, &retornou);

  int *retorno = (int *)calloc(mergulhou + 1, sizeof(int));
  if (retorno == NULL)
  {
    printf("Erro ao alocar memória!\n");
    exit(1);
  }

  for (int i = 0; i < retornou; i++)
  {
    scanf("%d", &idVoluntarios);
    retorno[idVoluntarios] = 1;
  }

  for (int i = 1; i <= mergulhou; i++)
  {
    if (retorno[i] == 0)
    {
      printf("%d ", i);
      contador++;
    }
  }

  if (contador == 0)
  {
    printf("*");
  }
  printf("\n");

  free(retorno);
  return 0;
}