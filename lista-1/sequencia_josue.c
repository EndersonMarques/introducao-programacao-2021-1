#include <stdio.h>

int main(){

    char primieraLetra, segundaLetra, terceiraLetra, aux;
    int alfa[6];

    scanf("%c %c %c", &primieraLetra, &segundaLetra, &terceiraLetra);

    alfa[0]=primieraLetra;
    alfa[1]=segundaLetra;
    alfa[2]=terceiraLetra;


    //Bouble Sort
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++)
        {
            if(alfa[j] > alfa[j+1]){
                aux = alfa[j];
                alfa[j]= alfa[j+1];
                alfa[j+1]= aux;
            }
        }
    }

    primieraLetra = alfa[0];
    segundaLetra = alfa[1];
    terceiraLetra = alfa[2];

    // printf("%c %c %c\n", primieraLetra, segundaLetra, terceiraLetra);
    // printf("%d %d %d\n", primieraLetra, segundaLetra, terceiraLetra);

    if( (primieraLetra < 65 || primieraLetra >90 || segundaLetra < 65 || segundaLetra >90 || terceiraLetra < 65 || terceiraLetra >90)  )
    {
        printf("Etiquetas erradas!");
    }
    else if( (((primieraLetra +1) == segundaLetra)  && ((segundaLetra +1) == terceiraLetra)))
    {
        if (primieraLetra == 65 || primieraLetra == 69 || primieraLetra == 73 || primieraLetra == 79 || primieraLetra == 85 ||
            segundaLetra == 65 || segundaLetra == 69 || segundaLetra == 73 || segundaLetra == 79 || segundaLetra == 85 ||
            terceiraLetra == 65 || terceiraLetra == 69 || terceiraLetra == 73 || terceiraLetra == 79 || terceiraLetra == 85)
        {
            printf("Sequência quase perfeita.");
        }
        else
        {
            printf("Sequência perfeita.");
        }
    }

    else if( ((primieraLetra +2) == segundaLetra)  && ((segundaLetra +2) == terceiraLetra) )
    {
        if (primieraLetra == 65 || primieraLetra == 69 || primieraLetra == 73 || primieraLetra == 79 || primieraLetra == 85 ||
            segundaLetra == 65 || segundaLetra == 69 || segundaLetra == 73 || segundaLetra == 79 || segundaLetra == 85 ||
            terceiraLetra == 65 || terceiraLetra == 69 || terceiraLetra == 73 || terceiraLetra == 79 || terceiraLetra == 85)
        {
            printf("Bissequência quase perfeita.");
        }
        else
        {
            printf("Bissequência perfeita.");
        }
    }

    else if( ((primieraLetra +3) == segundaLetra)  && ((segundaLetra +3) == terceiraLetra) )
    {
        if (primieraLetra == 65 || primieraLetra == 69 || primieraLetra == 73 || primieraLetra == 79 || primieraLetra == 85 ||
            segundaLetra == 65 || segundaLetra == 69 || segundaLetra == 73 || segundaLetra == 79 || segundaLetra == 85 ||
            terceiraLetra == 65 || terceiraLetra == 69 || terceiraLetra == 73 || terceiraLetra == 79 || terceiraLetra == 85)
        {
            printf("Trissequência quase perfeita.");
        }
        else
        {
            printf("Trissequência perfeita.");
        }
    }

    else{
        printf("Só umas letras ai...");
    }
    return 0;
}