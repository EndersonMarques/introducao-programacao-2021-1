#include <stdio.h>
#include <string.h>

typedef struct
{
    int passagem;
    char data[15];
    char deOnde[50];
    char prOnde[50];
    char horario[50];
    int poltrona;
    int idade;
    char nome[50];
} Passageiro;

int main()
{
    // Declarar
    Passageiro passageiros[44];
    int i, j, tam = 0;
    int idades = 0;
    for (i = 0; i < 44; i++)
    {
        scanf("%d", &passageiros[i].passagem);
        if (passageiros[i].passagem == -1)
            break;
        scanf(" %s", passageiros[i].data);
        scanf(" %49[^\n]", passageiros[i].deOnde);
        scanf(" %49[^\n]", passageiros[i].prOnde);
        scanf(" %s", passageiros[i].horario);
        scanf("%d", &passageiros[i].poltrona);
        scanf("%d", &passageiros[i].idade);
        scanf(" %49[^\n]", passageiros[i].nome);
        tam++;
        idades += passageiros[i].idade;
    }
    // verificando condiçoes e printando
    int meida_idades = idades / tam;

    for (i = 0; i < tam; i++)
    {
        if (passageiros[i].idade > meida_idades && passageiros[i].poltrona % 2 == 0)
        {
            printf("%s\n", passageiros[i].nome);
        }
    }
    return 0;
}