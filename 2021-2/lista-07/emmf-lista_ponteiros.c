// emmf - Enderson Marques de Matos Filho

// Questao 1
#include <stdio.h>

int main()
{

    char c = 'a';
    char *pc;
    pc = &c;

    // Letra A)
    printf("Leta A): %p %c\n", &c, c);

    // Letra B)
    printf("Leta B): %c %p\n", *pc, pc);

    // Letra C)
    printf("Leta C): %p\n", &pc);

    // Letra D)
    printf("Leta D): %p %p\n", &(*pc), *(&pc));

    // Letra E)
    /* Os dois endereços são iguais por que, primeiramente o operador '&'
        retorna o endereço de agluma variavel. E quando fazemos '*pc', estamos pedindo
        para que seja mostrado o valor que está armazenado na variavel que o ponteiro esta
        apontando, logo2 se eu faço 'char c = a;', 'char *pc = &c;' e peço para que seja
        printado '*pc', é o mesmo que epdir que seja printado apenas 'c'. Então, quando o
        enunciado pede o '*Endereço do valor guarado*', logo deve-se usar o operador de
        'Endereço, &' do 'Valor guarado, (*pc)', ou seja '&(*pc)'.

        E logo em seguida, quando o enunciado pede o 'Valor Guardado no ENDEREÇO de pc',
        deve-se usar na ordem pedida, o 'VALOR, *(Algum_Ponteiro)' gurdado no'ENDEREÇO, &'
        de pc, ou seja, é pedido que seja feito '*(&pc)'.

        Mas e porque eles são iguais ?,  Simples !!! Eles são iguais pelo simples fato de
        que o VALOR GUARDADO no endereço de pc é o propio Endereço que pc guarda, logo
        *(&pc) é == (igual) pc, que por suas vez também é igual a (&c). E também, porque
        o ENDEREÇO DO VALOR guardado no ENDEREÇO apontando por pc é extamente igual a
        o endereço de c, logo (&c),  que é justamente o endereço que pc guarda !!!
        Sendo assim, as duas formas esntão printando o endereço de c, '&c', ou printando
        o propio pc(Que guarda o enreço de c, '&c')

        logo eles são iguais :D
    */

    return 0;
}

// Questao 2
#include <stdio.h>

int main()
{
    int vet[5] = {1, 2, 3, 4, 5};
    int *p = vet;
    int i;

    // Letra A)
    printf("Letra A): %p %p\n", p, &vet);

    // Letra B)
    printf("Letra B): ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");

    // Letra C)
    printf("Letra C): ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n");

    // Letra D)
    printf("Letra D.1 Usando vet[]: ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");

    printf("Letra D.2 Usando *(vet): ");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", *(vet + i));
    }
    printf("\n");
    return 0;
}

// Questao 3
#include <stdio.h>
#include <string.h>
int main()
{
    char str[50];     // String
    char str_inv[50]; // String invertida
    char *ptr_str = str;
    char *ptr_inv = str_inv;
    int i = -1;
    scanf("%s", str);
    // [...]

    while (*(ptr_str) != '\0')
    {
        ptr_str++;
        i--;
    }
    while (i)
    {
        *(ptr_inv) = *(ptr_str - 1);
        ptr_str--;
        ptr_inv++;
        i++;
    }

    printf(" O inverso da string : %s\n\n", str_inv);
    return 0;
}

/* Letra B - Não é necessário o '&' no scanf de uma string e de
    nenhum vetor, porque o nome de um vetor qualquer, já é um
    ponteiro para a primeira posição do mesmo vetor !!!
*/

// Questao 4
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char palavra[50];
    int c, tam, j, i, interador = 1;

    char **aux = (char **)malloc(sizeof(char *));
    aux[0] = (char *)malloc(sizeof(char));

    if (aux[0] == NULL)
    {
        printf("Erro\n");
        free(aux[0]);
        free(aux);
        return 0;
    }

    c = 0;
    j = 0;
    while (scanf(" %s", palavra) != EOF)
    {
        tam = strlen(palavra);
        aux = (char **)realloc(aux, (c + 1) * sizeof(char *));
        aux[j] = (char *)realloc(aux[j], tam * sizeof(char));
        if (aux[j] == NULL)
        {
            printf("Erro ao Realocar\n");
            for (i = j; i <= 0; i--)
            {
                free(aux[i]);
            }
            free(aux);
            return 0;
        }
        strcpy(aux[j], palavra);
        c++;
        j++;
    }

    while (c)
    {
        printf("Plavra na posicao %d = %s\n", interador, aux[interador - 1]);
        free(aux[interador - 1]);
        c--;
        interador++;
    }
    free(aux);

    return 0;
}

// Questao 5
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