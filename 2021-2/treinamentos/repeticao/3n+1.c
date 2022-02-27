#include <stdio.h>

int main()
{

    long long int i, j, x = 0, y = 0, aux;
    long long int maior_current = 0;
    long long int maior = 0;
    int achei = 0;
    int valor = 0;

    // Verifica ate o final de arquivo
    while (scanf("%lld %lld", &i, &j) != EOF)
    {
        // guardando os valores de i e j ordenados
        if (i < j)
        {
            x = i;
            y = j;
        }
        else
        {
            x = j;
            y = i;
        }
        // verificando todos os numeros de i ate j
        for (x; x <= y; x++)
        {
            valor = x;
            achei = 0;

            // enquanto nao achou, ve a regra dos divisores e conta eles
            while (!achei)
            {
                if (valor == 1)
                {
                    achei = 1;
                    maior++;
                }
                else if (valor > 1 && valor % 2 == 0)
                {
                    valor /= 2;
                    maior++;
                }
                else if (valor > 1 && valor % 2 != 0)
                {
                    valor = 3 * valor + 1;
                    ;
                    maior++;
                }
            }
            // verifica qual ? o numero que tem mais divisores e guarda a qtd de divisores dele em uma variavel
            if (maior_current < maior)
            {
                maior_current = maior;
            }
            // zera para o proximo for
            maior = 0;
        }
        // exibe na tela
        printf("%lld %lld %lld\n", i, j, maior_current);
        // zera para o prixomo while
        maior = 0;
        maior_current = 0;
    }

    return 0;
}