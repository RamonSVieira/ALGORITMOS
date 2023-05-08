#include <stdio.h>

int main()
{
  int a = 10, b = 20;
  int *pa, *pb;
  pa = &a;
  pb = &b;
  *pa = *pb * 2;
  printf("%d,%d\n", a, b);
  return 0;
}