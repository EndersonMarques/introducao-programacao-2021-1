#include <stdio.h>
#include <string.h>

void troca(char *a, char *b)
{
    char aux = *a;
    *a = *b;
    *b = aux;
}

void procedimento(char *frase)
{
    // Trocar a string toda
    int i;
    for (i = 0; frase[i] != '\0'; i++)
    {
        char vogais[5] = {'a', 'e', 'i', 'o', 'u'};
        if (frase[i] == 'a' || frase[i] == 'i')
        {
            troca(&frase[i], &vogais[4]);
        }
        else if (frase[i] == 'e')
        {
            troca(&frase[i], &vogais[3]);
        }
        else if (frase[i] == 'o')
        {
            troca(&frase[i], &vogais[0]);
        }
        else if (frase[i] == 'u')
        {
            troca(&frase[i], &vogais[1]);
        }
    }

    printf("%s", frase);
}

int main()
{

    char frase[101];
    fgets(frase, 101, stdin);
    fflush(stdin);
    procedimento(frase);
}