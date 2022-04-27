[21:58, 22 / 04 / 2022] + 55 81 8448 - 5060 : #include<stdio.h>
#include <stdlib.h>
#include <string.h>

                                              char **
                                              carregaRegulagensDeFilial(int filial, int *tamVet)
{
    FILE *pArq = NULL;
    char **m = NULL;
    char filialS[20] = "";
    char *linhas = NULL;
    char regulagem[10] = "Pablo";
    char *p = NULL;
    int i;

    for (i = 101; i <= filial; i++)
    {

        itoa(i, filialS, 10);

        strcat(filialS, ".txt");

        printf("%s\n", filialS);

        pArq = fopen(filialS, "rt");
        if (pArq == NULL)
        {
            printf("Erro ao abrir arq\n");
            exit(-1);
        }

        linhas = (char *)malloc(256 * sizeof(char));
        if (linhas == NULL)
        {
            printf("Erro ao alocar\n");
            exit(-2);
        }

        while (fscanf(pArq, " %[^\n]", linhas) != EOF)
        {

            strcpy(regulagem, "");

            p = memchr(linhas, '[', strlen(linhas));

            printf("%s\n", p);

            strncpy(regulagem, p, 9);

            regulagem[9] = '\0';

            (*tamVet)++;

            if ((*tamVet) == 1)
            {
                m = (char **)malloc(sizeof(char *));
            }
            else
            {
                m = (char **)realloc(m, (*tamVet) * sizeof(char *));
            }

            if (m == NULL)
            {
                printf("Erro ao alocar");
                exit(-1);
            }

            m[(*tamVet) - 1] = malloc(10 * sizeof(char));

            if (m[(*tamVet) - 1] == NULL)
            {
                printf("Erro ao alocar");
                exit(-1);
            }

            strcpy(m[(*tamVet) - 1], regulagem);
        }

        free(p);
        free(linhas);
        fclose(pArq);
    }

    return m;
}

int main()
{
    int filial, tam = 0, i;
    char **matrizRegulagens = NULL;

    do
    {
        printf("Entre com o numero da ultima filial: |101 <= F <= 199|\n");
        scanf("%d", &filial);
    } while ((filial < 101) || (filial > 199));

    matrizRegulagens = carregaRegulagensDeFilial(filial, &tam);

    for (i = 0; i < tam; i++)
    {
        printf("%s\n", matrizRegulagens[i]);
    }

    for (i = 0; i < tam; i++)
    {
        free(matrizRegulagens[i]);
    }

    free(matrizRegulagens);

    return 0;
}
[22:40, 22 / 04 / 2022] + 55 81 8448 - 5060 : #include<stdio.h>
#include <stdlib.h>
#include <string.h>

                                              char *
                                              lerArq(int *n, int *qtdP, char **palavras)
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