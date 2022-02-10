#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, d;
    int delta;
    float x1, x2;
    int raiz_delta;
    printf("Infome respectivamente o termo A B e C da equaçao\n");
    scanf("%d %d %d", &a, &b, &c);

    if (a == 0)
    {
        printf("Nao eh uma equacao do primeiro grau !!\n");
        return 0;
    }

    delta = (b * b) - (4 * a * c);

    if (delta < 0)
    {
        printf("A equecao nao tem solucao real\n");
        return 0;
    }
    raiz_delta = sqrt(delta);
    x1 = (float)((b * (-1)) + raiz_delta) / (2 * a);
    x2 = (float)((b * (-1)) - raiz_delta) / (2 * a);

    printf("As Raizes sao x1 = %.1f, x2= %.1f\n", x1, x2);
}