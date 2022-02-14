#include <stdio.h>
#include <string.h>

int main()
{
    int entrada, metade;
    int i, j;
    scanf("%d", &entrada);
    char strings[] = {0};

    for (i = 0; i < entrada; i++)
    {
        while (scanf("%c", &strings) != EOF)
        {
            puts(strings);
        }
    }
