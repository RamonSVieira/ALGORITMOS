#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do array dinâmico
struct array_list
{
  int *data;             // Ponteiro para o array
  unsigned int size;     // Quantidade de elementos atualmente armazenados no array
  unsigned int capacity; // Quantidade de elementos que o array pode armazenar sem realocação
};

// Função para aumentar a capacidade do array em 10 elementos
void array_list_increase_capacity(struct array_list *list)
{
  // Aloca um novo array com capacidade maior
  int *new_data = (int *)malloc(sizeof(int) * (list->capacity + 10));

  // Copia os elementos do array original para o novo array
  for (int i = 0; i < list->capacity; ++i)
  {
    new_data[i] = list->data[i];
  }

  // Libera a memória alocada para o array original
  free(list->data);

  // Atualiza o ponteiro do array para apontar para o novo array
  list->data = new_data;

  // Atualiza a capacidade do array
  list->capacity = list->capacity + 10;
}

// Para o append, saber o tamanho vai ser a chave, visto que o último elemento deve ser adicionado no último index
void array_list_append(struct array_list *list, int value)
{
  // Verifica se a lista está cheia e aumenta a capacidade caso necessário
  if (list->size == list->capacity)
  {
    array_list_increase_capacity(list);
    // Adiciona o valor no final da lista e incrementa o tamanho
    list->data[list->size++] = value;
  }
  else
  {
    // Adiciona o valor no final da lista e incrementa o tamanho
    list->data[list->size++] = value;
  }
}

// Função para criar um novo array com capacidade inicial de 10 elementos
struct array_list *array_list_create()
{
  // Aloca memória para a estrutura do array
  struct array_list *new_list;
  new_list = (struct array_list *)malloc(sizeof(struct array_list));

  // Verifica se a alocação de memória foi bem-sucedida
  if (new_list == 0)
  {
    fprintf(stderr, "Error on memory allocation.\n");
    exit(-1);
  }

  // Define a capacidade inicial do array como 10
  new_list->capacity = 10;

  // Inicializa a quantidade de elementos do array como 0
  new_list->size = 0;

  // Aloca memória para o array com capacidade inicial de 10 elementos
  new_list->data = (int *)malloc(sizeof(int) * new_list->capacity);

  // Verifica se a alocação de memória foi bem-sucedida
  if (new_list->data == 0)
  {
    fprintf(stderr, "Error on memory allocation.\n");
    exit(-1);
  }

  // Retorna o ponteiro para a estrutura do array
  return new_list;
}

// Função para ler inteiros a partir da entrada padrão até que seja lido o valor "end_reading"
void array_list_read_until(struct array_list *list, int end_reading)
{
  int x;

  // Lê inteiros da entrada padrão até que seja lido o valor "end_reading"
  while (scanf("%d", &x), x != end_reading)
  {
    // Se a quantidade de elementos do array é igual à sua capacidade, aumenta a capacidade em 10 elementos
    if (list->size == list->capacity)
      array_list_increase_capacity(list);

    // Adiciona o inteiro lido ao final do array
    list->data[list->size++] = x;
  }
}

void array_list_print(struct array_list *list) // recebe um ponteiro para uma estrutura array_list como parâmetro.
{
  // inicia a impressão na tela da string [.
  printf("[");
  // Verifica se o tamanho da lista é maior que zero e se for, imprime o primeiro elemento da lista.
  if (list->size > 0)
  {
    // Printa o primeiro elemento da lista
    printf("%d", list->data[0]);
    // A partir do segundo elemento da lista, percorre-a com um laço for e imprime os elementos separados por vírgula e um espaço.
    for (int i = 1; i < list->size; ++i)
      printf(", %d", list->data[i]);
  }
  // finaliza
  printf("]");
}

int main()
{
  struct array_list *list01 = array_list_create(); // Criando o array
  printf("Digite os elementos da lista e ao final o -1 para parar\n");
  array_list_read_until(list01, -1);
  array_list_print(list01);
  printf("\n");
  printf("Digite um novo valor a ser adicionado na lista\n");
  int x;
  scanf("%d", &x);
  array_list_append(list01, x);
  array_list_print(list01);
  printf("\n");
  free(list01->data);
  free(list01);
  return 0;
}