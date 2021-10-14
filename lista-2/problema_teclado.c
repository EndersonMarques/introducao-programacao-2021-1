#include <stdio.h>
#include <math.h>


int eh_primo(int x){ 
    if(x == 1){
        return 0;
    }
    
    for(int i=2; i< x; i++){
        if( x % i==0 ){
            return 0;
        }
    }
    return 1;
}

int main(){

    int n, k;
    long long int sequencias, numeros;
    int qtd_numeros =0, qtd_letras = 0;
    char letras;
    scanf("%d", &n);

    while(n){
        scanf(" %c", &letras);
        if( letras >= 48 && letras <= 57 ){
            qtd_numeros++;
        }
        else{
            qtd_letras++;
        }
        n--;
    }

    scanf("%d", &k);

    for(int j = 1; j <= k; j++){
        printf("Tamanho %d\n", j);
        if (!(eh_primo(j))){
            sequencias = pow(qtd_letras, j);
            printf("Sequencias: %lld, Numeros: 0\n", sequencias);
        }
        else{
            numeros = pow(qtd_numeros, j);
            printf("Sequencias: 0, Numeros: %lld\n", numeros);
        }
    }
    return 0;
}