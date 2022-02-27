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

void salvarArquivoBinario()
{
    FILE *arquivo = fopen("lista2.txt", "wb");

    if (arquivo)
    {
        fprintf(arquivo, "%d\n", qtd);
        fwrite(lista, sizeof(Pessoa),qtd ,arquivo);

        fclose(arquivo);
    }
    else
    {
        printf("Nao foi possivel abrir o arquivo");
    }
}

void lerArquivoBinario()
{
    FILE *arquivo = fopen("lista2.txt", "rb");
    if (arquivo)
    {
        fscanf(arquivo, "%d\n", &qtd);
        fread(lista, sizeof(Pessoa), qtd, arquivo);           
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
        printf("\n1 - Cadastrar\n2 - Imprimir\n3 - Salvar em arquivo Binario\n4 - Ler em arquivo Binario\n0 - Sair\n");
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
            salvarArquivoBinario();
            break;
        case 4:
            lerArquivoBinario();
            break;
        default:
            printf("Opcao Invalida.\n\n");
        }

    } while (op != 0);

    return 0;
}