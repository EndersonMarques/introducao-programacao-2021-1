#include <stdio.h>
#include <math.h>


int perfect_raiz(int x){
    int teste = sqrt(x);

    if(teste * teste == x){
        return 1;
    }
    return 0;
}


int anterior_quadrado(int x)
{
    
    if (perfect_raiz(x))
    {
        return x;
    }

    for (int i = x; i > 0; x--)
    {
        if (perfect_raiz(x))
        {
            return x;
        }
    }
}
int sucessor_quadrado(int x)
{
    int achei = 0;
    if (perfect_raiz(x))
    {
        return x;
    }

    for (int i = x+1; i > 0; !achei)
    {
        if (perfect_raiz(i))
        {
            return i;
            achei = 1;
        }
    }
}

int main()
{
    int n, sucessor, anterior;

    scanf("%d", &n);
    while (n != 0)
    {
        sucessor = sucessor_quadrado(n);
        anterior = anterior_quadrado(sucessor+1);
    printf("%d-%d\n", sucessor, anterior);
        scanf("%d", &n);
    }
    return 0;
}