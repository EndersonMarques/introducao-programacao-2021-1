#include <stdio.h>

int main(){

    int dia_i, mes_i, ano_i, dia_f, mes_f, ano_f;
    int contador = 0;
    int ano_bi = 0;
    int trinta_um = 0;
    int vinte_oito = 0;

    scanf("%d/%d/%d", &dia_i, &mes_i, &ano_i);
    scanf("%d/%d/%d", &dia_f, &mes_f, &ano_f);

    trinta_um =( ano_f - ano_i) *7;
    vinte_oito = ( ano_f - ano_i) *2;

    for(int j = ano_i; j <= ano_f; j++){

        if( j % 4 == 0 && j %100 != 0){
            ano_bi++;
        }

   }

    while (1)
    {
        if( dia_i > 30){
            dia_i = 1;
            mes_i++;
        }
        if( mes_i > 12){
            dia_i = 1;
            mes_i = 1;
            ano_i++;
        }
        dia_i++;
        contador++;
        if(ano_i == ano_f && mes_f == mes_i && dia_f == dia_i){
            break;
        }

    }

    printf("%d", contador+trinta_um-vinte_oito+ano_bi-3);
    // printf("Contador: %d\n", contador+trinta_um-vinte_oito+ano_bi-3);
    // printf("dias inicias: %d\n", dia_i);
    // printf("mes inicial: %d\n", mes_i);
    // printf("ano inicial: %d\n", ano_i);

    // printf("\nQuantidade de anos Bi: %d \n", ano_bi);
    // printf("\nANOS E 31 DIAS: %d \n", trinta_um);
    


}