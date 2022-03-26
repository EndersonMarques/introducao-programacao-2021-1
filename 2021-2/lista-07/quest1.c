#include <stdio.h>

int main()
{

    char c = 'a';
    char *pc;
    pc = &c;

    // Letra A)
    printf("Leta A): %p %c\n", &c, c);

    // Letra B)
    printf("Leta B): %c %p\n", *pc, pc);

    // Letra C)
    printf("Leta C): %p\n", &pc);

    // Letra D)
    printf("Leta D): %p %p\n", &(*pc), *(&pc));

    // Letra E)
    /* Os dois endereços são iguais por que, primeiramente o operador '&'
        retorna o endereço de agluma variavel. E quando fazemos '*pc', estamos pedindo
        para que seja mostrado o valor que está armazenado na variavel que o ponteiro esta
        apontando, logo2 se eu faço 'char c = a;', 'char *pc = &c;' e peço para que seja
        printado '*pc', é o mesmo que epdir que seja printado apenas 'c'. Então, quando o
        enunciado pede o '*Endereço do valor guarado*', logo deve-se usar o operador de
        'Endereço, &' do 'Valor guarado, (*pc)', ou seja '&(*pc)'.

        E logo em seguida, quando o enunciado pede o 'Valor Guardado no ENDEREÇO de pc',
        deve-se usar na ordem pedida, o 'VALOR, *(Algum_Ponteiro)' gurdado no'ENDEREÇO, &'
        de pc, ou seja, é pedido que seja feito '*(&pc)'.

        Mas e porque eles são iguais ?,  Simples !!! Eles são iguais pelo simples fato de
        que o VALOR GUARDADO no endereço de pc é o propio Endereço que pc guarda, logo
        *(&pc) é == (igual) pc, que por suas vez também é igual a (&c). E também, porque
        o ENDEREÇO DO VALOR guardado no ENDEREÇO apontando por pc é extamente igual a
        o endereço de c, logo (&c),  que é justamente o endereço que pc guarda !!!
        Sendo assim, as duas formas esntão printando o endereço de c, '&c', ou printando
        o propio pc(Que guarda o enreço de c, '&c')

        logo eles são iguais :D
    */

    return 0;
}