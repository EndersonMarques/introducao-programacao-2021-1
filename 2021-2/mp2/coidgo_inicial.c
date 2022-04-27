#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char nome[40];
    double preco;
    int qt;
} Pessoa;

void cadastrarPessoas(Pessoa **ptr, int *qtd)
{
    Pessoa aux;
    Pessoa *p = NULL;
    // ler para uma memoria aux
    // Alocar a memoria
    // Passar da memoria aux pra memoria alocada

    printf("Entre com o codigo\n");
    while (scanf("%d", &aux.codigo) && (aux.codigo != 0))
    {
        printf("Entre com o nome\n");
        scanf(" %39[^\n]", aux.nome);
        printf("Entre com o preco\n");
        scanf("%lf", &aux.preco);
        printf("Entre com a quantidade\n");
        scanf("%d", &aux.qt);

        // Realizando a alocação
        (*ptr) = (Pessoa *)realloc((*ptr), (*qtd + 1) * sizeof(Pessoa));
        if ((*ptr) == NULL)
        {
            printf("Erro ao alocar\n");
            exit(-1);
        }

        (*ptr)[*qtd] = aux;
        (*qtd)++;
        // p[x] = 10;
        printf("Entre com o codigo\n");
    }

    //***P -> **p **p -> *p *p -> p p p  p
    // p = &a;
    //(*p) = 100;
}

void gerarCentral(Pessoa *ptr, int i)
{

    FILE *arq = fopen("central.bin", "w");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arq\n");
        exit(-1);
    }
    // w escrever
    // a adicionar ao final do arq
    // r leitura
    fwrite(ptr, sizeof(Pessoa), i, arq);
    // &i, sizeof(int), 1, arq
    // 1 parametro = De onde vc quer escrever
    // 2 parametro = O tamanho que vc quer escrever
    // 3 parametro = Quantas vezes vai escrever esse tamanho
    // 4 parametro = Onde vc quer escrever

    fclose(arq);
}

void lerCentral(Pessoa **ptr, int *qt)
{
    Pessoa aux;
    FILE *arq = fopen("central.bin", "r");
    if (arq == NULL)
    {
        printf("Erro ao abrir o arq\n");
        exit(-1);
    }

    while (fread(&aux, sizeof(Pessoa), 1, arq) != 0)
    {
        // 1 = Onde vc quer salvar  o que ler
        // 2 = Qual o tamanho que queres ler
        // 3 = quantas vezes vc quer ler esse tamanho
        // 4 = De onde vc quer ler

        (*ptr) = (Pessoa *)realloc((*ptr), (*qt + 1) * sizeof(Pessoa));
        if ((*ptr) == NULL)
        {
            printf("Erro ao alocar\n");
            exit(-1);
        }

        (*ptr)[*qt] = aux;
        (*qt)++;
    }

    fclose(arq);
}

int main()
{
    Pessoa *ptrPessoa = NULL;
    Pessoa *pLidas = NULL;
    int qtd = 0, i, lidas = 0;

    cadastrarPessoas(&ptrPessoa, &qtd);

    gerarCentral(ptrPessoa, qtd);

    lerCentral(&pLidas, &lidas);

    printf("%d pessoas foram lidas\n", lidas);
    for (i = 0; i < lidas; i++)
    {
        printf("Nome: %s\n", pLidas[i].nome);
        printf("Codigo: %d\n", pLidas[i].codigo);
        printf("Preco: %.2lf\n", pLidas[i].preco);
        printf("QTD: %d\n", pLidas[i].qt);
    }

    free(ptrPessoa);
    free(pLidas);

    return 0;
}