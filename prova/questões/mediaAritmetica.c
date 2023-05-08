#include <stdio.h>

int main()
{
  double x, y, media;
  scanf("%lf %lf", &x, &y);

  media = (x + y) / 2.0;

  printf("%.5lf", media);

  return 0;
}