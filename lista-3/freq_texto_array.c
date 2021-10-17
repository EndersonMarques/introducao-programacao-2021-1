#include <stdio.h>
#include <string.h>

int main(){
    char text[1000], text_2[1000], aux_char, aux_int; 
    int count = 0;
    int i, j, c = 0;


    while(scanf("%c", &text[count]) != EOF){
        text_2[count] = text[count];
        count++;
    }

    char text_ordenado[count+1];
    int freq_text[count+1];
    for(i = 0; i < count; i++){
        for(j = 0; j <count; j++){
            if( text[i] == text_2[j] ){
                text_ordenado[i] = text[i];
                c++;
            }
        }
        freq_text[i] = c;
        c=0;
    }

    //Ordenar
    for(i = 0; i < count-1; i++){
        for(j =0; j < count-i-1; j++){
            if(text_ordenado[j] < text_ordenado[j+1]){
                //Ordenando Array de Texto
                aux_char = text_ordenado[j];
                text_ordenado[j] = text_ordenado[j+1];
                text_ordenado[j+1] = aux_char;

                //Ordenando Array de Frequencia
                aux_int = freq_text[j];
                freq_text[j] = freq_text[j+1];
                freq_text[j+1] = aux_int;
            }
        }
    }


    for(i = 0; i < count; i++){
        if( text_ordenado[i]  != text_ordenado[i+1]){
            printf("%c %d\n", text_ordenado[i], freq_text[i]);
        }
    }

  
  
}