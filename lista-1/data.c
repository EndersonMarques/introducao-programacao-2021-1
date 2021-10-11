#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int dia, mes, ano;
    
    scanf("%d%d%d", &dia, &mes, &ano);
    
    if(ano<1900 || ano > 2100){
        printf("invalida");
        // printf("1");
    }
    else{
    
        if(ano % 4 == 0 && ano != 2100){
            if(( mes == 1 || mes == 3 || mes ==5 ||mes == 7 || mes == 8 || mes == 10 ||mes == 12) && dia <= 31){
                printf("valida");
            }
            else if( ( mes == 4 || mes ==6 ||mes == 9 || mes == 8 || mes == 11) && dia <= 30 ){
                printf("valida");
            }
            else if( mes == 2 && dia <= 29){
                printf("valida");
            }
            else{
                printf("invalida");
                // printf("\n1");
            }
        }
        else if (( mes == 1 || mes == 3 || mes ==5 ||mes == 7 || mes == 8 || mes == 10 ||mes == 12) && dia <= 31){
            printf("valida");
        }
        else if( ( mes == 4 || mes ==6 ||mes == 9 || mes == 8 || mes == 11) && dia <= 30 ){
                printf("valida");
        }
        else if( mes == 2 && dia <= 28){
                printf("valida");
                // printf("\n2");
        }
        else{
            printf("invalida");
            // printf("\n3");
        }

    }
    
	return 0;
}