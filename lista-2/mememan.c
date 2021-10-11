#include <stdio.h>


int main(){

    int tempo_inicial, tempo_abando;
    int cont = 0;
    
    scanf("%d %d", &tempo_inicial, &tempo_abando);

    
    while(tempo_inicial != 0){
        
        // printf("Tempo Inicial: %d\n", tempo_inicial);
        cont++;
        if(tempo_inicial == 0){
            break;
        }
        else if( tempo_inicial % 13 == 0 ){
            tempo_inicial -= 60;
        }
        else if( tempo_inicial % 60 == 0) {
            tempo_inicial += 30;
        }
        else if( cont > (tempo_abando*60) ){
            printf("fui pedir comida mesmo\n");
            return 0;
        }
        tempo_inicial++;
    }
    printf("%d\n", cont);

    return 0;
}