#include <stdio.h>

int is_exist( int x, int vetor[], int tam ){
    for(int i=0; i < tam; i++){
        if( x == vetor[i]){
            return 0;
        }
    }
    return 1;
}


int main(){

    int n1, n2, flag, item;
    int i, j, k;
    scanf("%d %d",&n1,&n2);

    int lista1[n1], lista2[1000] = {0}, lista3[1000] = {0};

    for(i=0; i < n1; i++){
        scanf("%d",&lista1[i]);
    }
    flag = n2;
    j = 0;
    
    do{
        scanf("%d",&item);
        if( is_exist( item, lista1, n1)){
            lista2[j] = item;
            flag--;
        }
        else{
            lista2[j] = item;
        }
        j++;
    }
    while(flag);

    // printf("\n\n");
    // printf("Lista 1: ");
    // for(i=0; i < n1; i++){
    //     printf("%d ", lista1[i]);
    // }
    // printf("Lista 2: ");
    // printf("\n");
    // for(i=0; i < j; i++){
    //     printf("%d ", lista2[i]);
    // }

    lista3[0] = lista2[0];
    // printf("\n\n");
    for(i=1; i < j; i++){
        lista3[i] = (lista2[i] * lista2[i-1]) - lista2[i+1];
        if(lista3[i] < 0){
            lista3[i] = lista3[i] * (-1);
        }
    }

    lista3[j] = lista2[j] * lista2[j-1];

    for(i=0; i < j-1; i++){
        for(k=0; k < j-i-1; k++){
            if( lista3[k] > lista3[k+1] ){
                int aux = lista3[k];
                lista3[k] = lista3[k+1];
                lista3[k+1] = aux;
            }
        }
    }

    for(i=0; i < j; i++){
        if( is_exist(lista3[i], lista1, n1) ){
            printf("%d ", lista3[i]);
        }
        else{
            printf("DELETADO ");
        }
    }

    return 0; 
}