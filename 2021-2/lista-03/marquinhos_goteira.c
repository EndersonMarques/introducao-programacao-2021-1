#include <stdio.h>
int main()
{
    int linhas, colunas;
    int i, j;
    scanf("%d %d", &linhas, &colunas);
    char matriz[linhas][colunas];

    // Lendo matriz
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            scanf(" %c", &matriz[i][j]);
        }
    }

    // Atribuição
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            if (matriz[i][j] == 'o')
            {
                if (matriz[i + 1][j] == '.')
                {
                    matriz[i + 1][j] = 'o';
                }
                if (matriz[i + 1][j] == '#')
                {
                    if (j + 1 < colunas)
                    {
                        matriz[i][j + 1] = 'o';
                    }
                    if (j - 1 >= 0 && matriz[i][j - 1] == '.')
                    {
                        matriz[i][j - 1] = 'o';
                        j -= 2;
                    }
                }
            }
            else if (matriz[i][j] == '.' && matriz[i - 1][j] == 'o')
            {
                matriz[i][j] = 'o';
            }
        }
    }

    // Printando
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}