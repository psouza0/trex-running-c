#include <time.h> // Usada para função delay
#include <windows.h>
#include "extraf.h"

void gotoxy(int x, int y)//X recebe a coluna e Y a linha
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(unsigned int msec)
{
    clock_t goal = msec + clock();

    while (goal > clock());
}
