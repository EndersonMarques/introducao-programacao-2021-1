#include <stdio.h>

int main()
{

    int money, devendo, notas;

    scanf("%d%d", &money, &devendo);

    if(devendo > money)
    {
        printf("Pedro vai ter que fugir");
    }
    else 
    {

        notas = money / 100;

        if(devendo <=0){
            printf("Esta pago\nSobrou %d", money);
        }
        else if(money < 100){
            printf("Pedro vai ter que fugir");
        }

        else if(devendo < (notas *100)){
            printf("Pegou mais\nEsta pago\nSobrou %d", (money -(notas*100)));
        }
        else if(devendo == (notas *100))
        {
            printf("Esta pago\nSobrou %d", (money -(notas*100)));
        }
        else if(money == (notas *100))
        {
            printf("Esta pago\nSobrou %d", (money -(notas*100)));
        }
        else{
            printf("Pedro vai ter que fugir");
        }
    }

    return 0;
}