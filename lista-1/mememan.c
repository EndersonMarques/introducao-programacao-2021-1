#include <stdio.h>

int main(){

    int tempo;

    scanf("%d",&tempo);

    if(tempo < 0){
        printf("Meme man quebrou o tempo! De volta ao transito :(");
    }
    else if(tempo < 62){
        printf("...Ainda no transito...");
    }
    else if(tempo >= 62 && tempo < 3720){
        printf("Lar doce lar");
    }
    else if(tempo >= 3720 && tempo <=3743 ){
        printf("Stonks has been born!");
    }
    else{
        printf("Lar doce lar");
    }


    return 0;

}