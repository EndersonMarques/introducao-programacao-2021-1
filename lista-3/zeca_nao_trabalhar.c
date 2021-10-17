#include <stdio.h>

int main(){

    int money, amigos;
    int i, j, k, c=0, soma;
    scanf("%d %d",&money, &amigos);
    int valores[amigos];

    for(i=0; i<amigos; i++){
        scanf("%d",&valores[i]);
    }

    for(i=0; i < amigos-2; i++){
        for(j=1; j< amigos-1; j++){
            for(k=2; k< amigos; k++){
                // printf("i = %d, j = %d, k = %d", valores[i], valores[j], valores[k]);
                soma = valores[i] + valores[j] + valores[k];
                // printf("Soma: %d\n", soma);
                if( money == soma){
                    c++;
                }
            }
        }

    }

    if( c == 0 ){
        printf("Zeca vai ter que trabalhar.");
    }
    else{
        printf("Zeca nao vai ter que trabalhar!");
    }

    // printf("\n%d\n", c);

    return 0;
}