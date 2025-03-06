#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Usada para o comando Kbhit()
#include "../include/extraf.h"
#include "../include/desenhos.h"
#include "../include/jogo.h"
#include "../include/instrucoes.h"
#include "../include/creditos.h"

void menu() //Fun��es do menu
{
    int opcao, i, j;
    char op;
    const char X = 219;//SIMBOLO P/ DESENHO QUE CORRESPONDE A AREA DO CURSOR INTEIRO
    const char C = 223;//SIMBOLO P/ DESENHO QUE CORRESPONDE A METADE DE CIMA(C) DO CURSOR
    const char B = 220;//SIMBOLO P/ DESENHO QUE CORRESPONDE A METADE DE BAIXO(B) DO CURSOR

    //VETORES PTERODACTILO
    char L1_ob3[]= {' ',' ',' ',' ',' ',' ',' ', X, B,'\n','\0'};
    char L2_ob3[]= {' ',' ',' ',' ',' ',' ',' ', X, X, X, B,'\n','\0'};
    char L3_ob3[]= {' ',' ',' ', B,' ',' ',' ', X, X, X, X,'\n','\0'};
    char L4_ob3[]= {' ', B, X, X, X, B,' ', X, X, X, X, X, X, B,'\n','\0'};
    char L5_ob3[]= {C, C, C, C, X, X, X, X, X, X, X, X, X, X, X, X, C, C, C,'\n','\0'};
    char L6_ob3[]= {' ',' ',' ',' ',' ',' ', C, X, X, X, X, X, X, X, X, C, C,'\n','\0'};
    //VETORES NOME DO JOGO
    char txt_l1[]={X, C, X, C, X,' ',' ',' ', C, X, C, C, C, B,' ',' ', C, X, C, C, C, X,' ', C, X, C,' ', C, X, C,' ',' ',' ', X,' ', B,'\n','\0'};
    char txt_l2[]={' ',' ', X,' ',' ', B, B, B,' ', X, B, B, B, C,' ',' ',' ', X, B, B, B,' ',' ',' ',' ', C, B, C,' ',' ',' ', X,' ', X, B, X,'\n','\0'};
    char txt_l3[]={' ',' ', X,' ',' ',' ',' ',' ',' ', X,' ',' ',' ', X,' ',' ',' ', X,' ',' ',' ', B,' ',' ', B, C,' ', C, B,' ',' ', C, C, X,'\n','\0'};
    char txt_l4[]={' ', C, C, C,' ',' ',' ',' ', C, C, C,' ', C, C, C,' ', C, C, C, C, C, C,' ', C, C, C,' ', C, C, C,' ',' ',' ', C,'\n','\0'};
    char txt_l5[]={' ',' ',' ',' ', X,' ', B,' ', C, X, C, C, C, B,' ', C, X, C,' ', C, X, C,' ', C, X, B,' ', C, X, C,' ', C, X, B,' ', C, X, C,' ', C, X, C,' ', C, X, B,' ', C, X, C,' ', B, C, C, C, B,'\n','\0'};
    char txt_l6[]={' ',' ', X,' ', X, B, X,' ',' ', X, B, B, B, C,' ',' ', X,' ',' ',' ', X,' ',' ',' ', X,' ', X,' ', X,' ',' ',' ', X,' ', X,' ', X,' ',' ',' ', X,' ',' ',' ', X,' ', X,' ', X,' ',' ', X,' ',' ', B, B,'\n','\0'};
    char txt_l7[]={' ',' ', C, C, X,' ',' ',' ',' ', X,' ',' ',' ', X,' ',' ', X,' ',' ',' ', X,' ',' ',' ', X,' ', C, B, X,' ',' ',' ', X,' ', C, B, X,' ',' ',' ', X,' ',' ',' ', X,' ', C, B, X,' ',' ', X,' ',' ',' ',X,'\n','\0'};
    char txt_l8[]={' ',' ',' ',' ', C,' ',' ',' ', C, C, C,' ', C, C, C,' ',' ', C, C, C, C, C,' ', C, C, C,' ',' ', C, C,' ', C, C, C,' ',' ', C, C,' ', C, C, C,' ', C, C, C,' ',' ', C, C,' ',' ', C, C, C,'\n','\0'};
    //DESENHO DO NOME DO JOGO
    gotoxy(17,2);
    printf("%s",txt_l1);
    gotoxy(17,3);
    printf("%s",txt_l2);
    gotoxy(17,4);
    printf("%s",txt_l3);
    gotoxy(17,5);
    printf("%s",txt_l4);
    gotoxy(17,6);
    printf("%s",txt_l5);
    gotoxy(17,7);
    printf("%s",txt_l6);
    gotoxy(17,8);
    printf("%s",txt_l7);
    gotoxy(17,9);
    printf("%s",txt_l8);
    //DESENHO DO PTERODACTILO NO MENU INICIAL
    gotoxy(67,23);
    printf("%s",L1_ob3);
    gotoxy(67,24);
    printf("%s",L2_ob3);
    gotoxy(67,25);
    printf("%s",L3_ob3);
    gotoxy(67,26);
    printf("%s",L4_ob3);
    gotoxy(67,27);
    printf("%s",L5_ob3);
    gotoxy(67,28);
    printf("%s",L6_ob3);

    //DESENHO DO DINO NO MENU INICIAL
    gotoxy(1,20);
    draw_FULL_dino(); //NAO PRECISA SER DESENHADO LINHA POR LINHA POIS EST� NA PRIMEIRA COLUNA (1,y)


    //OP��ES DO MENU INICIAL
    gotoxy(40,14);
    printf("1 - Jogar\n");
    gotoxy(40,15);
    printf("2 - Instrucoes\n");
    gotoxy(40,16);
    printf("3 - Creditos\n");
    gotoxy(40,17);
    printf("4 - Sair\n");

    opcao = getch();

    switch(opcao)
    {

    case '1':
        system("cls"); //LIMPA A TELA
        gotoxy(70,2);
        printf("SCORE : ");
        gotoxy(1,29);
        for(j=0; j<87; j++) //DESENHA A MARGEM DO CH�O
        {
            printf("_");
        }
        while(1)//WHILE INFINITO PARA SEMPRE VERIFICAR SE UMA TECLA FOI PRESSIONADA
        {
            while(!kbhit())
            {
                jogo(0);
                obstaculo();
            }
            op = getch();
            if(op == 'w')
            {
                //PULANDO
                for(i=0; i<14; i++)
                {
                    jogo(1);
                    obstaculo();
                }
                //DESCENDO
                for(i=0; i<14; i++)
                {
                    jogo(2);
                    obstaculo();
                }
            }
            else if (op == 13)
            {
                system("cls");
                menu();
                break;
            }
        }
        break;

    case '2':
        system("cls");
        instrucoes();
        break;

    case '3':
        system("cls");
        credits();
        break;
    case '4':
        system("cls");
        exit(0);//ENCERRA O PROGRAMA DE VEZ
        break;
    default:
        system("cls");
        menu();//CHAMADA RECURSIVA PARA O MENU
    }

}

void retorna_menu() //FUN��O RETORNAR PARA O MENU
{
    char tecla;
    do
    {   system("cls");
        gotoxy(28,14);
        printf("Pressione ENTER para voltar ao Menu");
        tecla=getch();
    }
    while(tecla!=13); //TECLA REFERENTE AO "ENTER" NA TABELA ASCII

    system("cls");
    menu();
}
