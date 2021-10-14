#include <stdio.h>

int eh_primo(int x){ 
    if(x == 1){
        return 0;
    }
    
    for(int i=2; i< x; i++){
        if( x % i==0 ){
            return 0;
        }
    }
    return 1;
}

int proxi_primo(int x){

    if ( eh_primo(x)){
        return x;
    }

    for(int i=x; i< x*2; i++){
        if(eh_primo(i)){
            return i;
        }
    }
}

int ant_primo(int x){

    if ( eh_primo(x)){
        return x;
    }

    for(int i=x; i> 2; i--){
        if(eh_primo(i)){
            return i;
        }
        else{
            continue;
        }
    }
}

int main(){
    int anterior, sucessor;
    float operacao;
    int a, b;
    int contador =0;

    scanf("%d %d", &a, &b);

    while(a <= b){
        if(eh_primo(a)){
            anterior = ant_primo(a-1);
            sucessor = proxi_primo(a+1);

            operacao = ((anterior + 0.0)+ (sucessor + 0.0))/2;
            if( operacao == a ){
                contador++;
            }
        }
        a++;
    }
    
    printf("%d\n", contador);

    return 0;
}