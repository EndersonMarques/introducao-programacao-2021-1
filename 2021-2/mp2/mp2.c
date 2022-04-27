#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    int ataque, defesa;
} Pokemon;

typedef struct
{
    char nome[30];
    Pokemon *pokebola;
    int nPokemons, pontuacao;
} Treinador;

Treinador *addTreinador(Treinador *treinadores, int *qtdCompetidores)
{
    int aux, i;
    printf("Quantos Competidores quer add ?: ");
    scanf("%d", &aux);
    (*qtdCompetidores) = (*qtdCompetidores) + aux;

    treinadores = realloc(treinadores, (*qtdCompetidores) * sizeof(Treinador));
    if (treinadores == NULL)
    {
        printf("erro de alocaçao :'( \n");
        exit(-1);
    }
    for (i = (*qtdCompetidores) - aux; i < *(qtdCompetidores); i++)
    {
        printf("Informacoes do %dº Competidor\n", i + 1);
        printf(" Nome: ");
        scanf(" %29[^\n]", treinadores[i].nome);
        treinadores[i].nPokemons = 0;
        treinadores[i].pontuacao = 0;
        treinadores[i].pokebola = NULL;
    }
    return treinadores;
}
Treinador *addPokemon(Treinador *treinadores, char *nomeTreinador, Pokemon pokemon, int qtdCompetidores)
{
    int i;
    for (i = 0; i < qtdCompetidores; i++)
    {
        if (strcmp(treinadores[i].nome, nomeTreinador) == 0)
        {
            treinadores[i].nPokemons++;
            treinadores[i].pokebola = (Pokemon *)realloc(treinadores[i].pokebola, (treinadores[i].nPokemons + 1) * sizeof(Pokemon));
            treinadores[i].pokebola[treinadores[i].nPokemons - 1] = pokemon;
        }
    }

    return treinadores;
}
Treinador *removeTreinador(Treinador *treinadores, int *qtdCompetidores, int indexTreinador);
char *batalha(Treinador **treinadores, char *nomeCompetidor1, char *nomeCompetidor2, int indexPokemon1, int indexPokemon2, int *qtdCompetidores)
{
    Pokemon *ListAux1 = NULL;
    Pokemon *ListAux2 = NULL;
    int posPlayer1;
    int posPlayer2;
    char *winner;
    for (int i = 0; i < *qtdCompetidores; i++)
    {
        if (strcmp((*treinadores[i]).nome, nomeCompetidor1) == 0)
        {
            ListAux1 = treinadores[i]->pokebola;
            posPlayer1 = i;
        }
    }
    for (int i = 0; i < *qtdCompetidores; i++)
    {
        if (strcmp((*treinadores[i]).nome, nomeCompetidor2) == 0)
        {
            ListAux2 = treinadores[i]->pokebola;
            posPlayer2 = i;
        }
    }

    if (ListAux1[indexPokemon1].ataque > ListAux2[indexPokemon1].defesa)
    {
        winner = nomeCompetidor1;
        treinadores[posPlayer1]->pontuacao++;
    }
    else
    {
        winner = nomeCompetidor2;
        treinadores[posPlayer2]->pontuacao++;
    }

    // verificando se o competidor foi desclassificado
    // Infelismente nao consegui terminar a função por contade tempo :/
    // if (treinadores[posPlayer1]->pontuacao <= -5)
    // {
    //     *treinadores = removeTreinador(*treinadores, qtdCompetidores, posPlayer1);
    // }
    // if (treinadores[posPlayer2]->pontuacao <= -5)
    // {
    //     *treinadores = removeTreinador(*treinadores, qtdCompetidores, posPlayer2);
    // }

    return winner;
}
void print_comp(Treinador *treinadores, int *qtdCmp)
{
    for (int i = 0; i < (*qtdCmp); i++)
    {
        printf("Treinador %dº\n", i + 1);
        printf("  Nome: %s\n", treinadores[i].nome);
        printf("  qtdPokes: %d\n", treinadores[i].nPokemons);
        if (treinadores[i].nPokemons > 0)
        {
            Pokemon *aux = treinadores[i].pokebola;
            printf(" Pokemons: ");
            for (int j = 0; j < treinadores[i].nPokemons; j++)
            {
                printf(" %s", aux[j].nome);
            }
            printf("\n");
        }
        printf("  Pontos: %d\n", treinadores[i].pontuacao);
    }
}
int main()
{

    Treinador *competidores = NULL;
    Pokemon newPokemon;
    int index1, index2;
    char comp1[30], comp2[20];
    char nomeComp[30];
    int qtdCompetidores = 0;
    int op;
    do
    {
        printf("======= Menu =======\n");
        printf("1 -  Add Competidor\n");
        printf("2 -  Add Pokemon\n");
        printf("3 -  Fight\n");
        printf("4 -  Sair\n");
        printf("0 -  Printar Comp\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            /* Adicionar Competidor */
            competidores = addTreinador(competidores, &qtdCompetidores);
            break;
        case 2:
            /* Adicionar Pokemon */
            printf("Adicionar Pokemon\n");
            printf(" Nome do Pokemon: ");
            scanf(" %29[^\n]", newPokemon.nome);
            printf(" Ataque do Pokemon: ");
            scanf("%d", &newPokemon.ataque);
            printf(" Defesa do Pokemon: ");
            scanf("%d", &newPokemon.defesa);
            printf("Qual competidor vai receber esse Pokemon ? ");
            scanf(" %29[^\n]", nomeComp);
            competidores = addPokemon(competidores, nomeComp, newPokemon, qtdCompetidores);
            break;
        case 3:
            /* Batalhar */
            printf(" Nome do Competidor 1: ");
            scanf(" %29[^\n]", comp1);
            printf(" Nome do Competidor 2: ");
            scanf(" %29[^\n]", comp2);
            printf("Diga o index do Pokemon 1: ");
            scanf("%d", &index1);
            printf("Diga o index do Pokemon 2: ");
            scanf("%d", &index1);
            char *winner = batalha(&competidores, comp1, comp2, index1, index2, &qtdCompetidores);
            printf("%s", winner);
            break;
        case 0:
            /* Batalhar */
            print_comp(competidores, &qtdCompetidores);
            // printf("Pokemon: %d", competidores[0].pokebola[0].defesa);
            break;

        default:
            break;
        }
    } while (op != 4);

    free(competidores);
    exit(-1);

    return 0;
}