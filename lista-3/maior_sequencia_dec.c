#include <stdio.h>

int main (){

    int caso_teste,seq_tam,contador=0, maior_sequencia =0;
    int i, j, k,l, m ,n;

    scanf("%d",&caso_teste);


    for (i=0; i< caso_teste; i++){
        int lista[120] = {0}, final[120] = {0},lista2[120] = {0};
        scanf("%d", &seq_tam);  

        for (j=0; j< seq_tam; j++){
            scanf("%d", &lista[j]);
        }

        //Encontrar sequencia
        k=0;
        for( j =0; j < seq_tam-1; j++){
            
            if( (lista[j] - lista[j+1]) >= 1 ){
                final[j] = lista[j];
                final[j+1] = lista[j+1];
                contador++;
            }
            
        }
        
        for( j=0; j< seq_tam; j++){
            printf("%d ", final[j]);
        }

        printf("\n");
    }

    return 0;
}