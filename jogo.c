#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "extraf.h"

int spd = 20;
int w;


void jogo(int jump)
{
    static int c=1;
    const char X = 219;
    const char B = 220;
    const char C = 223;

    char linha1[]= {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', B, X, C, X, X, X, X, X, B,' ','\n','\0'};
    char linha2[]= {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', X, X, X, X, X, X, X, X, X,' ','\n','\0'};
    char linha3[]= {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', X, X, X, X, C, C, C, C, C,' ','\n','\0'};
    char linha4[]= {' ',' ',' ',' ',' ', B,' ',' ',' ',' ',' ',' ',' ', B, X, X, X, C, C, C, C,' ',' ',' ','\n','\0'};
    char linha5[]= { ' ',' ',' ',' ',' ',X, B, B,' ',' ', B, B, X, X, X, X, X, B, B,' ',' ',' ',' ',' ','\n','\0'};
    char linha6[]= { ' ',' ',' ',' ',' ',X, X, X, X, X, X, X, X, X, X, X, X,' ', C,' ',' ',' ',' ',' ','\n','\0'};
    char linha7[]= {' ',' ',' ',' ',' ',' ', C, X, X, X, X, X, X, X, X, X, X,' ',' ',' ',' ',' ',' ',' ','\n','\0'};
    char linha8[]= {' ',' ',' ',' ',' ',' ',' ',' ', C, X, X, X, X, X, X, C,' ',' ',' ',' ',' ',' ',' ',' ','\n','\0'};
    char linha9[]= {' ',' ',' ',' ',' ',' ',' ',' ',' ', X, X, C,' ', C, X,' ',' ',' ',' ',' ',' ',' ',' ',' ','\n','\0'};
    char linha10[]= {' ',' ',' ',' ',' ',' ',' ',' ',' ', X, B,' ',' ',' ', X, B,' ',' ',' ',' ',' ',' ',' ',' ','\n','\0'};
    //Apenas pé esquerdo:
    char linhaE2[]= {' ',' ',' ',' ',' ',' ',' ',' ',' ', X, B,' ',' ',' ',' ',' ',' ','\n','\0'};
    //Apenas pé direito:
    char linhaD2[]= {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', X, B,'\n','\0'};


    if(jump==0)  //sem pular
    {
        w = 0;
    }
    else if(jump==2) //descer
    {
        w--;
    }
    else  //subir
    {
        w++;
    }
    gotoxy(1,17-w);
    printf("                       ");
    gotoxy(1,18-w);
    printf("%s",linha1);
    gotoxy(1,19-w);
    printf("%s",linha2);
    gotoxy(1,20-w);
    printf("%s",linha3);
    gotoxy(1,21-w);
    printf("%s",linha4);
    gotoxy(1,22-w);
    printf("%s",linha5);
    gotoxy(1,23-w);
    printf("%s",linha6);
    gotoxy(1,24-w);
    printf("%s",linha7);
    gotoxy(1,25-w);
    printf("%s",linha8);
    gotoxy(1,26-w);
    printf("%s",linha9);
    gotoxy(1,27-w);
    // CÓDIGO PARA A MOVIMENTAÇÃO DAS PERNAS
    //Posição das pernas no ar:
    if(jump==1 || jump==2)
    {
        printf("%s", linha9);
        gotoxy(1,27-w);
        printf("%s",linha10);
        //Alternança da posição das pernas ao correr:
    }
    else if(jump == 0 && c == 1)
    {
        gotoxy(1,27-w);
        printf("%s", linhaE2);
        c = 2;

    }
    else if(jump == 0 && c == 2)
    {
        gotoxy(1,27-w);
        printf("%s", linhaD2);
        c = 1;
    }
    gotoxy(1,28-w);
    //Se não estiver no chão, imprime vazio logo abaixo do dino
    printf("                ");
    delay(spd);

}

char obstaculo()
{

    static int z = 0, scr=0;
    char keep = ' ';
    const char X = 219;
    const char B = 220;
    char L1_ob1[]= {' ',' ', X, X,' ', B,' ','\n','\0'};
    char L2_ob1[]= {B,' ', X, X, B, X,' ','\n','\0'};
    char L3_ob1[]= {X, B, X, X,' ','\n','\0'};
    char L4_ob1[]= {' ',' ', X, X,' ','\n','\0'};
    char L5_ob1[]= {' ',' ', X, X,' ','\n','\0'};

    //CACTO
    gotoxy(85-z,23);
    printf("%s", L1_ob1);
    gotoxy(85-z,24);
    printf("%s", L2_ob1);
    gotoxy(85-z,25);
    printf("%s", L3_ob1);
    gotoxy(85-z,26);
    printf("%s", L4_ob1);
    gotoxy(85-z,27);
    printf("%s", L5_ob1);
    z++;//SEGUIR HORIZONTALMENTE PARA A ESQUERDA

    if(z==85)//MARCAR UM PONOTO NO SCORE
    {
        z=0;
        scr++;
        gotoxy(79,2);
        printf("     ");
        gotoxy(79,2);
        printf("%d",scr);
        spd--;//AUMENTA A DIFICULDADE (VELOCIDADE AUMENTA,DELAY DIMINUI)

    }

    //Game Over
    if(z>=68 && w<3)//CASO AS COORDENADAS DO T-REX COINCIDAM COM A DO OBSTACULO
    {
        scr=0;
        spd=20;
        gotoxy(36,8);
        printf("GAME OVER!!!");
        gotoxy(21,9);
        printf("Aperte |1| para recomecar ou |ENTER| para sair");
        keep = getch();

        //REINICIAR APÓS GAME OVER
        z = 0;
        gotoxy(19,23);
        printf("        RUN, ");
        gotoxy(19,24);
        printf("           T-REX");
        gotoxy(19,25);
        printf("               RUN!!!");
        gotoxy(19,26);
        printf("           ");
        gotoxy(19,27);
        printf("           ");
        gotoxy(79,2);
        printf("      ");//ZERAR O SCORE
        gotoxy(36,8);
        printf("            ");//APAGA "GAME OVER!!!"
        gotoxy(16,9);
        printf("                                                             ");//APAGA A MENSAGEM DE CONTINUAÇÃO

        if(keep != '1')//PARA SAIR DO MODO JOGO
        {
            system("cls");
            retorna_menu();
        }
    }
    return 0;
}
