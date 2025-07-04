#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

#define MAGENTA "\033[38;2;255;0;255m"
#define VERMELHO "\033[38;2;255;0;0m"
#define AZUL "\033[38;2;50;50;255m"
#define VERDE "\033[38;2;0;255;0m"
#define RESET "\033[0m"

// Information about a game
typedef struct infoJogo {
    char Tabuleiro [3][3];
    int TurnoX;
    int ModoJogo;
} INFOJOGO, *InfoJogo;





// Menu.c

// Corre o menu principal - Runs the main menu
int menuPrincipal ();

// Corre o menu de controlos - Runs the controls menu
void menuControlos ();

// Corre o menu do jogo - Runs the game menu
int menuJogo (int ModoJogo);





// Print.c

// Imprime o menu principal - Prints the main menu
void imprimeMenuPrincipal (int ModoJogo);

// Imprime o menu de controlos - Prints the controls menu
void imprimeMenuControlos ();