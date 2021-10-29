#include <stdio.h>
#include <string.h>

int main(){

    int n, diagonal = 0;
    int i, j, k;
    int letra = 0;
    //Ler a entrada N
    printf("\nDigite a dimensão da matriz: ");
    scanf("%d", &n);

    //Criando a Matriz de strings
    char matriz[n][n][31];
    char resultado[31] = "";
    
    printf("\nDigite agora as %d strings que comporão a matriz %d x %d: \n", n*n, n, n);

    //Lendo Matriz
    for(i=0; i< n; i++){
        for ( j = 0; j < n; j++){
            scanf(" %s",matriz[i][j]);
        }
        
    }

    //Casos que podem dar errado
    for(i=0; i<n; i++){
       for(j=0; j <n; j++){
           //Se está na diagonal principal
           if(i==j){
               //Se o teu tamanho não é igual ao sucesso de sua posição
               int tam = strlen(matriz[i][j]);
               if(tam == (i+j)  ){
                   printf("Matriz não encontra na propriedade :( \n");
                   return 0;
               }
               //Fora da diagonal principal
            //    else{
            //        if( strcmp(matriz[i][j],toupper(matriz[i][j])) ){
            //             printf("Matriz não encontra na propriedade :( \n");
            //             return 0;
            //        }
            //    }
           }
       }
    }

    int soma;

    //CAso tenha tido sucesso
    for(i=0; i<n; i++){
       for(j=0; j <n; j++){
            if(i== j){
                strcat(resultado, matriz[i][j]);
            }
            else{
                int tam = strlen(matriz[i][j]);
                for(k=0; k<tam; k++){
                    letra += matriz[i][j][k] - '0';
                }
                strcat(resultado, matriz[i][j]);
            }
       }
    }
    printf("Sua senha é ");
    puts(resultado);

    return 0;
}