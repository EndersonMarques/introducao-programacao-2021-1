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