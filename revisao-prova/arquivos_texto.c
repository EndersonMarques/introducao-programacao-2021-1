#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    int idade;
    char sexo;
} Pessoa;

int tam = 10;
Pessoa lista[10];

int qtd = 0;

int cadastrarPessoa()
{
    if (qtd < tam)
    {
        Pessoa p;
        scanf("%*c"); //Limpando burffer do teclado
        printf("Nome: ");
        fgets(p.nome, 50, stdin);
        printf("Digite idade e sexo m ou f: ");
        scanf("%d %c", &p.idade, &p.sexo);
        lista[qtd] = p;
        qtd++;
        return 1;
    }
    else
    {
        printf("ERRO: vetor cheio\n\n");
        return 0;
    }
}

void imprimirPessoa()
{
    int i;
    for (i = 0; i < qtd; i++)
    {
        printf("Nome: %s", lista[i].nome);
        printf("Idade: %d\tSexo: %c\n", lista[i].idade, lista[i].sexo);
    }
}

void salvarArquivo()
{
    FILE *arquivo = fopen("lista.txt", "w");
    int i;
    if (arquivo)
    {
        fprintf(arquivo, "%d\n", qtd);
        for (i = 0; i < qtd; i++)
        {
            fprintf(arquivo, "%s", lista[i].nome);
            fprintf(arquivo, "%d\n", lista[i].idade);
            fprintf(arquivo, "%c\n", lista[i].sexo);
        }

        fclose(arquivo);
    }
    else
    {
        printf("Nao foi possivel abrir o arquivo");
    }
}

void lerArquivo()
{
    FILE *arquivo = fopen("lista.txt", "r");
    int i;
    if (arquivo)
    {
        fscanf(arquivo, "%d\n", &qtd);
        for (i = 0; i < qtd; i++)
        {
            Pessoa p;
            fgets(p.nome, 50, arquivo);
            fscanf(arquivo, "%d\n", &p.idade);
            fscanf(arquivo, "%c\n", &p.sexo);
            lista[i] = p;
        }
        fclose(arquivo);
    }
    else
    {
        printf("Nao foi possivel abrir o arquivo");
    }
}

int main()
{
    int op;

    do
    {
        printf("\n1 - Cadastrar\n2 - Imprimir\n3 - Salvar em arquivo\n4 - Ler em arquivo\n0 - Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("Tchau...\n\n");
            break;
        case 1:
            cadastrarPessoa();
            break;
        case 2:
            imprimirPessoa();
            break;
        case 3:
            salvarArquivo();
            break;
        case 4:
            lerArquivo();
            break;
        default:
            printf("Opcao Invalida.\n\n");
        }

    } while (op != 0);

    return 0;
}