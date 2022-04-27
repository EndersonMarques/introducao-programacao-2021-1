#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int estadoAtual, estadoFuturo, caractereAReconhecer;
    char estadoFinal; // 1 – Sim, 0 - Não
} Transicao;

Transicao *carregaAutomato(char *nomeArq, long *numEstados)
{
    // Criando varivaies auxliaares
    Transicao *ListAux = NULL;
    Transicao conteudo;
    FILE *arq = fopen(strcat(nomeArq, ".bin"), "rb");
    if (arq == NULL)
    {
        printf("Opa, temos um probela ao abrir o arquivo \n");
        exit(-1);
    }
    // Vendo quantos estados existem no arquivo e Preenchendo a lista || O->O
    while (fread(&conteudo, sizeof(Transicao), 1, arq) != ".")
    {
        (*numEstados)++;
        ListAux = (Transicao *)realloc(ListAux, (*numEstados) * sizeof(Transicao));
        ListAux[(*numEstados)] = conteudo;
    }
    fclose(arq);
    return ListAux;
}
long *localizaEstado(Transicao *automato, long numEstados, int estadoAtual, int *numEstadosAtuais, char qual)
{
    int vet[numEstados], i;
    if (qual == '0')
    {
        for (i = 0; i < numEstadosAtuais; i++)
        {
            vet[i] = i;
        }
    }
    else if (qual == '1')
    {
        return automato[estadoAtual].estadoFuturo;
    }
    return vet;
}
int avaliaTransicao(Transicao *automato, long numEstados, int estadoAtual, char caractereAtual)
{
    int *vet = localizaEstado(automato, numEstados, estadoAtual, numEstados, '1');
    int i;
    for (i = 0; i < numEstados; i++)
    {
        if (automato[i].estadoAtual == estadoAtual && (automato[i].caractereAReconhecer == caractereAtual))
        {
            return automato[i].estadoFuturo;
        }
        else
        {
            return -1;
        }
    }
}
void gravaStatus(FILE *arqSaida, char *entrada, char status)
{
    if (status - '0' == -1)
    {
        fscanf(arqSaida, "%s, - (erro de reconhecimento)\n", entrada);
    }
    else if (status - '0' == 0)
    {
        fscanf(arqSaida, "%s, - (reconhecida)\n", entrada);
    }
    else if (status - '0' == 1)
    {
        fscanf(arqSaida, "%s, - (nao reconhecida)\n", entrada);
    }
}
void reconhece(FILE *arqSaida, Transicao *automato, long numEstados, char *entrada)
{
    int i, chamou = 0;
    // Assumindo como estadoAtual 0 chama avaliaTransicao para cada caracter
    for (i = 0; i < strlen(entrada); i++)
    {
        if (avaliaTransicao(automato, numEstados, 0, entrada[i]) == -1)
        {
            // chama gravaStatus passando status -1
            gravaStatus(arqSaida, entrada, '-1');
            chamou = 1;
        }
    }
    if (!chamou)
    {

        // Apenas cai aqui se a entrada toda foi processada e nao entrou no if acima
        // chama gravaStatus passando status 0
        gravaStatus(arqSaida, entrada, '0');
    }
    else
    {
        // chama gravaStatus passando status 1
        gravaStatus(arqSaida, entrada, '1');
    }
}
int main()
{

    // Criando as variaveis
    Transicao *ListaAutomatos = NULL;
    char nomeArq[51];
    long numEstados = 0;
    char automato[100] = "";
    int i = 0;
    FILE *arqSaida = NULL;

    // Carrega automato
    printf("Digite o nome do arquivo: ");
    scanf(" %50[^\n]", nomeArq);
    ListaAutomatos = carregaAutomato(nomeArq, &numEstados);
    printf("Digite os automatos seguintes:\n");

    // Padrao IF (A)ABCX
    arqSaida = fopen(strcat(nomeArq, ".txt"), "w");

    while (strcmp(automato, "." != 0))
    {
        // Adcionando novos estados além dos que tem no arq binario
        numEstados++;
        ListaAutomatos = (Transicao *)realloc(ListaAutomatos, numEstados * sizeof(Transicao));
        // Encontrando o epson
        ListaAutomatos[numEstados].estadoAtual = i;
        ListaAutomatos[numEstados].estadoFinal = i + 1;
        ListaAutomatos[numEstados].caractereAReconhecer = automato[i];
        reconhece(arqSaida, ListaAutomatos, numEstados, automato);
        i++;
    }

    // Desalocando e fechando arquivos
    fclose(arqSaida);
    free(ListaAutomatos);
    return 0;
}