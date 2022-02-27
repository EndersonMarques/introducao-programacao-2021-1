#include <stdio.h>
#include <string.h>

// clear && gcc bonxai.c && ./a.out < entrada

int eh_primo(int valor)
{
    int i;
    for (i = 2; i < valor; i++)
    {
        if (valor % i == 0)
            return 0;
    }
    return 1;
}

int tres_primos_diferentes(int valor)
{
    int i, cont = 0;
    for (i = 2; i < valor; i++)
    {
        if (eh_primo(i) && valor % i == 0)
        {
            cont++;
            if (cont == 3)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{

    char palavra[100];
    int tentativa = 0, qtd_tentativa = 0, total = 0, tam, aux = 0;
    int i;

    scanf("%s", palavra);

    tam = strlen(palavra);
    for (i = 0; i < tam; i++)
    {
        total = total + (palavra[i]);
    }

    if (total % 17 == 0)
    {
        printf("Agora estou Putin, Bonxai!\n");
        return 0;
    }

    while (scanf("%d", &aux) != EOF)
    {
        qtd_tentativa++;
        if (qtd_tentativa > 6)
        {
            break;
        }
        tentativa = tentativa + aux;
    }
    // printf("\nTotal:%d\n", total);

    if (qtd_tentativa > 6 || tentativa < total)
    {
        printf("Bonxai foi de base.\n");
        return 0;
    }
    else
    {
        if (tres_primos_diferentes(total))
        {
            total = total * 3;
        }
        // printf("caiu aqui\n");
        // printf("Tentativa: %d || Total: %d\n", tentativa, total);
        if (tentativa > total)
        {
            printf("Agora voce passou dos limites!\n");
        }
        else if (tentativa == total)
        {
            printf("Parabueins! Voce ajudou Bonxai a escapar.\n");
        }
    }
}