#include <stdio.h>
#include <string.h>

int main()
{
    //carla
    //clraa

    char palavra[10];
    scanf("%s", palavra);
    int i;
    int tam = strlen(palavra);
    int p = tam-2;
    for(i=1; i < tam/2 +1; i++){
        char aux = palavra[i];
        palavra[i] = palavra[p];
        palavra[p] = aux;
        p--;
    }

    printf("%s", palavra);

    return 0;
}