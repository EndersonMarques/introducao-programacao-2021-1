#include <stdio.h>

int main()
{
    int n, m;
    int i, j;
    scanf("%d%d", &n, &m);
    
    int matriz[n][m];
    
    for(i = 0; i < n; i++){
        for(j=0; j< m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    
    printf("\n\n");
    
    int matriz_transporta[m][n];
    
    for(i = 0; i < m; i++){
        for(j=0; j< n; j++){
            matriz_transporta[i][j] = matriz[j][i];
        }
    }
    
    for(i = 0; i < m; i++){
        for(j=0; j< n; j++){
            printf("%d ", matriz_transporta[i][j]);
        }
        printf("\n");
    }

    return 0;
}
