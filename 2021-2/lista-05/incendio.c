#include <stdio.h>

typedef struct
{
    int id;
    double temperatura;
    char fumaca;

} Incendio;

int main()
{
    int n;
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int casos_testes;
        double media_temp = 0;
        scanf("%d", &casos_testes);
        Incendio incendios[casos_testes];

        for (j = 0; j < casos_testes; j++)
        {
            scanf("%d", &incendios[j].id);
            scanf("%lf", &incendios[j].temperatura);
            scanf(" %c", &incendios[j].fumaca);
            media_temp += incendios[j].temperatura;
        }
        media_temp = (media_temp / casos_testes) * 1.15;
        printf("TESTE %d\n", i + 1);
        for (j = 0; j < casos_testes; j++)
        {
            if (incendios[j].fumaca == 'S')
            {
                printf("%d\n", incendios[j].id);
            }
            else if (incendios[j].temperatura > media_temp)
            {
                printf("%d\n", incendios[j].id);
            }
            else if (incendios[j].temperatura > 40.0)
            {
                printf("%d\n", incendios[j].id);
            }
        }
    }

    return 0;
}