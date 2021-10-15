#include <stdio.h>

int main(){

    int n;
    int i, j;
    int c = 0;

    scanf("%d",&n);
    int vetor_1[n], vetor_2[n], result[2*n];

    for(int i=0; i < n; i++){
        scanf("%d",&vetor_1[i]);
    }

    //Vetor recebe o valor igual
    for(i = 0; i < n; i++){
        vetor_2[i] = vetor_1[i];
    }

    //Bouble Sort
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(vetor_2[j] > vetor_2[j+1]){
                int aux = vetor_2[j];
                vetor_2[j] = vetor_2[j+1];
                vetor_2[j+1] = aux;
            }
        }
    }

    
    //Verificar quantops casos são iguais
    for(i = 0; i < n; i++){
        if( vetor_1[i] == vetor_2[i]){
            c++;
        }
    }
    printf("%d\n", c);
    //Verifica quais casos são iguais
    for(i = 0; i < n; i++){
        if( vetor_1[i] == vetor_2[i]){
            c++;
            printf("%d %d\n", vetor_2[i], i+1);
        }
    }
    return 0;
}