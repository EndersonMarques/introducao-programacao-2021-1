#include <stdio.h>

int main(){

    int vetor[1000000] = {0};
    int n;
    int tam, i, j;
    int c= 0,k;


    tam = 0;
    while( scanf("%d", &n) != EOF ){
        vetor[tam] = n;
        tam++;
    }
    
    //Bouble Sort
    for( i = 0; i < tam-1; i++ ){
        for( j = 0; j < tam-i-1; j++ ){
            if( vetor[j] > vetor[j+1]){
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
    //Pegar o unico não repetido
    for(i=0; i < tam; i+=2){
        if( vetor[i] != vetor[i+1]){
            c++;
            k=i;
            i--;

            // printf("\n%d", vetor[k]);
        }
    }


    for(i=0; i < tam; i++){
        printf("%d ", vetor[i]);
    }

    if( c == 0 ){
        printf("\n0");
    }
    else{
        printf("\n%d", vetor[k]);
    }
    

}