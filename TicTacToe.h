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
    int L, C;
} INFOJOGO, *InfoJogo;





// Menu.c

// Corre o menu principal - Runs the main menu
int menuPrincipal ();

// Corre o menu de controlos - Runs the controls menu
void menuControlos ();

// Corre o menu do jogo - Runs the game menu
int menuJogo (int ModoJogo);

// Corre o menu do fim do jogo - Runs the post game menu
void menuFim (InfoJogo I, char c);





// Print.c

// Imprime o menu principal - Prints the main menu
void imprimeMenuPrincipal (int ModoJogo);

// Imprime o menu de controlos - Prints the controls menu
void imprimeMenuControlos ();

// Imprime o menu do jogo - Prints the game menu
void imprimeMenuJogo (InfoJogo I);

// Imprime o menu do fim do jogo - Prints the post game menu
void imprimeMenuFimJogo (InfoJogo I, char c);





// Logica.c

// Inicializa a informação do jogo - Inicializes the information of the game
InfoJogo inicializaJogo (int ModoJogo);

// Altera o quadrado selecionado - Moves the selected square
void mudaQuadradoSelecionado (InfoJogo I, char Input);

// Realiza uma jogada - Makes a play
int realizaJogada (InfoJogo I);

// Verifica se o jogo acabou - Checks if the game is finished
int fimJogo (InfoJogo I);

// Verifica se um jogador (ou o computador) ganhou - Checks if a player (or the computer) won
int vitoria (char Tabuleiro [3][3], char c);

// Verifica se o tabuleiro está completamente preenchido - Checks if the board is completly filled
int tabuleiroPreenchido (char Tabuleiro [3][3]);