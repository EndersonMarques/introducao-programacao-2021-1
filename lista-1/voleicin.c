#include <stdio.h>

int main(){

    int alan, bianca, carlos, daniela, erasmo, fernanda, gabriel, helen;

   scanf("%d %d %d %d %d %d %d %d", &alan, &bianca, &carlos, &daniela, &erasmo, &fernanda,&gabriel, &helen);

    if(alan== carlos || alan == erasmo || alan == gabriel){
        printf("Alguem nao esta satisfeito...");
    }
    else if( bianca == alan || bianca == daniela){
        printf("Alguem nao esta satisfeito...");
    }
    else if(gabriel == helen && daniela != carlos){
        printf("Alguem nao esta satisfeito...");
    }
    else if( helen != gabriel && helen != fernanda ){
        printf("Alguem nao esta satisfeito...");
    }
    else if(carlos == erasmo && fernanda != alan){
        printf("Alguem nao esta satisfeito...");
    
    }
    else if (carlos != erasmo && fernanda == alan){
        printf("Alguem nao esta satisfeito...");
    }
    else{
        printf("Conseguimos times suficientes!");
    }


    return 0;

}