#include <stdio.h>

int main()
{
    int soldados_al, tanques_al, avioes_al, misseis_al;
    int soldados_ing, tanques_ing, avioes_ing, misseis_ing;
    int soldados_rf, tanques_rf, avioes_rf, misseis_rf;
    int contador_inimigo = 0;
    int contador_aliado = 0;
    int soldados_ing_rf, tanques_ing_rf, avioes_ing_rf, misseis_ing_rf;

    scanf("%d %d %d %d", &soldados_al, &tanques_al, &avioes_al, &misseis_al);
    scanf("%d %d %d %d", &soldados_ing, &tanques_ing, &avioes_ing, &misseis_ing);
    scanf("%d %d %d %d", &soldados_rf, &tanques_rf, &avioes_rf, &misseis_rf);

    soldados_ing_rf = soldados_ing + soldados_rf;
    tanques_ing_rf = tanques_ing + tanques_rf;
    avioes_ing_rf = avioes_ing + avioes_rf;
    misseis_ing_rf = misseis_ing + misseis_rf;

    if (soldados_ing_rf > soldados_al)
    {
        contador_inimigo++;
    }
    else if (soldados_al > soldados_ing_rf)
    {
        contador_aliado++;
    }
    if (tanques_ing_rf > tanques_al)
    {
        contador_inimigo++;
    }
    else if (tanques_al > tanques_ing_rf)
    {
        contador_aliado++;
    }
    if (avioes_ing_rf > avioes_al)
    {
        contador_inimigo++;
    }
    else if (avioes_al > avioes_ing_rf)
    {
        contador_aliado++;
    }
    if (misseis_ing_rf > misseis_al)
    {
        contador_inimigo++;
    }
    else if (misseis_al > misseis_ing_rf)
    {
        contador_aliado++;
    }
    // printf("%d", contador_inimigo);
    // printf("%d", contador_aliado);
    // Verificando
    if (contador_inimigo > 2)
    {
        printf("Recuar\n");
    }
    else if (contador_aliado > 2)
    {
        printf("Avancar\n");
    }
    else
        printf("Permanecer\n");

    return 0;
}