#include <stdio.h>


int main(){

    int numero;
    int contador = 0;
    int novo_numero;
    int divisor, max_cont = 0;
    scanf("%d", &numero);
    novo_numero = numero;

    for(int i = 2; i <= numero; i++){

        while( novo_numero % i == 0){
            
            if( novo_numero % i == 0){
                contador++;
                novo_numero = novo_numero /i;
            }

        }
        if( contador > max_cont) {
            max_cont = contador;
            divisor = i;
        }
        contador = 0;

    }
    printf("mostFrequent: %d frequency: %d\n", divisor, max_cont);
    return 0;
}