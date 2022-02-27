#include <stdio.h>

int main()
{

    int n;
    int i;
    scanf("%d", &n);
    int sequencia[n];
    // Lendo a sequencia
    for (i = 0; i < n; i++)
    {
        scanf("%d", &sequencia[i]);
    }

    // Verificando se a sequencia é valida
    for (i = 0; i < n; i++)
    {
        if (sequencia[i] + sequencia[i + 1] != sequencia[i + 2])
        {
            printf("Sherliro achou o termo %d que deveria estar na posicao %d\n", (sequencia[i] + sequencia[i + 1]), i + 3);
            return 0;
        }
    }
    return 0;
}