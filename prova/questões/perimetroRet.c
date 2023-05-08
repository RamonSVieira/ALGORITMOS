#include <stdio.h>

int main()
{
  long long int lado1, lado2;
  scanf("%lld %lld", &lado1, &lado2);

  printf("%lld", (2 * (lado1 + lado2)));
  return 0;
}