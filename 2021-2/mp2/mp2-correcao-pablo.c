#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    Treinador aux;
    Treinador *p = treinadores;

    aux.nPokemons = 0;
    aux.pontuacao = 0;

    printf("Entre com o nome do novo treinador\n");
    scanf(" %[^\n]", aux.nome);

    p = (Treinador *)realloc(p, ((*qtdCompetidores) + 1) * sizeof(Treinador));
    if (p == NULL)
    {
        printf("Sem memoria");
        free(treinadores);
        exit(-1);
    }

    treinadores = p;

    treinadores[(*qtdCompetidores)] = aux;

    (*qtdCompetidores)++;

    return treinadores;
}

Treinador *addPokemon(Treinador *treinadores, char *nomeTreinador, Pokemon pokemon, int qtdCompetidores)
{
    int i, flag = 0;
    Treinador *p = treinadores;

    for (i = 0; (i < qtdCompetidores) && (flag == 0); i++)
    {
        if (strcmp(nomeTreinador, p[i].nome) == 0)
        {

            if (p[i].nPokemons == 0)
            {
                p[i].pokebola = (Pokemon *)malloc((p[i].nPokemons + 1) * sizeof(Pokemon));
                if (p[i].pokebola == NULL)
                {
                    printf("Sem memoria\n");
                    exit(-1);
                }
            }
            else
            {
                p[i].pokebola = (Pokemon *)realloc(p[i].pokebola, (p[i].nPokemons + 1) * sizeof(Pokemon));
                if (p[i].pokebola == NULL)
                {
                    printf("Sem memoria\n");
                    exit(-1);
                }
            }

            p[i].pokebola[p[i].nPokemons] = pokemon;

            p[i].nPokemons++;

            flag = 1;
        }
    }

    return p;
}

Treinador *removeTreinador(Treinador *treinadores, int *qtdCompetidores, int indexTreinador)
{
    Treinador *p = treinadores;
    int i, flag = 1;

    for (i = 0; (i < (*qtdCompetidores)) && flag; i++)
    {

        if (i == indexTreinador)
        {

            p[i] = p[(*qtdCompetidores) - 1];

            p = (Treinador *)realloc(p, ((*qtdCompetidores) - 1) * sizeof(Treinador));
            if (p == NULL)
            {
                printf("Sem memoria\n");
                exit(-1);
            }

            (*qtdCompetidores)--;

            flag = 0;
        }
    }

    return p;
}

char *batalha(Treinador **treinadores, char *nomeCompetidor1, char *nomeCompetidor2, int indexPokemon1, int indexPokemon2, int *qtdCompetidores)
{
    char *vencedor = NULL;
    int i, j;
    Pokemon poke1, poke2;
    int index1, index2;

    for (i = 0; i < (*qtdCompetidores); i++)
    {
        if (strcmp(nomeCompetidor1, (*treinadores)[i].nome) == 0)
        {
            // Achamos o competidor 1;
            index1 = i;
            for (j = 0; j < (*treinadores)[i].nPokemons; j++)
            {
                if (j == indexPokemon1)
                {
                    poke1 = (*treinadores)[i].pokebola[j];
                }
            }

            // poke1 = (*treinadores)[i].pokebola[indexPokemon1];
        }
        else if (strcmp(nomeCompetidor2, (*treinadores)[i].nome) == 0)
        {
            index2 = i;
            for (j = 0; j < (*treinadores)[i].nPokemons; j++)
            {
                if (j == indexPokemon2)
                {
                    poke2 = (*treinadores)[i].pokebola[j];
                }
            }
            // poke2 = (*treinadores)[i].pokebola[indexPokemon2];
        }
    }

    if ((poke1.ataque - poke2.defesa) > (poke2.ataque - poke1.defesa))
    {
        vencedor = nomeCompetidor1;
        (*treinadores)[index1].pontuacao++;
        (*treinadores)[index2].pontuacao--;

        if ((*treinadores)[index2].pontuacao == -2)
        {
            (*treinadores) = removeTreinador((*treinadores), qtdCompetidores, index2);
        }
    }

    else
    {
        vencedor = nomeCompetidor2;
        (*treinadores)[index1].pontuacao--;
        (*treinadores)[index2].pontuacao++;
        if ((*treinadores)[index1].pontuacao == -2)
        {
            (*treinadores) = removeTreinador((*treinadores), qtdCompetidores, index1);
        }
    }

    return vencedor;
}

int main()
{
    int opcao, qtdCompetidores = 0, i, j, poke1, poke2;
    Treinador *lista = NULL;
    char *vencedor = NULL;
    Pokemon aux;
    char treinador[30], comp1[30], comp2[30];

    do
    {

        printf("\t--- POKEDEX ---\n");
        printf("1... Adicionar Competidor\n");
        printf("2... Adicionar Pokemon\n");
        printf("3... Batalhar\n");
        printf("4... Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:

            lista = addTreinador(lista, &qtdCompetidores);

            printf("Lista atualizada\n");
            for (i = 0; i < qtdCompetidores; i++)
            {
                printf("Nome: %s\n", lista[i].nome);
                printf("Pontuacao: %d\n", lista[i].pontuacao);
                printf("Numero de Pokemons: %d\n", lista[i].nPokemons);
                if (lista[i].nPokemons > 0)
                {
                    printf("Pokemons de %s:\n", lista[i].nome);
                    for (j = 0; j < lista[i].nPokemons; j++)
                    {
                        printf("Pokemon: %s\n", lista[i].pokebola[j].nome);
                        printf("Ataque: %d\n", lista[i].pokebola[j].ataque);
                        printf("Defesa: %d\n", lista[i].pokebola[j].defesa);
                    }
                }
            }
            break;
        case 2:
            printf("Quem o capturou?\n");
            scanf(" %[^\n]", treinador);
            printf("Entre com os dados do novo POkemon\n");
            printf("Nome:\n");
            scanf(" %[^\n]", aux.nome);
            printf("ATQ:\n");
            scanf("%d", &aux.ataque);
            printf("DEF:\n");
            scanf("%d", &aux.defesa);

            lista = addPokemon(lista, treinador, aux, qtdCompetidores);

            break;
        case 3:
            printf("\t---BATALHA---\n");
            printf("Entre com os dados da batalha\n");
            printf("Entre com o nome do primeiro competidor:\n");
            scanf(" %[^\n]", comp1);
            printf("Qual o indice do pokemon de %s que vai batalhar?\n", comp1);
            scanf("%d", &poke1);
            printf("Entre com o nome do segundo competidor:\n");
            scanf(" %[^\n]", comp2);
            printf("Qual o indice do pokemon de %s que vai batalhar?\n", comp2);
            scanf("%d", &poke2);

            vencedor = batalha(&lista, comp1, comp2, poke1, poke2, &qtdCompetidores);

            printf("O vencedor da batalha foi %s\n", vencedor);

            break;
        case 4:
            break;

        default:
            printf("Entre com uma opcao valida\n");
            break;
        }

    } while (opcao != 4);

    for (i = 0; i < qtdCompetidores; i++)
    {
        free(lista[i].pokebola);
    }

    free(lista);
    free(vencedor);

    return 0;
}