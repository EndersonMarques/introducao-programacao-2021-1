#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    int i, j;
    scanf("%d", &n);
    char instrucoes[n + 1][10];
    for (i = 0; i < n + 1; i++)
    {
        gets(instrucoes[i]);
    }

    // Encontrar as palavras chaves
    for (i = 0; i < n + 1; i++)
    {
        if (strncmp(instrucoes[i], "mov", 3) == 0)
        {
            char a = instrucoes[i][4];
            char b = instrucoes[i][7];
            strcpy(instrucoes[i], " ");
            sprintf(instrucoes[i], "%c = %c", a, b);
            printf("%s\n", instrucoes[i]);
        }
        if (strncmp(instrucoes[i], "add", 3) == 0)
        {
            char a = instrucoes[i][4];
            char b = instrucoes[i][7];
            strcpy(instrucoes[i], " ");
            sprintf(instrucoes[i], "%c += %c", a, b);
            printf("%s\n", instrucoes[i]);
        }
        if (strncmp(instrucoes[i], "sub", 3) == 0)
        {
            char a = instrucoes[i][4];
            char b = instrucoes[i][7];
            strcpy(instrucoes[i], " ");
            sprintf(instrucoes[i], "%c -= %c", a, b);
            printf("%s\n", instrucoes[i]);
        }
        if (strncmp(instrucoes[i], "and", 3) == 0)
        {
            char a = instrucoes[i][4];
            char b = instrucoes[i][7];
            strcpy(instrucoes[i], " ");
            sprintf(instrucoes[i], "%c = %c & %c", a, a, b);
            printf("%s\n", instrucoes[i]);
        }
    }
}