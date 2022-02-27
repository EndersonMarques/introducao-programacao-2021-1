#include <stdio.h>
#include <math.h>

// Verdadeiro == 1 e Falso == 0

int eh_primo(int numero)
{

    if (numero <= 1)
    {
        return 0;
    }
    for (int i = 2; i < numero; i++)
    {
        if (numero % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{

    int i, valor1, valor2;
    char numero[9];
    int anterior, posterior;
    for (i = 0; i < 9; i++)
    {
        scanf(" %c", &numero[i]);
    }

    if (numero[1] != '_' || numero[2] != '_')
    {
        printf("Marquinhos esta louco!\n");
        return 0;
    }

    anterior = numero[0] - '0';
    posterior = numero[3] - '0';

    for (i = 1; i < 100; i++)
    {
        valor1 = i / anterior;
        valor2 = i / posterior;

        if (eh_primo(valor1) && eh_primo(valor2))
        {
            // printf("Valor1: %d, Valor2:%d, I: %d\n", valor1, valor2, i);
            numero[1] = (i / 10) + '0';
            numero[2] = (i % 10) + '0';
            for (int j = 0; j < 9; j++)
            {
                printf("%c", numero[j]);
            }
            printf("\n");
        }
    }

    return 0;
}
