#include <stdio.h>

int main(){

    int dia_i, mes_i, ano_i, dia_f, mes_f, ano_f;

    scanf("%d/%d/%d", &dia_i, &mes_i, &ano_i);
    scanf("%d/%d/%d", &dia_f, &mes_f, &ano_f);

    int anos = (ano_f - ano_i) * 360;
    int meses;
    if(mes_i >= 12){
        meses = mes_f;
    }
    else{
        meses = mes_f + mes_i;
    }

    int dias = dia_f + dia_i;
    printf("%d", anos + meses+dias);

}