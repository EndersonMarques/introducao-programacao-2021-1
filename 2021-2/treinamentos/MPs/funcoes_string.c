#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{

    // Encontrar
    char palavra[30] = "OI YASMIM BELEZAAAA [77-18-]";
    // Sem usar função
    for (int i = 0; i < strlen(palavra); i++)
    {
        if (palavra[i] == '[')
        {
            // Faz algo
        }
    }

    // Usando função
    char *Pont_palavra;
    Pont_palavra = strstr(palavra, "YASMIM");
    if (Pont_palavra != NULL)
    {
        printf("%c\n", *(Pont_palavra));
    }
    else
    {
        printf("Esta string nao exsite na palavra :/\n");
    }

    // Transformando
    char numero[4] = "157";
    int tam = strlen(numero);
    int exp = tam - 1;
    int valor = 0;
    for (int i = 0; i < tam; i++)
    {
        valor += (numero[i] - '0') * pow(10, exp);
        exp--;
    }
    printf("%d\n", valor);

    // Maiusculo e minuscuo
    // touuper transforma *1* caracter em maisuclo
    // tolower transforma *1* caracter em minusculo
    char frase[6] = "AeIou";
    for (int i = 0; i < strlen(frase); i++)
    {
        if (i % 2 == 0)
        {
            frase[i] = tolower(frase[i]);
        }
        else
        {
            frase[i] = toupper(frase[i]);
        }
    }
    printf("%s\n", frase);
    return 0;
}