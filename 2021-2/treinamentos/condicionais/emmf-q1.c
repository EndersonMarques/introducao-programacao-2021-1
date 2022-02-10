#include <stdio.h>

int main()
{
    int dezena1, dezena2;

    scanf("%d%d", &dezena1, &dezena2);

    int soma, quadrado, d1, d2;

    // Debugger ------------------
    // soma = dezena1 + dezena2;
    // quadrado = soma * soma;
    // d1 = quadrado / 100;
    // d2 = quadrado % 100;
    // printf("%d\n", soma);
    // printf("%d\n", quadrado);
    // printf("%d %d\n", d1, d2);

    if (d1 == dezena1 && d2 == dezena2)
    {
        printf("Satisfaz a propriedade\n");
    }
    else
    {
        printf("Nao Satisfaz a propriedade\n");
    }
}