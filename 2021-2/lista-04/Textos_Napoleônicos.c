#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char texto[501], numeroChareado[10];
    int i, j, k, c, l, pos = 0;
    int cMai = 0, cMine = 0;
    fgets(texto, 501, stdin);

    // percorre todo texto
    for (i = 0; texto[i] != '\0'; i++)
    {
        if ((texto[i] != '[' && texto[i] != ']'))
        {
            printf("%c", texto[i]);
        }
        // encontra o primeio [xx-]
        if (texto[i] == '[')
        {
            l = 0;
            // vai ate o final do primero [xx-]]
            for (j = i + 1; texto[j] != ']'; j++)
            {
                i++;
                int numero[3];
                c = 0;
                // econtra o primero numero cha forma ['x', 'x']
                while (texto[j] != '-')
                {
                    i++;
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
                numeroChareado[l] = valor;
                l++;
            }

            // vendo se uqantos maisculos/minucsculos tem e tratando
            for (int a = 0; a < l; a++)
            {
                if (numeroChareado[a] < 97)
                {
                    cMai++;
                }
                else
                {
                    cMine++;
                }
            }
            if (cMai > cMine)
            {
                for (int a = 0; a < l; a++)
                {
                    printf("%c", toupper(numeroChareado[a]));
                }
            }
            else
            {
                for (int a = 0; a < l; a++)
                {
                    printf("%c", tolower(numeroChareado[a]));
                }
            }
            // zerando
            cMine = 0;
            cMai = 0;
            // printf("\n");
            // printf("%d %d\n", cMai, cMine);
            i++;
            // printf("\npos: %d\n", pos);
        }
    }
    return 0;
}