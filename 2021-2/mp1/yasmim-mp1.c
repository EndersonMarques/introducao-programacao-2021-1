
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAM_CODE 15
#define N_REG 32
// yvso
typedef struct
{
    int num_instrucao;
    char instr_nome[4];
    int destino, origem;
} Instrucao;
int main()
{
    int N_LINHAS, org, dest, aux1 = 0, aux2 = 0, flag = 0, registrador[100], valor[100] = {0}, alert = 0;
    // instruções alocadas, fazer comparação
    char vet_1[4] = "ldv", vet_2[4] = "swp", vet_3[4] = "mov";
    char vet_4[4] = "add", vet_5[4] = "sub", vet_6[4] = "mul";
    scanf("%d", &N_LINHAS);
    char codigo[N_LINHAS][TAM_CODE];
    Instrucao instrucao[N_LINHAS];
    for (int i = 0; i < 100; i++)
    {
        registrador[i] = 0; // Inicialmente zerando o registrador pra serem usado nas funções
        for (int j = 0; j < 100; j++)
        {
            codigo[i][j] = '\0'; // zerar o vetor de strings
        }
    }
    for (int i = 0; i < N_LINHAS; i++)
    {
        valor[i] = 0; // zerar vetor valor (será usado quanro a função for ldv)
        scanf(" %s %d,%d", codigo[i], &dest, &org);
        // fazendo a alocação dos valores lidos
        strcpy(instrucao[i].instr_nome, codigo[i]);
        instrucao[i].destino = dest;
        instrucao[i].origem = org;
        // fazendo as alocações das instruções conforme leitura
        if (strcmp(instrucao[i].instr_nome, vet_1) == 0)
        {
            instrucao[i].num_instrucao = 1;
            valor[i] = instrucao[i].origem;
        }
        else if (strcmp(instrucao[i].instr_nome, vet_2) == 0)
        {
            instrucao[i].num_instrucao = 2;
        }
        else if (strcmp(instrucao[i].instr_nome, vet_3) == 0)
        {
            instrucao[i].num_instrucao = 3;
        }
        else if (strcmp(instrucao[i].instr_nome, vet_4) == 0)
        {
            instrucao[i].num_instrucao = 4;
        }
        else if (strcmp(instrucao[i].instr_nome, vet_5) == 0)
        {
            instrucao[i].num_instrucao = 5;
        }
        else if (strcmp(instrucao[i].instr_nome, vet_6) == 0)
        {
            instrucao[i].num_instrucao = 6;
        }
    }
    // analisar as instruções
    for (int i = 0; i < N_LINHAS; i++)
    {
        if (instrucao[i].num_instrucao == 1)
        {
            // fazer um vetor registrador para guardar as funções
            // guardando no vetor registrador o valor do vl destino
            registrador[instrucao[i].destino] = valor[i];
        }
        if (instrucao[i].num_instrucao == 2)
        {
            // fazendo a troca dos valores
            aux1 = registrador[instrucao[i].origem];
            aux2 = registrador[instrucao[i].destino];
            registrador[instrucao[i].origem] = aux2;
            registrador[instrucao[i].destino] = aux1;
        }
        if (instrucao[i].num_instrucao == 3)
        {
            // copia valor destino em origem
            registrador[instrucao[i].origem] =
                registrador[instrucao[i].destino];
        }
        if (instrucao[i].num_instrucao == 4)
        {
            // obs: ficou um pouco grandino *--* (faz a soma de orgem e destino --> destino)
            registrador[instrucao[i].destino] = registrador[instrucao[i].destino] + registrador[instrucao[i].origem];
        }
        if (instrucao[i].num_instrucao == 5)
        {
            // same obs! faznedo a subtração destino-origem-->destino
            registrador[instrucao[i].destino] =
                registrador[instrucao[i].destino] - registrador[instrucao[i].origem];
        }
        if (instrucao[i].num_instrucao == 6)
        {
            // same obs! faznedo a mult destino-origem-->destino
            registrador[instrucao[i].destino] = registrador[instrucao[i].destino] * registrador[instrucao[i].origem];
        }
    }
    // para printar irei analisa o instrução destino de cada um
    printf("Valores nos registradores:\n");
    for (int i = 0; i < N_LINHAS && alert == 0; i++)
    {
        if (instrucao[i].destino > N_REG || instrucao[i].origem > N_REG)
        {
            printf("Fatality ERROR\n");
            alert = 1;
        }
        for (int j = 0; j < 100 && flag == 0; j++)
        {
            if (j == instrucao[i].destino)
            {
                printf("resister[%d]= %d\n", j, registrador[j]);
                flag = 1; // a flag é para ele printar apenas 1 vez e partir para o proximo i;
            }
        }
        flag = 0;
    }
    return 0;
}
