#include <stdio.h>

int main()
{
    int n;
    int i, j;
    scanf("%d", &n);
    
    if(n == 0){
        printf("Vazia");
        return 0;
    }
    
    int matriz1[n][n], matriz2[n][n];
    
    for(i=0; i < n; i++){
        for(j=0; j <n; j++){
            scanf("%d", &matriz1[i][j]);
        }
    }
    for(i=0; i < n; i++){
        for(j=0; j <n; j++){
            scanf("%d", &matriz2[i][j]);
        }
    }
    
    //Matriz Resultante
    for(i=0; i < n; i++){
        for(j=0; j <n; j++){
            printf("%d\n", (matriz1[i][j]+matriz2[i][j]) );
        }
    }

    return 0;
}
