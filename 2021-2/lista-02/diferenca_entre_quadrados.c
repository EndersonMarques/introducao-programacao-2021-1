#include <stdio.h>

int main()
{
    int n, termo_maior, termo_menor, i, j, achei = 0;

    scanf("%d", &n);
    while (n != 0)
    {
        if (n % 2 == 0)
            n += 1;

        for (i = 1; i < n && !achei; i++)
        {
            if ((i * i) - ((i - 1) * (i - 1)) == n && (i + (i - 1)) == n)
            {
                termo_maior = i;
                termo_menor = termo_maior - 1;
                achei = 1;
            }
        }
        achei = 0;
        printf("%d - %d\n", termo_maior * termo_maior, termo_menor * termo_menor);
        scanf("%d", &n);
    }
    return 0;
}
