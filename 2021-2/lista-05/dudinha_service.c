#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    char nome[40];
    int peso;
    float preco;
    int serial_number;
} Produto;
typedef struct center
{
    double pos_x;
    double pos_y;
} Center;

int existe(int x, int *array, int tam)
{
    // int tam = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < tam; i++)
    {
        if (x == array[i])
        {
            return 1;
        }
    }
    return 0;
}
int main()
{

    int n, p;
    int i, j, k = 0;
    scanf("%d %d", &n, &p);
    // Criando os vetores de structs e serial number
    int serial_array[n];
    Center centros[p];
    Produto produtos[n];
    for (i = 0; i < p; i++)
    {
        scanf("%lf %lf", &centros[i].pos_x, &centros[i].pos_y);
    }

    // lendo os N prudtos
    for (i = 0; i < n; i++)
    {
        scanf(" %s %d %f", produtos[i].nome, &produtos[i].peso, &produtos[i].preco);
    }

    // ordenando em ordem alfabetica
    for (j = 0; j < n - 1; j++)
    {
        for (i = 0; i < n - 1; i++)
        {
            if (strcmp(produtos[i].nome, produtos[i + 1].nome) > 0)
            {
                Produto aux = produtos[i];
                produtos[i] = produtos[i + 1];
                produtos[i + 1] = aux;
            }
        }
    }

    // iniciando serial array
    for (i = 0; i < n; i++)
    {
        serial_array[i] = 999;
    }

    // calculando o serial number
    for (i = 0; i < n; i++)
    {
        int serial_temp;
        int preco_tem = ceil(produtos[i].preco);
        serial_temp = (preco_tem + i + produtos[i].peso + k) % n;
        if (!existe(serial_temp, serial_array, n))
        {
            serial_array[i] = serial_temp;
            produtos[i].serial_number = serial_temp;
            // printf("nao xeiste %d\n", serial_temp);
        }
        else
        {
            // printf("ja xeiste %d\n", serial_temp);
            i--;
            k++;
        }
    }

    // pegando o serial medindo a distancia e usando
    int serial;
    double x, y;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &serial);

        // encontra produto pelo serial
        for (j = 0; j < n; j++)
        {
            if (produtos[j].serial == serial)
            {
                break;
            }
        }
        // scanf("%lf %lf", &x, &y);

        int distancia = 0;
        // distancia = (pow(x - centros[j].))
    }
    // for (j = 0; j < n; j++)
    // {
    //     printf("Nome: %s || Seiral: %d\n", produtos[j].nome, produtos[j].serial_number);
    // }
}