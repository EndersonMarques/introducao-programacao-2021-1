#include <stdio.h>

int main()
{

    int n, x, cont = 0, pos;
    int i, j;
    while (scanf("%d", &n) != -1)
    {
        if (n == -1)
            break;
        //  scanf("%d%d", &n, &x);
        scanf("%d", &x);
        int vetor[n], vetor_ordenado[n];
        for (i = 0; i < n; i++)
        {
            scanf("%d", &vetor[i]);
            if (vetor[i] == -1)
                break;
            vetor_ordenado[i] = vetor[i];
        }

        // bouble sorte
        for (j = 0; j < n - 1; j++)
        {
            for (i = 0; i < n - 1; i++)
            {
                if (vetor_ordenado[i] > vetor_ordenado[i + 1])
                {
                    int aux = vetor_ordenado[i];
                    vetor_ordenado[i] = vetor_ordenado[i + 1];
                    vetor_ordenado[i + 1] = aux;
                }
            }
        }

        // Comparar os mudolos
        for (i = 0; i < n; i++)
        {
            int temp = vetor_ordenado[i] - vetor[i];
            if (temp < 0)
                temp = -temp;

            // printf("p%i: %d - %d = %d\n", i, vetor_ordenado[i], vetor[i], temp); //Apenas debug
            if (temp == x)
            {
                cont++;
            }
        }

        // Printando Contx
        printf("%d\n", cont);
        for (i = 0; i < n; i++)
        {
            int temp = vetor_ordenado[i] - vetor[i];
            if (temp < 0)
                temp = -temp;
            if (temp == x)
            {
                printf("%d %d %d\n", vetor[i], vetor_ordenado[i], i + 1);
            }
        }
        // Reiniciando as variavies
        cont = 0;
    }
    return 0;
}