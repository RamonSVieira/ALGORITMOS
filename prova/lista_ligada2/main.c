#include <stdio.h>
#include <stdlib.h>

struct no
{
  int valor;
  struct no *proximoNo;
};

struct lista
{
  struct no *primeiroNo, *ultimoNo;
};

typedef struct lista *lista;

void print_list(lista lista)
{
  struct no *current = lista->primeiroNo; // Criamos um ponteiro que incialmente aponta para o primeiro nó da lista
  printf("{ ");                           // Abrimos chaves
  while (current != 0)                    // Enquanto o nó for diferente de vazio, printa
  {
    printf("%d ", current->valor); // Printa o valor do nó
    current = current->proximoNo;  // O ponteiro que apontava para o primeiro nó agora aponta para o next, e assim sucessivamente
  }
  printf("}\n"); // fecha chaves
}

void inserirInicio(lista lista, int valor)
{
  struct no *novoNo;
  novoNo = (struct no *)malloc(sizeof(struct no));

  novoNo->valor = valor;
  novoNo->proximoNo = lista->primeiroNo;
  if (lista->primeiroNo == 0)
  {
    lista->ultimoNo = novoNo;
  }

  lista->primeiroNo = novoNo;
}

void inserirFinal(lista lista, int valor)
{
  struct no *novoNo;
  novoNo = (struct no *)malloc(sizeof(struct no));

  novoNo->valor = valor;
  novoNo->proximoNo = 0;
  if (lista->primeiroNo == 0)
  {
    lista->primeiroNo = novoNo;
  }
  else
  {
    lista->ultimoNo->proximoNo = novoNo;
  }
  lista->ultimoNo = novoNo;
}

int removerInicio(lista lista)
{
  if (lista->primeiroNo == 0)
  {
    return -1;
  }

  int valorPrimeiroNo = lista->primeiroNo->valor;

  struct no *noRemovido = lista->primeiroNo;
  if (lista->primeiroNo->proximoNo == 0)
  {
    lista->primeiroNo = 0;
  }
  else
  {
    lista->primeiroNo = noRemovido->proximoNo;
  }

  free(noRemovido);
  return valorPrimeiroNo;
}

int removerFinal(lista lista)
{
  if (lista->primeiroNo == 0)
  {
    return -1;
  }

  int valorUltimoNo = lista->ultimoNo->valor;

  struct no *novoUltimo = lista->primeiroNo;
  while (novoUltimo->proximoNo != 0)
  {
    novoUltimo = novoUltimo->proximoNo;
  }

  novoUltimo->proximoNo = 0;
  free(lista->ultimoNo);
  lista->ultimoNo = novoUltimo;

  return valorUltimoNo;
}

int main()
{
  lista lista01;
  lista01 = (lista)malloc(sizeof(struct lista));
  lista01->primeiroNo = 0;
  lista01->ultimoNo = 0;

  print_list(lista01);
  inserirFinal(lista01, 10);
  inserirFinal(lista01, 10);
  inserirInicio(lista01, 5);
  removerInicio(lista01);
  removerInicio(lista01);
  print_list(lista01);

  return 0;
}