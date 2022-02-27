#include <stdio.h>

int main()
{

    int n, deslocamento;
    int i;

    // Le o tamanho da string
    scanf("%d", &n);

    // Cria a string e l? ela
    char frase[n];
    int cifra[n];
    for (i = 0; i < n; i++)
    {
        scanf(" %c", &frase[i]);
        // Tranformei em inteiro
        cifra[i] = frase[i];
    }

    // Le o deslocamento
    scanf("%d", &deslocamento);
    if (deslocamento > 26)
        // fazendo o deslocamento virar um looping
        deslocamento %= 26;
    // Somar deslocamento
    for (i = 0; i < n; i++)
    {
        cifra[i] += deslocamento;
        if (cifra[i] > 122)
            cifra[i] -= 26;
    }

    // Printar string
    for (i = 0; i < n; i++)
    {
        printf("%c", cifra[i]);
    }

    return 0;
}