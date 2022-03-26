#include <stdio.h>
#include <string.h>
int main()
{
    char str[50];     // String
    char str_inv[50]; // String invertida
    char *ptr_str = str;
    char *ptr_inv = str_inv;
    int i = -1;
    scanf("%s", str);
    // [...]

    while (*(ptr_str) != '\0')
    {
        ptr_str++;
        i--;
    }
    while (i)
    {
        *(ptr_inv) = *(ptr_str - 1);
        ptr_str--;
        ptr_inv++;
        i++;
    }

    printf(" O inverso da string : %s\n\n", str_inv);
    return 0;
}

/* Letra B - Não é necessário o '&' no scanf de uma string e de
    nenhum vetor, porque o nome de um vetor qualquer, já é um
    ponteiro para a primeira posição do mesmo vetor !!!
*/
