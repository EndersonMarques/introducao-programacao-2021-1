#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome_clube[16];
    double valor_elenco;
    int qtd_grandes;
    int qtd_titulos;
    char neymar[4];
    char eh_flaflu[4];
    double pontos_total;
} Time;

int main()
{
    int n;
    scanf("%d", &n);
    int i;
    Time times[n];
    for (i = 0; i < n; i++)
    {
        scanf(" %15[^\n]", times[i].nome_clube);
        scanf("%lf", &times[i].valor_elenco);
        scanf("%d", &times[i].qtd_grandes);
        scanf("%d", &times[i].qtd_titulos);
        scanf(" %s", times[i].neymar);
        scanf(" %s", times[i].eh_flaflu);
    }
    // qtd pontos
    for (i = 0; i < n; i++)
    {
        double pontos = 0;
        pontos += times[i].valor_elenco;
        pontos += times[i].qtd_grandes * 100.0;
        pontos += times[i].qtd_titulos * 2000.0;
        if (strcmp(times[i].neymar, "sim") == 0)
        {
            pontos += 10000.0;
        }
        if (strcmp(times[i].eh_flaflu, "sim") == 0)
        {
            pontos += 20000.0;
        }

        times[i].pontos_total = pontos;
    }

    // Ordenar por pontos
    for (int j = 0; j < n - 1; j++)
    {
        for (i = 0; i < n - 1; i++)
        {
            if (times[i].pontos_total < times[i + 1].pontos_total)
            {
                Time aux = times[i];
                times[i] = times[i + 1];
                times[i + 1] = aux;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("%s %.2lf\n", times[i].nome_clube, times[i].pontos_total);
    }
}