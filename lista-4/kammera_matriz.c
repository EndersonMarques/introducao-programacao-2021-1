#include <stdio.h>
#include <math.h>

int main(){

    int linhas, colunas;
    double razao, i_coluna, vet_razoes[12]={1}, matriz[12][12] = {0};
    int i, j;

    scanf("%d %d",&linhas, &colunas);

    //Ler a matriz
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            scanf("%lf", &matriz[i][j]);
        }
    }

    //Percorrer a matriz até achar o primeiro numero corrompido
    for(i=0; i<linhas; i++){
        i_coluna =0;
        for(j=0; j<colunas; j++){
            //Verifica se o numero da linha é -1 e vê se o proximo não é
            if(matriz[i][j] != -1 && matriz[i][j] != 1){
                i_coluna = j;
                //Encontra a razão e armazena em vet_razoes
                razao = pow( matriz[i][j] , 1/i_coluna);
                // printf("%lf ", razao);
                vet_razoes[i] = razao;
                break;
            }
        } 
    }

    //So tendo certeza que nenhma razao é 0, e substituindo por 1
    for(i=0; i < linhas; i++){
        if(vet_razoes[i] ==0){
            vet_razoes[i] = 1;
        }
    }
    
    for(i=0; i<linhas; i++){
        i_coluna =0;
        for(j=0; j<colunas; j++){
            if(matriz[i][j] == -1){
                i_coluna = j;
                double recuperado = pow(vet_razoes[i], i_coluna);
                matriz[i][j] = recuperado;
            }
        }
    }

    for(i=0; i<linhas; i++){
        for(j=0; j < colunas; j++){
            if(j+1 != colunas){
                printf("%.0lf ", matriz[i][j]);
            }
            else{
                printf("%.0lf", matriz[i][j]);
            }     
        }
        printf("\n");
    }

    return 0;
}