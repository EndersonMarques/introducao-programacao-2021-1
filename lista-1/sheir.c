#include <stdio.h>

int main(){

    int ID1, ID2, ID3, ID4, ID5;
    int v1, v2, v3, v4, v5;
    int P1, P2, P3, P4,P5;
    int PF;
    scanf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d", &ID1, &P1, &ID2, &P2, &ID3, &P3, &ID4, &P4, &ID5 ,&P5, &PF);

    if( (ID1 == ID2 || ID1 == ID3 || ID1 == ID4 || 
       ID1 == ID5) && (ID2 == ID3 || ID2 == ID4 || 
       ID2 == ID5) && (ID3 == ID4 || ID3 == ID5 )&&
       (ID4 == ID5)){
            printf("UEPAAA TEMOS UM RATINHO\n");
            return 0;
    }

    if (ID1 % 2 == 0 && ( ID1 %3 ==0 || ID1 % 5 == 0 || ID1 % 7 == 0))
    {
        P1 = P1 *2;
        v1 = (ID1 * P1);
    }
    else if( (ID1 * P1) % 2 != 0 && ((ID1 * P1) % 11 == 0 || (ID1 * P1) % 13 == 0 || (ID1 * P1) % 17 == 0 || (ID1 * P1) % 19 == 0) )
    {
        v1 = (ID1 * P1)/2;
    }
    else if(ID1 % 2 == 0 && ID1 % 17 == 0 )
    {
        v1 = 0;
    }
    else{
        v1 = (ID1 * P1);
    }
    // ---------------------------------------------------
    if (ID2 % 2 == 0 && ( ID2 %3 ==0 || ID2 % 5 == 0 || ID2 % 7 == 0))
    {
        P2 = P2 *2;
        v2 = (ID2 * P2);
    }
    else if( (ID2 * P2) % 2 != 0 && ((ID2 * P2) % 11 == 0 || (ID2 * P2) % 13 == 0 || (ID2 * P2) % 17 == 0 || (ID2 * P2) % 19 == 0) )
    {
        v2 = (ID2 * P2)/2;
    }
    else if(ID2 % 2 == 0 && ID2 % 17 == 0 )
    {
        v2 = 0;
    }
    else{
        v2 = (ID2 * P2);
    }
    // ---------------------------------------------------
    if (ID3 % 2 == 0 && ( ID3 %3 ==0 || ID3 % 5 == 0 || ID3 % 7 == 0))
    {
        P3 = P3 *2;
        v3 = (ID3 * P3);
    }
    else if( (ID3 * P3) % 2 != 0 && ((ID3 * P3) % 11 == 0 ||(ID3 * P3) % 13 == 0 || (ID3 * P3) % 17 == 0 || (ID3 * P3) % 19 == 0) )
    {
        v3 = (ID3 * P3)/2;
    }
    else if(ID3 % 2 == 0 && ID3 % 17 == 0 )
    {
        v3 = 0;
    }
    else{
        v3 = (ID3 * P3);
    }
    // ---------------------------------------------------
    if (ID4 % 2 == 0 && ( ID4 %3 ==0 || ID4 % 5 == 0 || ID4 % 7 == 0))
    {
        P4 = P4 *2;
        v4 = (ID4 * P4);
    }
    else if( (ID4 * P4) % 2 != 0 && ((ID4 * P4) % 11 == 0 || (ID4 * P4) % 13 == 0 || (ID4 * P4) % 17 == 0 || (ID4 * P4) % 19 == 0) )
    {
        v4 = (ID4 * P4)/2;
    }
    else if(ID4 % 2 == 0 && ID4 % 17 == 0 )
    {
        v4 = 0;
    }
    else{
        v4 = (ID4 * P4);
    }

    // ---------------------------------------------------
    if (ID5 % 2 == 0 && ( ID5 %3 ==0 || ID5 % 5 == 0 || ID5 % 7 == 0))
    {
        P5 = P5 *2;
        v5 = (ID5 * P5);
    }
    else if( (ID5 * P5) % 2 != 0 && ((ID5 * P5) % 11 == 0 || (ID5 * P5) % 13 == 0 || (ID5 * P5) % 17 == 0 || (ID5 * P5) % 19 == 0) )
    {
        v5 = (ID5 * P5)/2;
    }
    else if(ID5 % 2 == 0 && ID5 % 17 == 0 )
    {
        v5 = 0;
    }
    else{
        v5 = (ID5 * P5);
    }

    int soma = v1 + v2 + v3 + v4 + v5;
    // printf("Soma: %d", soma);

    if( soma != PF){
        printf("UEPAAA TEMOS UM RATINHO");
    }
    else{
        printf("barra limpa, khan");
    }

}