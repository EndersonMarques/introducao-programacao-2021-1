#include <stdio.h>

int main(){

    int op = 0;
    double banco[2][100] = {0};
    double valor=0, resultado, credito=0, debito=0;

    int i = 0, j = 0;
    while(op == 1 || op == 0){
        scanf("%d", &op);
        if(op == -1){
            break;
        }
        else{
            scanf("%lf", &valor);
            banco[i][j] = valor;
        }
        i++;
        j++;
        if( op == 0){
            debito += valor;
        }
        else if(op == 1){
            credito += valor;
        }
    }

    resultado = credito - debito;

    printf("Creditos: R$ %.2lf\n", credito);
    printf("Debitos: R$ %.2lf\n", debito);
    printf("Saldo: R$ %.2lf\n", resultado);
    return 0;
}