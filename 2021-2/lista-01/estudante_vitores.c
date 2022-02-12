#include <stdio.h>

int main()
{

    int a, b, c;
    int primeiro = 0;

    scanf("%d %d %d", &a, &b, &c);

    // Ordem
    /*
     - Ao quadrado
     - Resto da divisão
     - Multiplicação
     - Divisão
     - Soma
     - Subtração
    */

    // Quadrado
    if ((a * a) == c)
    {
        printf("Quadrado Vitoris\n");
        primeiro++;
    }
    // Resto
    if (a % b == c)
    {
        if (primeiro == 0)
            printf("Resto Vitoris\n");
        else
        {
            printf("tambem Resto\n");
        }
        primeiro++;
    }
    // Multi
    if (a * b == c)
    {
        if (primeiro == 0)
            printf("Multi Vitoris\n");
        else
        {
            printf("tambem Multi\n");
        }
        primeiro++;
    }
    // Div
    if (a / b == c)
    {
        if (primeiro == 0)
            printf("Div Vitoris\n");
        else
        {
            printf("tambem Div\n");
        }
        primeiro++;
    }
    // Soma
    if (a + b == c)
    {
        if (primeiro == 0)
            printf("Soma Vitoris\n");
        else
        {
            printf("tambem Soma\n");
        }
        primeiro++;
    }
    // Sub
    if (a - b == c)
    {
        if (primeiro == 0)
            printf("Sub Vitoris\n");
        else
        {
            printf("tambem Sub\n");
        }
        primeiro++;
    }
    // Impossivel
    if (primeiro == 0)
    {
        printf("Impossivel vitores\n");
    }

    return 0;
}