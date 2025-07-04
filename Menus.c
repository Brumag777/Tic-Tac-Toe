#include "TicTacToe.h"

// Corre o menu principal - Runs the main menu
int menuPrincipal () {

    // Inteiro que indica o modo de jogo selecionado - Integer that indicates the selected game mode
    int ModoJogo = 0;

    // Corre o menu - Runs the menu
    while (1) {

        // Limpa a terminal - Clears the terminal
        printf ("\033[2J\033[H");

        // Imprime o menu principal - Prints the main menu
        imprimeMenuPrincipal (ModoJogo);

        // Recebe o input do jogador - Receives the player's input
        char Input = getchar ();

        // Verifica se o jogador pretende sair do jogo - Checks whether the player wants to quit the game
        if (Input == 'q') break;

        // Verifica se o jogador pretende ver os controlos - Checks whether the player wants to see the controls
        else if (Input == 'c') menuControlos ();

        // Verifica se o jogador pretende mudar o modo de jogo - Checks whether the player wants to change the game mode
        else if (Input == 'm') {
            if (ModoJogo < 3) ModoJogo++;
            else ModoJogo = 0;
        }

        // Verifica se o jogador pretende iniciar um jogo - Checks whether the player wants to start a game
        else if (Input == '\n') if (menuJogo (ModoJogo)) return 1;
    }

    // Indica que a função correu corretamente - Indicates that the function ran correctly
    return 0;
}



// Corre o menu de controlos - Runs the controls menu
void menuControlos () {

    // Mantém o menu aberto até ao jogador pressionar 'q' - Keeps the menu running until the player presses 'q'
    while (1) {

        // Limpa a terminal - Clears the terminal
        printf ("\033[2J\033[H");

        // Imprime o menu de controlos - Prints the controls menu
        imprimeMenuControlos ();

        // Verifica se o jogador pretende sair do menu - Checks whether the player wants to leave the menu
        if (getchar () == 'q') break;
    }
}



// Corre o menu do jogo - Runs the game menu
int menuJogo (int ModoJogo) {
    if (ModoJogo) return 0;
    return 0;
}