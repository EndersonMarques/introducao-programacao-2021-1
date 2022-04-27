#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lerArq(int *n, int *qtdP, char **palavras)
{
    FILE *pArq = NULL;
    char **p = NULL;
    char palavra[11];
    int i, j;

    pArq = fopen("teste.txt", "rt");
    if (pArq == NULL)
    {
        printf("Erro ao abrir o arq\n");
        exit(-1);
    }

    fscanf(pArq, "%d", &(*n));

    // Alocando as linhas
    p = (char **)malloc((*n) * sizeof(char *));
    if (p == NULL)
    {
        printf("Erro ao alocar\n");
        exit(-2);
    }

    // Alocar as colunas
    for (i = 0; i < (*n); i++)
    {
        p[i] = (char *)malloc((*n) * sizeof(char));
        if (p[i] == NULL)
        {
            printf("Erro ao alocar as colunas\n");
            exit(-3);
        }
    }

    for (i = 0; i < (*n); i++)
    {
        for (j = 0; j < (*n); j++)
        {
            fscanf(pArq, " %c", &p[i][j]);
        }
    }

    while (!feof(pArq))
    {

        strcpy(palavra, "");

        fscanf(pArq, " %10s", palavra);

        (*qtdP)++;

        if ((*qtdP) == 1)
        {
            (palavras) = (char *)malloc(sizeof(char *));
        }
        else
        {
            (palavras) = (char *)realloc((*palavras), (*qtdP) * sizeof(char *));
        }

        if ((*palavras) == NULL)
        {
            printf("Erro ao alocar\n");
            exit(-3);
        }

        (*palavras)[(*qtdP) - 1] = malloc(10);

        if ((*palavras)[(*qtdP) - 1] == NULL)
        {
            printf("Erro ao alocar\n");
            exit(-3);
        }

        strcpy((*palavras)[(*qtdP) - 1], palavra);
    }

    fclose(pArq);

    return p;
}

int main()
{
    int n, qtdP = 0;
    ;
    char **matriz = NULL;
    char **palavras = NULL;
    int i, j;

    matriz = lerArq(&n, &qtdP, &palavras);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < qtdP; i++)
    {
        printf("%s\n", palavras[i]);
    }

    for (i = 0; i < n; i++)
    {
        free(matriz[i]);
    }

    for (i = 0; i < n; i++)
    {
        free(palavras[i]);
    }

    free(matriz);
    free(palavras);

    return 0;
}