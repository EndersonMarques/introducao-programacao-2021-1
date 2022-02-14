#include <stdio.h>
#define velocidade_verde 80
#define velocidade_vermelho 100
#define velocidade_roxo 120
#define velocidade_amarelo 80

int main()
{
    int moedas;
    int yoshi1, yoshi2, yoshi3, yoshi4;
    int razao_verde, razao_vermelho, razao_roxo, razao_amarelo;

    scanf("%d", &moedas);
    scanf("%d %d %d %d", &yoshi1, &yoshi2, &yoshi3, &yoshi4);

    razao_verde = velocidade_verde / yoshi1;
    razao_vermelho = velocidade_vermelho / yoshi2;
    razao_roxo = velocidade_roxo / yoshi3;
    razao_amarelo = velocidade_amarelo / yoshi4;

    printf("%d %d %d %d\n", razao_verde, razao_vermelho, razao_roxo, razao_amarelo);
    if (moedas >= yoshi1 || moedas >= yoshi2 || moedas >= yoshi3 || moedas >= yoshi4)
    {

        if ((razao_verde >= razao_vermelho && razao_verde >= razao_roxo && razao_verde >= razao_amarelo))
        {
            printf("Verde\n");
        }
        else if ((razao_vermelho > razao_verde && razao_vermelho >= razao_roxo && razao_vermelho >= razao_amarelo))
        {
            printf("Vermelho\n");
        }
        else if ((razao_roxo > razao_verde && razao_roxo > razao_vermelho && razao_roxo >= razao_amarelo))
        {
            printf("Roxo\n");
        }
        else if ((razao_amarelo > razao_verde && razao_amarelo > razao_vermelho && razao_amarelo > razao_roxo))
        {
            printf("Amarelo\n");
        }
    }
    else
    {
        printf("Acho que vou a pe :(\n");
    }
}