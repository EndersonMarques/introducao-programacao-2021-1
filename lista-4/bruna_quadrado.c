#include <stdio.h>

int main() {
  //Numero da Mtariz Quadrada
  int n;

  //Varivaies Auxliares
  int contador=0, auxiliar1=0, auxiliar2=0, auxiliar3 = 0;

  //Definindo as matrizes
  int matriz[101][101]={0};

  //Interadores para vascular a matriz
  int i, j, x, y;

  //Lendo o Tamanho da Matriz
  scanf("%d", &n);

  //Preenchendo a Matriz
  for(i=0; i < n; i++) {
    for(j=0; j < n; j++){
      scanf("%d", &matriz[i][j]);
    }
  }

  //Pegar o maior numero de 1's em alguma linha 
  for(i=0; i < n; i++) {
    contador = 0;
    for(j=0; j < n; j++){
      if(matriz[i][j]==1){
        while(matriz[i][j] !=0){
          j++;
          contador++;
        }
        j=n;
      }
    }
    // printf("\ni = %d\nContador?: %d\n", i, contador);
    // Salvando o valor do contador
    if(contador >= auxiliar2){
      auxiliar2 = contador;
    }   
  }

  
  contador = 0;
  // auxiliar3 = auxiliar2;
  // printf("\nAux2 = %d\n", auxiliar2);

  //Percorrer a matriz a partir do primeiro 1

  for(int i=0; i <n; i++){
    for(int j=0; j < n; j++){
      auxiliar3 = auxiliar2;

      //Encontra o primeiro 1
      if(matriz[i][j] == 1){
        while(contador != (auxiliar3+1)*(auxiliar3+1)){
          contador = 0;
          for(x = i; x < (i+auxiliar3) && x< n; x++){
            for(y = j; y < (j+auxiliar3) && y < n; y++){
              if(matriz[x][y] == 1){
                contador++;
              }
            }
          }
          auxiliar3--;
        }
        if(contador > auxiliar1){
          auxiliar1 = contador;
        }
      }
    }
  }
  printf("%d", auxiliar1);

  return 0;
}