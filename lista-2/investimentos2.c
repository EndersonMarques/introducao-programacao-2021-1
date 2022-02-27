#include <stdio.h>


int main(){

    int a, c;

    scanf("%d %d", &a, &c);
    while (c)
    {
        if( 30 % (a+1) == 0  ){
            printf("Curvou\n");
        }
        else{
            printf("Pedro se cagou todo e foi pego.");
            break;
        }
        a++;
        c--;
    }
    
    return 0;
}