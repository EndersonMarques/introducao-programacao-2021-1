#include <stdio.h>

int main()
{
    int hora, minuto;

    scanf("%d:%d", &hora, &minuto);

    if (hora < 12)
    {
        printf("%d:%d da manhã", hora, minuto);
    }
    else if (hora == 12)
    {
        printf("%d:%d da tarde", hora, minuto);
    }
    else if (hora > 12 && hora <= 17)
    {
        printf("%d:%d da tarde", hora % 12, minuto);
    }
    else if (hora > 17 && hora <= 23)
    {
        printf("%d:%d da noite", hora % 12, minuto);
    }
}