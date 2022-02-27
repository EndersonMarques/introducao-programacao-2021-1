#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    int dado;
    struct node* next;
    int cont;
}node;

node* add(node* head, int dado)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->dado = dado;
    new_node->next = head;
    new_node->cont = 0;
    
    return new_node;
}

void compara(node* head, int texto)
{
    while(head != NULL)
    {
        if(head->dado == texto)
        {
            head->cont++;
        }
        head = head->next;
    }
}
void print(node* head)
{
    while(head != NULL)
    {
        if(head->cont != 0) printf("%c %d\n", head->dado, head->cont);
        head= head->next;
    }
}

int main() {
    
    node* head = NULL;
    
    for(int i = 0; i<256; i++)
    {
        head = add(head, i);
    }
    
    char texto, aux;
    
    while(scanf("%c", &texto) != EOF)
    {
        texto = (int)texto;
        compara(head, texto);
    }
    print(head);
    
    
    
	return 0;
}