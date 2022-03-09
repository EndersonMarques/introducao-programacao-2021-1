#include <stdio.h>
#include <string.h>

int main()
{
    int tam, SumPar = 0, SumImpar = 0;
    int i, j, k;
    scanf("%d", &tam);

    char matriz[tam][tam][31];
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            scanf("%s", matriz[i][j]);
        }
    }

    // Verificar somatorio
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            if ((i + j) % 2 == 0)
            {
                // Se for par
                for (k = 0; matriz[i][j][k] != '\0'; k++)
                {
                    if (k % 2 == 0)
                    {
                        SumPar += matriz[i][j][k];
                    }
                }
            }
            else
            {
                // Se for impar
                for (k = 0; matriz[i][j][k] != '\0'; k++)
                {
                    if (k % 2 != 0)
                    {
                        SumImpar += matriz[i][j][k];
                    }
                }
            }
        }
    }

    // // printar
    // printf("SumPar: %d \nSumImpar: %d\n", SumPar, SumImpar);
    if (SumPar == SumImpar)
    {
        printf("Tivemos um empate em %d pontos!\n", SumPar);
    }
    else
    {
        if (SumPar > SumImpar)
        {
            printf("Os pares venceram com %d pontos!\n", SumPar);
        }
        else
        {
            printf("Os impares venceram com %d pontos!\n", SumImpar);
        }
    }

    return 0;
}