#include <stdio.h>
#include <stdlib.h>

int eh_primo(int numero)
{

    int i;

    if (numero <= 1)
    {
        return 0;
    }

    for (i = 2; i < numero / 2; i++)
    {
        if (numero % i == 0)
        {
            return 0;
        }
    }
    return numero;
}

int existe(int numero, int vetor[], int tamanho)
{
    // int tamanho = sizeof(vetor) / sizeof(int);
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (numero == vetor[i])
        {
            return 1;
        }
    }
    return 0;
}

void limpar_array(int vetor[], int tamanho)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        vetor[i] = 0;
    }
}
int main()
{
    /*
        - N é um nomero inicial
        - K é o numero limite
        - P é a quantidade de primos que N ate K cada ensimo numero deve ter
        - Q é a quantidade de numeros iguais ao ensimo numero com p primos
    */

    int n, k, p = 0;
    int i, j;
    int cont = 0;
    int pos = 0;
    int x = 0, q = 0;

    scanf("%d %d %d", &n, &k, &p);

    int fatores[] = {0};

    if ((n <= 0 || n >= 100000) ||
        (k <= 0 || k >= 100000) ||
        (p <= 0 || p >= 100))
    {
        printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.\n");
        return 0;
    }

    for (i = n; i < k; i++)
    {
        for (j = 2; j < k; j++)
        {
            if (eh_primo(j) && i % j == 0 && j % 2 != 0)
            {
                if (!existe(j, fatores, p))
                {
                    cont++;
                    fatores[pos] = j;
                    pos++;
                }
                else
                {
                    break;
                }
            }
        }
        if (cont == p)
        {
            x = i;
            break;
        }
        else
        {
            cont = 0;
            limpar_array(fatores, p);
            pos = 0;
        }
    }

    // verificando quantos Q tem
    for (i = x + 1; i < k; i++)
    {
        for (j = 2; j < k; j++)
        {
            if (eh_primo(j) && i % j == 0 && j % 2 != 0)
            {
                if (!existe(j, fatores, p))
                {
                    cont++;
                    fatores[pos] = j;
                    pos++;
                }
                break;
            }
        }
        if (cont == p)
        {
            q++;
        }
        else
        {
            cont = 0;
            limpar_array(fatores, p);
            pos = 0;
        }
    }

    if (x == 0 && q == 0)
    {
        printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.\n");
    }
    else
    {
        printf("%d %d\n", x, q);
    }
}
