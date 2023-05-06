#include <stdio.h>

int main()
{
  int n, d, l, r, c;
  int grid[11][11] = {0}; // Inicializa o grid com zeros

  scanf("%d", &n);

  // Lê as posições dos navios e marca no grid
  for (int i = 0; i < n; i++)
  {
    scanf("%d %d %d %d", &d, &l, &r, &c);

    // Verifica se o navio está dentro do tabuleiro
    if ((d == 0 && c + l - 1 > 10) || (d == 1 && r + l - 1 > 10))
    {
      printf("N\n"); // Navio fora do tabuleiro
      return 0;
    }

    // Verifica se o navio colide com outro navio
    for (int j = 0; j < l; j++)
    {
      if (d == 0 && grid[r][c + j] == 1)
      {
        printf("N\n"); // Colisão com outro navio
        return 0;
      }
      else if (d == 1 && grid[r + j][c] == 1)
      {
        printf("N\n"); // Colisão com outro navio
        return 0;
      }
    }

    // Marca as posições do navio no grid
    for (int j = 0; j < l; j++)
    {
      if (d == 0)
        grid[r][c + j] = 1;
      else
        grid[r + j][c] = 1;
    }
  }

  printf("Y\n"); // Posicionamento válido

  return 0;
}