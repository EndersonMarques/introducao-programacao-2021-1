#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    char tipo[50];
    int ataque;
    int defesa;
    char funcao[50];
} Pokemon;

Pokemon pegar_pelo_nome(char *nome, Pokemon *p, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        if (strcmp(nome, p[i].nome) == 0)
        {
            return p[i];
        }
    }
}

void list(char *tipo, Pokemon *p, int tam)
{
    int i, j = 1;
    for (i = 0; i < tam; i++)
    {
        if (strcmp(p[i].tipo, tipo) == 0)
        {
            printf("Pokemon %d: %s\n", j, p[i].nome);
            printf(" Ataque: %d\n", p[i].ataque);
            printf(" Defesa: %d\n", p[i].defesa);
            j++;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    // Declarando N pokemons
    Pokemon pokemons[n];
    int i;

    // lendo apenas os pokemons sem funcao
    for (i = 0; i < n; i++)
    {
        scanf(" %49[^\n]", pokemons[i].nome);
        scanf(" %49[^\n]", pokemons[i].tipo);
        scanf("%d", &pokemons[i].ataque);
        scanf("%d", &pokemons[i].defesa);
    }

    // lendo funcao
    i = 0;
    char funcao[50] = "";
    while (1)
    {
        scanf(" %49[^\n]", funcao);
        if (strcmp(funcao, "0") == 0)
            break;
        strcpy(pokemons[i].funcao, funcao);
        if (strncmp(pokemons[i].funcao, "luta", 4) == 0)
        {
            char pokemon1[50];
            char pokemon2[50];
            scanf(" %s vs %s", pokemon1, pokemon2);
            Pokemon newPk1 = pegar_pelo_nome(pokemon1, pokemons, n);
            Pokemon newPk2 = pegar_pelo_nome(pokemon2, pokemons, n);
            int totalPontos1, totalPontos2;
            totalPontos1 = (newPk1.ataque) - (newPk2.defesa);
            totalPontos2 = (newPk2.ataque) - (newPk1.defesa);
            if (totalPontos1 > totalPontos2)
            {
                printf("%s deitou %s na porrada\n", newPk1.nome, newPk2.nome);
            }
            else if (totalPontos2 > totalPontos1)
            {
                printf("%s deitou %s na porrada\n", newPk2.nome, newPk1.nome);
            }
            else
            {
                printf("parece que temos um empate\n");
            }
        }
        else if (strncmp(pokemons[i].funcao, "list\n", 4) == 0)
        {
            char tipo[50];
            for (int j = 0; funcao[j] != '\0'; j++)
            {
                tipo[j] = funcao[j + 5];
            }
            list(tipo, pokemons, n);
            // printf("tipo: %s\n", tipo);
        }
        i++;
    }
    // printf("\n%d\n", i);
}
