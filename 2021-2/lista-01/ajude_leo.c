#include <stdio.h>
#include <math.h>

int main()
{
    int x, y;

    int a, n, b, m;

    scanf("(%d, %d)", &x, &y);
    scanf("%d*x^%d - %d*y^%d", &a, &n, &b, &m);

    int result = (a * (pow(x, n))) - (b * (pow(y, m)));
    if (result == 0)
    {
        printf("a função não está definida em (%d,%d) .-.", x, y);
    }
    else
    {
        printf("a função está definida em (%d,%d)", x, y);
    }
}