#include <stdio.h>

int main()
{
    int n, m;
    int i, j, cont = 0;

    while (scanf("%d %d", &n, &m) != EOF)
    {
        cont++;
        // scanf("%d %d", &n, &m);
        int poliA[n + 1], poliB[m + 1], matriz_conta[n + 1][n + m + 1];
        // Ler o polinomio A
        for (i = 0; i < n + 1; i++)
        {
            scanf("%d", &poliA[i]);
        }
        // Ler o polinomio B
        for (i = 0; i < m + 1; i++)
        {
            scanf("%d", &poliB[i]);
        }
        // zerando matriz
        for (i = 0; i < n + 1; i++)
        {
            for (j = 0; j < n + m + 1; j++)
            {
                matriz_conta[i][j] = 0;
            }
        }
        // Atribuindo e multiplicvando os valores
        for (i = 0; i < n + 1; i++)
        {
            for (j = 0; j < m + 1; j++)
            {
                // printf("%d ", poliA[i] * poliB[j]);
                matriz_conta[i][j + i] = poliA[i] * poliB[j];
            }
            // printf("\n");
        }

        // printando valores
        // for (i = 0; i < n + 1; i++)
        // {
        //     for (j = 0; j < n + m + 1; j++)
        //     {
        //         printf("%3d ", matriz_conta[i][j]);
        //     }
        //     printf("\n");
        // }
        // somando colunas exibindo
        printf("Caso #%d: ", cont);
        for (i = 0; i < m + n + 1; i++)
        {
            int valor = 0;
            for (j = 0; j < n + 1; j++)
            {
                valor += matriz_conta[j][i];
            }
            if (i < n + m)
            {
                printf("%d ", valor);
            }
            else
            {
                printf("%d", valor);
            }
        }
        printf("\n");
    }

    return 0;
}