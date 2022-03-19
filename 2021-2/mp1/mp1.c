#include <stdio.h>
#include <string.h>
#define TAM_CODE 15
#define N_REG 32

typedef struct
{
    int num_instrucao;
    char inst_nome[4];
    int destino;
    int origem;
} Instrucao;

int main()
{
    int registradores[N_REG] = {0};
    int N_LINHA;
    int i;
    // Lendo numero de instruções e declarando struct
    scanf("%d", &N_LINHA);
    Instrucao instrucoes[N_LINHA];
    for (i = 0; i < N_LINHA; i++)
    {
        scanf(" %s %d,%d", instrucoes[i].inst_nome, &instrucoes[i].destino, &instrucoes[i].origem);
    }

    // Fazendo operações
    for (i = 0; i < N_LINHA; i++)
    {
        // Variavies auxliares para origem e destino
        int origem = instrucoes[i].origem;
        int destino = instrucoes[i].destino;
        // Se for um loud variable
        if (strcmp(instrucoes[i].inst_nome, "ldv") == 0)
        {
            registradores[destino - 1] = instrucoes[i].origem;
        }
        // Se for um swap
        else if (strcmp(instrucoes[i].inst_nome, "swp") == 0)
        {
            int aux = registradores[destino - 1];
            registradores[destino - 1] = registradores[origem - 1];
            registradores[origem - 1] = aux;
        }
        // se for um mov
        else if (strcmp(instrucoes[i].inst_nome, "mov") == 0)
        {
            int copy = registradores[destino - 1];
            registradores[origem - 1] = copy;
        }
        // se for add
        else if (strcmp(instrucoes[i].inst_nome, "add") == 0)
        {
            registradores[destino - 1] = registradores[destino - 1] + registradores[origem - 1];
        }
        // se for um sub
        else if (strcmp(instrucoes[i].inst_nome, "sub") == 0)
        {
            registradores[destino - 1] = registradores[destino - 1] - registradores[origem - 1];
        }
        // se for uma mult
        else if (strcmp(instrucoes[i].inst_nome, "mul") == 0)
        {
            registradores[destino - 1] = registradores[destino - 1] * registradores[origem - 1];
        }
    }
    // Printando
    printf("Valores nos registradores:\n");
    for (i = 0; i < 32; i++)
    {
        if (registradores[i] != 0)
            printf("register[%d] = %d\n", i + 1, registradores[i]);
    }
    return 0;
}