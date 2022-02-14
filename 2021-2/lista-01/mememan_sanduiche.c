#include <stdio.h>

int main()
{

    char i0, i1, i2, i3, i4, i5, i6;

    scanf("%c%c%c%c%c%c%c", &i0, &i1, &i2, &i3, &i4, &i5, &i6);

    if (i0 == ' ' || i6 == ' ')
    {
        printf("Invalido\n");
    }
    else
    {
        if (i0 != i6)
        {
            printf("Invalido\n");
        }
        else if (i1 != 'b' && i1 != 'f' && i1 != 'p' && i1 != ' ')
        {

            printf("Invalido\n");
        }
        else if ((i2 != 'A' && i2 != 'T' && i2 != 'C' && i2 != 'R' && i2 != ' ') || (i3 != 'A' && i3 != 'T' && i3 != 'C' && i3 != 'R' && i3 != ' ') || (i4 != 'A' && i4 != 'T' && i4 != 'C' && i4 != 'R' && i4 != ' '))
        {
            printf("Invalido\n");
        }
        else if ((i5 != 'P'))
        {
            printf("Invalido\n...Mas pelo menos ganhou um chute\n");
        }
        else
        {
            printf("Valido\n");
        }
    }

    return 0;
}