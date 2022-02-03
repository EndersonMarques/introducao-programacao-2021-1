#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float tempoAtend;
} Cliente;

float sorteia()
{
    return (rand() % 101) / 100.0;
}

// Caixas Independentes
Cliente *VetInd[5];
float VetCtx[5] = {0};
Cliente *VetUn[5];

void insereFilaIndependente()
{
}
void insereMenorFila(Cliente *VetInd, Cliente *VetUn, Cliente cliente)
{
    float menor1 = 0;
    float menor2 = 0;
    int i;

    // Verificando se a meno  fila de independentes
    VetInd = ((Cliente *)realloc(VetInd, 10 * sizeof(Cliente)));
    for (i = 0; i < 5; i++)
    {
        if (menor1 < VetInd[i].tempoAtend)
        {
            menor1 = i;
        }
    }
    // Verificando se a menor  fila de unicos
    VetUn = ((Cliente *)realloc(VetUn, 10 * sizeof(Cliente)));
    for (i = 0; i < 5; i++)
    {
        if (menor2 < VetUn[i].tempoAtend)
        {
            menor2 = i;
        }
    }

    if (menor1 <= menor2)
    {
        VetInd[(int)menor1] = cliente;
    }
    else
    {
        VetInd[(int)menor2] = cliente;
    }
}

int Ganhadora()
{
    float independente = 0;
    float unicas = 0;
    // Filas independentes
    for (int i = 0; VetInd != NULL; i++)
    {
        for (int j = 0; VetInd[i] != NULL; j++)
        {
            independente += VetInd[i][j].tempoAtend;
        }
    }

    // Filas Unicas
    for (int i = 0; VetUn != NULL; i++)
    {
        for (int j = 0; VetUn[i] != NULL; j++)
        {
            unicas += VetUn[i][j].tempoAtend;
        }
    }

    if (independente > unicas)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int main()
{
    srand((unsigned)time(NULL)); // Inicializa o gerador de números aleatórios
    float RelH = 0;
    while (RelH <= 10.0)
    {
        float NCli = sorteia(); // Sorteia a eventual chegada de cliente novo
        if (NCli <= 0.5)
        {
            // Não chegou cliente novo, então faz nada
        }
        else
        {
            float tempoAtend = 10 * sorteia();
            Cliente cliNovo = {(tempoAtend == 0 ? 1 : tempoAtend)}; // Chegou cliente novo, que requer atendimento de duração aleatória
            // Insere cliNovo nas filas independentes ou fila única
            insereMenorFila(VetInd, VetUn, cliNovo);
            // Atualize os vários vetores com o tempo de 0.1 que passou...

            // Apresente os vetores na tela (formatados) para melhor acompanhamento de seu programa
            printf("Printando Filas Independentes\n");
            for (int i = 0; VetInd != NULL; i++)
            {
                for (int j = 0; VetInd[i] != NULL; j++)
                {
                    printf("%.2f ", VetInd[i][j]);
                }
                printf("\n");
            }

            printf("Printando Filas Unicas\n");
            for (int i = 0; VetUn != NULL; i++)
            {
                for (int j = 0; VetUn[i] != NULL; j++)
                {
                    printf("%.2f ", VetUn[i][j]);
                }
                printf("\n");
            }
        }
        RelH = RelH + 0.1;
    }
    // Informe o tipo de fila ganhadora (o grupo que tiver menos clientes a atender ainda)
    int vencendor = Ganhadora();

    if (vencendor == 1)
    {
        printf("Fila Independente ganhou");
    }
    else if (vencendor == 2)
    {
        printf("Fila Unica ganhou");
    }
}