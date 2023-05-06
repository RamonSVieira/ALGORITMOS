#include <stdio.h>
#include <stdlib.h>

// Estrutura do nosso nó, que armazena um valor e um ponteiro para o próximo nó
struct ll_int_node
{
  int value;                // Valor do nosso elemento
  struct ll_int_node *next; // Ponteiro para o próximo elemento
};

// Estrutura que representa a lista, armazenando dois ponteiros, first(que aponta para o primeiro nó da lista) e last(que aponta para o ultimo nó da lista)
struct ll_int
{
  struct ll_int_node *first, *last
};

// Definiçõa de um tipo de dados "ll_int" que é um ponteiro para a estrutura "ll_int"
typedef struct ll_int *ll_int;

// FUNÇÃO PARA PRINTAR A NOSSA LISTA
//  Essa função recebe uma lista como parâmetro
void print_list(ll_int lista)
{
  struct ll_int_node *current = lista->first; // Criamos um ponteiro que incialmente aponta para o primeiro nó da lista
  printf("{ ");                               // Abrimos chaves
  while (current != 0)                        // Enquanto o nó for diferente de vazio, printa
  {
    printf("%d ", current->value); // Printa o valor do nó
    current = current->next;       // O ponteiro que apontava para o primeiro nó agora aponta para o next, e assim sucessivamente
  }
  printf("}\n"); // fecha chaves
}

// FUNÇÃO PARA INSERIR NO INÍCIO DA LISTA
// Essa função recebe um valor, e uma lista a ser atribuída esse valor
void insert_beginning(ll_int lista, int value)
{
  struct ll_int_node *new_node;                                        // Cria o nosso novo nó
  new_node = (struct ll_int_node *)malloc(sizeof(struct ll_int_node)); // Aloca dinamicamente memória para o novo nó e retorna um ponteiro para ele.
  if (new_node)                                                        // Verifica se a alocação de memória foi bem sucedida
  {
    new_node->value = value;       // Armazena o valor no nó novo nó da lista
    new_node->next = lista->first; // Ponteiro do novo nó aponta para o primeiro nó da lista

    if (lista->first == 0) // Verifica se a lista era vazia
    {
      lista->last = new_node; // Se a lista estava vazia, logo o nosso novo nó tanto é o primeiro quanto é o ultimo nó da lista
      lista->first = new_node;
    }
    else
    {
      lista->first = new_node; // Se a lista não era vazia, precisamos apenas atualizar quem é o primeiro nó da lista
    }
  }
  else
  {
    printf("Erro ao alocar memória!\n"); // Se a alocação de memória deu erro retorna o erro
  }
}

// FUNÇÃO PARA REMOVER UM NÓ DO FIM DA LISTA
// Essa função recebe como parâmetro uma lista
int remove_last(ll_int lista)
{
  if (lista->first == 0) // Verifica se a lista é vazia
  {
    return -1; // Se for vazia retorna -1
  }

  int ultimoValor = lista->last->value;        // Atribuia a ultimoValor o valor do ultimo nó da lista
  struct ll_int_node *new_last = lista->first; // Cria um ponteira que aponta para o primeiro nó da lista
  while (new_last->next != lista->last)        // Enquanto o proximo deste ponteiro for diferente do ultimo nó da lista
  {
    new_last = new_last->next; // Passe para o próximo nó
  }
  // Quando sai do while, significa que em new_last nos temos a referencia do antepenulimto nó da lista

  new_last->next = 0;     // Então nso atribuuimos o proximo do antepenultimo como 0
  free(lista->last);      // Liberamos a memória do antigo ultimo elemento da lista
  lista->last = new_last; // Atribuimos o antepenultimo como ultimo elemento da lista
  return ultimoValor;     // Retornamos o valor excluido
}

int main()
{
  int i;                                          // Declara variável i
  ll_int lista1;                                  // Declara variável do tipo ll_int
  lista1 = (ll_int)malloc(sizeof(struct ll_int)); // Aloca dinamicamente memória para a lista encadeada e armazena o ponteiro resultante em lista1.
  lista1->first = 0;                              // Ponteiro first de lista1 é inicializado com 0
  lista1->last = 0;                               // Ponteiro last de lista1 é inicializado com 0
  print_list(lista1);
  insert_beginning(lista1, 16);
  insert_beginning(lista1, 15);
  insert_beginning(lista1, 14);
  insert_beginning(lista1, 13);
  insert_beginning(lista1, 12);
  insert_beginning(lista1, 11);
  insert_beginning(lista1, 10);
  remove_last(lista1);
  print_list(lista1);
  return 0;
}