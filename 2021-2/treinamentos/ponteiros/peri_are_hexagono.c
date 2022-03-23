#include <stdio.h>
#include <math.h>

void calc_hexa(float l, float *area, float *perimetro)
{
    *area = (3 * pow(l,2) * sqrt(3)/ 2);
    *perimetro = 6* l;
}

int main()
{

    float lado;
    printf("Digite o lado do hexagono: \n");
    scanf("%f", &lado);
    while(lado > 0)
    {
        float area;
        float perimetro;
        calc_hexa(lado, &area, &perimetro);
        printf("Area: %.2f  || Perimetro: %.2f\n", area, perimetro);
        printf("Digite o lado do hexagono: \n");
        scanf("%f", &lado);
    }
    printf("Programa finalizado !!! :D\n"); 

    return 0;
}