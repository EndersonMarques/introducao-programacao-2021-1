#include <stdio.h>

int main()
{
    char letra;
    int altura = 0;
    int i, j, aux = 0;

    scanf("%c", &letra);
    altura = (letra)-64;

    aux = altura;
    for (i = 0; i < altura; i++)
    {
        for (j = 0; j < aux - 1; j++)
        {
            printf(".");
        }

        for (j = 65; j < letra - aux + 1; j++)
        {
            printf("%c", j);
        }
        for (j = letra - aux + 1; j >= 65; j--)
        {
            printf("%c", j);
        }

        for (j = 0; j < aux - 1; j++)
        {
            printf(".");
        }
        aux--;
        printf("\n");
    }

    return 0;
}
