#include <stdio.h>

int main(){
    int n;
    int distintas=0, altos= 0;
    int medios = 0, baixos = 0, diferenca = 0;
    int maior, menor;
    int i;

    scanf("%d",&n);

    int vetor[n];
    for(i=0; i < n; i++){
        scanf("%d",&vetor[i]);
    }

    //Verificar quais são alturas distintas
    for(i=0; i < n; i++){
        if(vetor[i] != vetor[i+1]){
            distintas++;
        }
    }

    //Verificar quais são altos
    for(i=0; i < n; i++){
        if ( vetor[i] >=100){
            altos++;
        }
    }

    //Verificar quais são medios
    for(i=0; i < n; i++){
        if ( vetor[i] >=50 && vetor[i] < 100){
            medios++;
        }
    }

    //Verificar quais são pequenos
    for(i=0; i < n; i++){
        if ( vetor[i] < 50){
            baixos++;
        }
    }

    //Ver qual é o maior
    maior = 0;
    for(i=0; i < n; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
        }
    }

    //Ver qual é o menor
    menor = maior;
    for(i=0; i < n; i++){
        if(vetor[i] < menor){
            menor = vetor[i];
        }
    }

    diferenca = maior - menor;

    printf("%d\n", distintas);
    printf("%d\n", altos);
    printf("%d\n", medios);
    printf("%d\n", baixos);
    printf("%d", diferenca);

}