#include <stdio.h>


int main(){

    int pontos, x,y,z;
    
    scanf("%d%d%d%d",&pontos, &x, &y, &z);

    if((x+y+z) <= pontos){
        printf("3");
    }
    else if((x+y) <= pontos || (x+z) <= pontos || (y+z) <= pontos){
        printf("2");
    }
    else if( x <=pontos || y <=pontos || z <= pontos ) {
        printf("1");
    }
    else{
        printf("0");
    }


    return 0;

}