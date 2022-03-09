#include <stdio.h>
#include <math.h>

int main()
{
    char texto[501];
    int i, j, k;
    fgets(texto, 501, stdin);
    for (i = 0; texto[i] != '\0'; i++)
    {
        if (texto[i] == '[')
        {
            for (j = i + 1; texto[j] != ']'; j++)
            {
                int numero[3];
                int c = 0;
                while (texto[j] != '-')
                {
                    // printf("%c", texto[j]);
                    numero[c] = texto[j] - '0';
                    c++;
                    j++;
                }
                int valor = 0;
                int temp = c - 1;
                for (k = 0; k < c; k++)
                {
                    valor += numero[k] * pow(10, temp);
                    temp--;
                }
                printf("%c", valor);
            }
            printf("\n");
        }
    }
    return 0;
}