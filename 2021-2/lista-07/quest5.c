#include <stdio.h>
#include <stdlib.h>

typedef struct el_list
{
    int valor;
    struct el_list *proximo;
} No;

int main()
{
    // Comecando
    int num;
    No *Lista, *aux, *atual;
    // Lista aponta pra null
    Lista = NULL;
    scanf("%d", &num);
    while (num != 0)
    {
        atual = (No *)malloc(sizeof(No));
        atual->valor = num;

        // Se for o primeiro
        if (Lista == NULL)
        {
            aux = atual;
            Lista = aux;
        }
        else
        {
            aux->proximo = atual;
            aux = atual;
        }
        scanf("%d", &num);
    }

    // Printando
    aux->proximo = NULL;
    aux = Lista;
    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->proximo;
    }

    // Liberando
    free(Lista);
    return 0;
}