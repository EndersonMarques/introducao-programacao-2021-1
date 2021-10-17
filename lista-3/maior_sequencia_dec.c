#include <stdio.h>

int main(){

    int caso_teste, tam_seq, valores[100] = {0};
    int i,j,k,l, m;

    scanf("%d", &caso_teste);

    for (i=0; i<caso_teste; i++){

        scanf("%d", &tam_seq);
        for(j = 0; j < tam_seq; j++){
            scanf("%d", &valores[j]);
        }

        for(k=0; k < tam_seq; k++){
            if( valores[k] > (valores[k+1]) && k< tam_seq-1){
                printf("%d ", valores[k]);
                m = k;
            }
            else if(valores[m] > (valores[m+1]) && m< tam_seq){
                printf("%d ", valores[m+1]);
            }
            else if( valores[k] < (valores[k+1] && k >0)){
                break;
            }
        }
         printf("\n");

    }


    return 0;
}