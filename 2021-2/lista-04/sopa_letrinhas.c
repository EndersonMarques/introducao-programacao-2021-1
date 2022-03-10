#include <stdio.h>
#include <string.h>
#define MAX_TAM 30
int main()
{

    char conjunto[MAX_TAM];
    scanf(" %s", conjunto);

    int N, i = 0, j = 0, k = 0;
    int cont = 0;

    scanf("%d", &N);
    char palavras[N][MAX_TAM];

    for (i = 0; i < N; i++)
    {
        scanf(" %s", palavras[i]);
    }

    char conjuntoCopia[MAX_TAM];
    strcpy(conjuntoCopia, conjunto);

    for (i = 0; i < N; i++)
    {

        while (j < strlen(palavras[i]) && k < strlen(conjuntoCopia))
        {

            if (palavras[i][j] == conjuntoCopia[k])
            {

                j++;
                conjuntoCopia[k] = '~';
                k = -1;
            }
            k++;
        }

        if (j == strlen(palavras[i]))
        {

            cont++;
            strcpy(conjunto, conjuntoCopia);
        }
        else
            strcpy(conjuntoCopia, conjunto);

        j = 0;
        k = 0;
    }

    printf("E possivel formar %d palavras com esse conjunto\n", cont);

    return 0;
}