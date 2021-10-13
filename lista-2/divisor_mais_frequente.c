#include <stdio.h>


int main(){

    int numero;
    int contador = 0;
    int frequencia = 0;
    int contador_interador = 1;
    int novo_numero;
    int novo_interador = 10;
    scanf("%d", &numero);
    novo_numero = numero;

    for(int i = 2; i <= numero; i++){

        while( novo_numero % i == 0){
            printf("%d ", i);
            novo_numero = novo_numero /i;
            contador++;
    
            if(novo_interador > i){
                novo_interador = i;
                contador++;
            }

            if( contador > frequencia){
                frequencia = contador;
            }

        }
    }
    printf("\n%d\n", contador_interador);

    return 0;
}