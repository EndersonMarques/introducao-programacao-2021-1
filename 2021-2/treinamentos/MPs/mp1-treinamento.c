#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    int valor;
    int i, j, k;
    scanf("%d", &n);
    char matriz[n][n][31];
    int tam = 0;
    char senha[100] = "";
    // in tam[100][100];

    // Lendo
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%s", matriz[i][j]);
            // tam
            // fgets(matriz[i][j], 30, stdin);
        }
    }

    // verificando condições
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            valor = 0;
            // Se estiver na diagonal princial
            if (i == j)
            {
                if (!(matriz[i][j][k] == 'a' || matriz[i][j][k] == 'e' ||
                      matriz[i][j][k] == 'i' || matriz[i][j][k] == 'o' ||
                      matriz[i][j][k] == 'u'))
                {
                    // matriz[i][j][k] = tolower(matriz[i][j][k]);
                    tam = strlen(matriz[i][j]);
                    for (k = 0; k < tam; k++)
                    {
                        matriz[i][j][k] = tolower(matriz[i][j][k]);
                    }
                }
                strcat(senha, matriz[i][j]);
            }
            // Se tiver fora diagonal
            else
            {
                tam = strlen(matriz[i][j]);
                for (k = 0; k < tam; k++)
                {
                    valor += matriz[i][j][k];
                }
                char valor_char[5];
                sprintf(valor_char, "%d", valor);
                strcat(senha, valor_char);
            }
        }
    }

    // printando
    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j < n; j++)
    //     {
    //         // printf("i: %d || j:%d", i, j);
    //         printf("%s ", matriz[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%s\n", senha);

    return 0;
}