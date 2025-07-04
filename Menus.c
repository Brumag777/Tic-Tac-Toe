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
    
    // Inicializa a informação do jogo - Inicializes the information of the game
    InfoJogo I = inicializaJogo (ModoJogo);

    // Verifica se ocorreu um erro ao inicializar o jogo - Checks if there was an error when inicializing the game
    if (I == NULL) return 1;

    // Corre o menu - Runs the menu
    while (1) {

        // Limpa a terminal - Clears the terminal
        printf ("\033[2J\033[H");

        // Imprime o menu do jogo - Prints the game menu
        imprimeMenuJogo (I);

        // Recebe o input do jogador - Receives the player's input
        char Input = getchar ();

        // Verifica se o jogador pretende terminar o jogo - Checks whether the player wants to finish the game
        if (Input == 'q') break;

        // Verifica se o jogador pretende mudar o quadrado selecionado - Checks whether the player wants to change the selected square
        else if (Input == 'w' || Input == 's' || Input == 'a' || Input == 'd') mudaQuadradoSelecionado (I, Input);

        // Verifica se o jogador pretende realizar uma jogada - Checks whether the player wants to make a play
        else if (Input == '\n') {

            // Verifica se foi realiza uma jogada - Checks if a play was made
            if (realizaJogada (I))

            // Verifica se o jogo foi terminado - Checks if the game is finished
            if (fimJogo (I)) break;
        }
    }

    // Liberta a memória alocada para a informação do jogo - Frees the memomry allocated for the game's information
    free (I);

    // Indica que a função correu corretamente - Indicates that the function ran correctly
    return 0;
}



// Corre o menu do fim do jogo - Runs the post game menu
void menuFim (InfoJogo I, char c) {

    // Corre o menu até ao jogador pressionar enter - Runs the menu until the player presses enter
    while (1) {

        // Limpa a terminal - Clears the terminal
        printf ("\033[2J\033[H");

        // Imprime o menu do fim jogo - Prints the post game menu
        imprimeMenuFimJogo (I, c);

        // Verifica se o jogador pretende sair do menu - Checks whether the player wants to leave the menu
        if (getchar () == '\n') break;
    }
}