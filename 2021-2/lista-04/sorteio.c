#include <stdio.h>
#include <string.h>

int main()
{
    int n, m, n1, n2;
    char aux[10];
    int i, j;
    scanf("%d", &n);
    char sorteio_carro[n][10];
    for (i = 0; i < n; i++)
    {
        scanf("%s", sorteio_carro[i]);
    }
    scanf("%d", &m);
    char sorteio_moto[m][10];
    for (i = 0; i < m; i++)
    {
        scanf("%s", sorteio_moto[i]);
    }

    // Lendo n1 e n2
    scanf("%d %d", &n1, &n2);

    // Ordenando o vetor de carro
    for (j = 0; j < n - 1; j++)
    {

        for (i = 0; i < n - 1; i++)
        {
            if (strcmp(sorteio_carro[i], sorteio_carro[i + 1]) > 0)
            {

                strcpy(aux, sorteio_carro[i]);
                strcpy(sorteio_carro[i], sorteio_carro[i + 1]);
                strcpy(sorteio_carro[i + 1], aux);
            }
        }
    }
    // Ordenando o vetor de moto
    for (j = 0; j < m - 1; j++)
    {

        for (i = 0; i < m - 1; i++)
        {
            if (strcmp(sorteio_moto[i], sorteio_moto[i + 1]) > 0)
            {

                strcpy(aux, sorteio_moto[i]);
                strcpy(sorteio_moto[i], sorteio_moto[i + 1]);
                strcpy(sorteio_moto[i + 1], aux);
            }
        }
    }

    // Verificando se � igual ou diferente
    if (strcmp(sorteio_carro[n1 - 1], sorteio_moto[n2 - 1]) == 0)
    {
        printf("Quem ganhou tudo hoje foi %s\n", sorteio_carro[n1 - 1]);
    }
    else
    {
        printf("Quem ganhou o carro foi: %s\n", sorteio_carro[n1 - 1]);
        printf("Quem ganhou a moto foi: %s\n", sorteio_moto[n2 - 1]);
    }
}