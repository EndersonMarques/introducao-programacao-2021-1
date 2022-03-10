#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char texto[501], numeroChareado[4] = {0};
    int i, j, k;
    int cMai = 0, cMine = 0;
    fgets(texto, 501, stdin);

    // percorre todo texto
    for (i = 0; texto[i] != '\0'; i++)
    {
        // encontra o primeio [xx-]
        if (texto[i] == '[')
        {
            // vai ate o final do primero [xx-]]
            for (j = i + 1; texto[j] != ']'; j++)
            {
                int numero[3];
                int c = 0;
                // econtra o primero numero cha forma ['x', 'x']
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
                // printf("%c", valor);
                // Adcionando ao vetor novamento
                int l = 0;
                numeroChareado[l] = valor;
                l++;

                // Verificando quantos maisuclos / minusculos existem e tratando
                for (int m = 0; m < l; m++)
                {
                    // printf("%c", numeroChareado[m]);
                    if (numeroChareado[m] < 97)
                    {
                        // printf("Contou maisuculo : %c\n", numeroChareado[m]);
                        cMai++;
                    }
                    else
                    {
                        // printf("Contou minuscuo : %c\n", numeroChareado[m]);
                        cMine++;
                    }
                    for (int a = 0; a < l; a++)
                    {
                        printf("%c", numeroChareado[a]);
                    }
                }
            }
            // printf("\n");
            printf("%d %d\n", cMai, cMine);
            // zerando
            cMine = 0;
            cMai = 0;
        }
        // if ((texto[i] != '[' && texto[i] != ']' && texto[i] != '-') && !(texto[i] >= 48 && texto[i] <= 59))
        // {
        //     printf("%c", texto[i]);
        // }
    }
    return 0;
}