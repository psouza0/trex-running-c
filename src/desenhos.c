#include <stdio.h>
#include <stdlib.h>
#include "../include/desenhos.h"

const char X = 219;//SIMBOLO P/ DESENHO QUE CORRESPONDE A AREA DO CURSOR INTEIRO
const char C = 223;//SIMBOLO P/ DESENHO QUE CORRESPONDE A METADE DE CIMA(C) DO CURSOR
const char B = 220;//SIMBOLO P/ DESENHO QUE CORRESPONDE A METADE DE BAIXO(B) DO CURSOR

//CONSTANTE PARA O CORPO DO DINO, EXCETO AS PERNAS
const char linha1[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B', 'X', 'C', 'X', 'X', 'X', 'X', 'X', 'B', ' ', '\n', '\0'};
const char linha2[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', '\n', '\0'};
const char linha3[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'X', 'X', 'X', 'X', 'C', 'C', 'C', 'C', 'C', ' ', '\n', '\0'};
const char linha4[] = {' ', 'B', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B', 'X', 'X', 'X', 'C', 'C', 'C', 'C', ' ', ' ', ' ', '\n', '\0'};
const char linha5[] = {' ', 'X', 'B', 'B', ' ', ' ', 'B', 'B', 'X', 'X', 'X', 'X', 'X', 'B', 'B', ' ', ' ', ' ', ' ', ' ', '\n', '\0'};
const char linha6[] = {' ', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', 'C', ' ', ' ', ' ', ' ', ' ', '\n', '\0'};
const char linha7[] = {' ', ' ', 'C', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n', '\0'};
const char linha8[] = {' ', ' ', ' ', ' ', 'C', 'X', 'X', 'X', 'X', 'X', 'X', 'C', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n', '\0'};

//LINHA9 E LINHA10 S�O DEDICADAS AS PERNAS DO DINO

void draw_FULL_dino()
{
    char linha9[]={' ',' ',' ',' ',' ', X, X, C,' ', C, X,' ',' ',' ',' ',' ',' ',' ',' ',' ','\n','\0'};
    char linha10[]={' ',' ',' ',' ',' ', X, B,' ',' ',' ', X, B,' ',' ',' ',' ',' ',' ',' ',' ','\n','\0'};

    printf("%s", linha1);
    printf("%s", linha2);
    printf("%s", linha3);
    printf("%s", linha4);
    printf("%s", linha5);
    printf("%s", linha6);
    printf("%s", linha7);
    printf("%s", linha8);
    printf("%s", linha9);
    printf("%s", linha10);
}




