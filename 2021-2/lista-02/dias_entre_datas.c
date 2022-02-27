#include <stdio.h>
main()
{
    int anoi = 0, anof = 0, quantDias = 0, diai = 0, diaf = 0;
    int mesi = 0, mesf = 0, anopro = 0, mespro = 0;

    // printf("Digite o ano inicial -> ");
    scanf("%d/%d/%d", &diai, &mesi, &anoi);
    getchar();
    // printf("Digite o ano final -> ");
    scanf("%d/%d/%d", &diaf, &mesf, &anof);
    getchar();
    anopro = anoi + 1;

    if (anoi != anof)
    { // ano inical e final diferentes
        // avaliar os anos intermerdiarios
        //  que possuem a quantidade completa de dias
        while (anopro < anof)
        {
            if (anopro % 400 == 0)
                quantDias = quantDias + 366;
            else if (anopro % 100 != 0 && anopro % 4 == 0)
                quantDias = quantDias + 366;
            else
                quantDias = quantDias + 365;
            // printf("dias %d + ", quantDias);// impress�o de teste
            anopro++;
        }
        // para ano inicial diferente de ano final.
        // Calculo no ano inicial
        mespro = mesi;
        while (mespro <= 12)
        {
            if (mespro == mesi)
            { // verifica��o do m�s inicial, precisa descontar a quantidade de dias corridos
                if (mesi <= 7 && mesi % 2 == 1)
                    quantDias += 31 - (diai - 1);
                // verficande de janeiro a julho
                else if (mesi <= 7 && mesi % 2 == 0 && mesi != 2)
                    quantDias += 30 - (diai - 1);
                else if (mesi == 2)
                {
                    if (anoi % 400 == 0)
                        quantDias = quantDias + 29 - (diai - 1); // C espress�o normal
                    else if (anoi % 100 != 0 && anoi % 4 == 0)
                        quantDias += 29 - (diai - 1); // C reduzido
                    else
                        quantDias += 28 - (diai - 1);
                } // verificando de agosto a dezembro
                else if (mesi > 7 && mesi % 2 == 0)
                    quantDias += 31 - (diai - 1);
                else if (mesi > 7 && mesi % 2 == 1)
                    quantDias += 30 - (diai - 1);
            }
            else
            { // verfica��o de m�s diferente do m�s inical
                // verficande de janeiro a julho
                if (mespro <= 7 && mespro % 2 == 1)
                    quantDias += 31; // C reduzido
                else if (mespro <= 7 && mespro % 2 == 0 && mespro != 2)
                    quantDias += 30;
                else if (mespro == 2)
                {
                    if (anoi % 400 == 0)
                        quantDias = quantDias + 29; // Espress�o normal
                    else if (anoi % 100 != 0 && anoi % 4 == 0)
                        quantDias += 29; // C reduzido
                    else
                        quantDias += 28;
                } // verificando de agosto a dezembro
                else if (mespro > 7 && mespro % 2 == 0)
                    quantDias += 31;
                else if (mespro > 7 && mespro % 2 == 1)
                    quantDias += 30;
            }

            mespro++;
        }
        // printf("dias %d + ", quantDias);// impress�o de teste
        // Calculo ano final
        mespro = mesf;
        while (mespro >= 1)
        {
            if (mespro == mesf)
            { // verifica��o do m�s final, s� conta a quantidade de dias corridos
                quantDias += diaf;
            }
            else
            { // verfica��o de m�s diferente do m�s final
                if (mespro <= 7 && mespro % 2 == 1)
                    quantDias += 31; // janeiro a julho
                else if (mespro <= 7 && mespro % 2 == 0 && mespro != 2)
                    quantDias += 30;
                else if (mespro == 2)
                {
                    if (anof % 400 == 0)
                        quantDias += 29;
                    else if (anof % 100 != 0 && anof % 4 == 0)
                        quantDias += 29;
                    else
                        quantDias += 28;
                } // agosto a dezembro
                else if (mespro > 7 && mespro % 2 == 0)
                    quantDias += 31;
                else if (mespro > 7 && mespro % 2 == 1)
                    quantDias += 30;
            }
            mespro--;
        }
        //_________________________________________________________________________________________
    }
    else
    { // para ano inicial e ano final iguais
        mespro = mesi;
        while (mespro < mesf)
        {
            if (mespro == mesi)
            { // verifica��o do m�s inicial, precisa descontar a quantidade de dias corridos
                if (mesi <= 7 && mesi % 2 == 1)
                    quantDias += 31 - (diai - 1);
                // verficande de janeiro a julho
                else if (mesi <= 7 && mesi % 2 == 0 && mesi != 2)
                    quantDias += 30 - (diai - 1);
                else if (mesi == 2)
                {
                    if (anoi % 400 == 0)
                        quantDias = quantDias + 29 - (diai - 1); // C espress�o normal
                    else if (anoi % 100 != 0 && anoi % 4 == 0)
                        quantDias += 29 - (diai - 1); // C reduzido
                    else
                        quantDias += 28 - (diai - 1);
                } // verificando de agosto a dezembro
                else if (mesi > 7 && mesi % 2 == 0)
                    quantDias += 31 - (diai - 1);
                else if (mesi > 7 && mesi % 2 == 1)
                    quantDias += 30 - (diai - 1);
            }
            else
            { // verfica��o de m�s diferente do m�s inical
                // verficande de janeiro a julho
                if (mespro <= 7 && mespro % 2 == 1)
                    quantDias += 31; // C reduzido
                else if (mespro <= 7 && mespro % 2 == 0 && mespro != 2)
                    quantDias += 30;
                else if (mespro == 2)
                {
                    if (anoi % 400 == 0)
                        quantDias = quantDias + 29; // Espress�o normal
                    else if (anoi % 100 != 0 && anoi % 4 == 0)
                        quantDias += 29; // C reduzido
                    else
                        quantDias += 28;
                } // verificando de agosto a dezembro
                else if (mespro > 7 && mespro % 2 == 0)
                    quantDias += 31;
                else if (mespro > 7 && mespro % 2 == 1)
                    quantDias += 30;
            }

            mespro++;
        }
        quantDias += diaf; // recebendo dias do mes final
    }
    // printf("dias %d", quantDias);// impress�o de teste

    printf("%d", quantDias - 1);
}