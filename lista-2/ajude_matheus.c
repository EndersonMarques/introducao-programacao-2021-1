#include <stdio.h>

int main(){

    int reais, x0, x1, y0,y1, z0,z1;
    int i, j, k;
    int palheta, pedal;
    int cont = 0;

    scanf("%d", &reais);

    scanf("%d %d %d %d %d %d", &x0, &x1, &y0, &y1, &z0, &z1);

    for(i = x0; i < x1; i++){

        for(j = y0; j < y1; j++){

            for(k = z0; k < z1; k++){

                palheta = x1;
                pedal = z1;


                if(reais == (i + j +k) ){
                    if(i <= x0 && k<=z0 ){
                        printf("\nS");
                        printf("\n%d %d %d", i, j , k);
                        cont++;
                    }
                    else{
                        continue;
                    }
                }
            }
        }
    }

    if(cont == 0) {
        printf("N");
    }


    return 0;
}