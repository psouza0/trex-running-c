#include <stdio.h>
#include <stdlib.h>
#include "../include/menu.h"


int main()
{
    system("mode con: lines=31 cols=90");//LIMITA O TAMANHO DO CONSOLE PARA 31 LINHAS E 90 COLUNAS
    system("title T-Rex Running"); //MODIFICA A BARRA DE T�TULO
    menu();
    return 0;
}
