#include <stdio.h>


int main(){

    int numero;

    scanf("%d", &numero);
    for (int i =2; numero > 1; i++){
        while(numero % i ==0){
            printf("%d ", i);
            numero =numero /i;
        }      
    }

    return 0;
}