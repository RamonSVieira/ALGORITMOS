#include <stdio.h>

int main()
{
  int a = 10, b = 20, c = 30;
  int *ponteiro;
  ponteiro = &b;
  ponteiro = ponteiro + 1;
  *ponteiro = 50;
  printf("a,b,c = %d, %d, %d\n", a, b, c);
  return 0;
}