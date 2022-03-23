#include <stdio.h>
#include <string.h>

int main()
{  
    char frase[100];
    char letras[] = {'a', 'e', 'i', 'o', 'u'};
   
    int i;
   
    fgets(frase, 100, stdin);
    for(i=0; i < frase[i] != '\0'; i++){
       
        if(frase[i] >= 48 && frase[i] <=53){
            int temp = frase[i] - '0';
            printf("%c", letras[temp-1]);
        }
        else{
            printf("%c", frase[i]);
        }
    }

    return 0;
}
