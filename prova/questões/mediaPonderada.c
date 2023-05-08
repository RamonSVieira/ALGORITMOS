#include <stdio.h>

int main()
{
  int nota1, nota2;
  scanf("%d %d", &nota1, &nota2);

  int media = (nota1 * 2 + nota2 * 3) / 5;

  printf("%d", media);
  return 0;
}