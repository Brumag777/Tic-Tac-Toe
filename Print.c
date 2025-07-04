#include "TicTacToe.h"

// Imprime o menu principal - Prints the main menu
void imprimeMenuPrincipal (int ModoJogo) {
    printf ("________________________________________________________________________________________________________________________________________________________________________________________________________\n\n"
            "                                                             ████████ ██  ██████       ████████  █████   ██████       ████████  ██████  ███████ \n"
            "                                                                ██    ██ ██               ██    ██   ██ ██               ██    ██    ██ ██      \n"
            "                                                                ██    ██ ██      █████    ██    ███████ ██      █████    ██    ██    ██ █████   \n"
            "                                                                ██    ██ ██               ██    ██   ██ ██               ██    ██    ██ ██      \n"
            "                                                                ██    ██  ██████          ██    ██   ██  ██████          ██     ██████  ███████ \n"
            AZUL "\n                                                                                     Press 'c' to know to controls!\n" RESET
            "________________________________________________________________________________________________________________________________________________________________________________________________________\n\n");
    if (ModoJogo == 0) printf (AZUL "                                                                                      Game Mode: Player VS Player\n" RESET);
    else if (ModoJogo == 1) printf (AZUL "                                                                                  Game Mode: Player VS Computer (Easy)\n" RESET);
    else if (ModoJogo == 2) printf (AZUL "                                                                                 Game Mode: Player VS Computer (Medium)\n" RESET);
    else printf (AZUL "                                                                                  Game Mode: Player VS Computer (Hard)\n" RESET);
}



// Imprime o menu de controlos - Prints the controls menu
void imprimeMenuControlos () {
    printf ("________________________________________________________________________________________________________________________________________________________________________________________________________\n\n"
            "                                                             ████████ ██  ██████       ████████  █████   ██████       ████████  ██████  ███████ \n"
            "                                                                ██    ██ ██               ██    ██   ██ ██               ██    ██    ██ ██      \n"
            "                                                                ██    ██ ██      █████    ██    ███████ ██      █████    ██    ██    ██ █████   \n"
            "                                                                ██    ██ ██               ██    ██   ██ ██               ██    ██    ██ ██      \n"
            "                                                                ██    ██  ██████          ██    ██   ██  ██████          ██     ██████  ███████ \n"
            AZUL "\n                                                                                 Press 'q' to return to the main menu!\n" RESET
            "________________________________________________________________________________________________________________________________________________________________________________________________________\n\n"
            MAGENTA "Main Menu Controls\n\n"
            AZUL "q:" RESET " Quits the game.\n"
            AZUL "m:" RESET " Changes the game mode.\n"
            AZUL "c:" RESET " Opens the controls menu.\n"
            AZUL "Enter:" RESET " Starts the game.\n\n"
            MAGENTA "In-Game Controls\n\n"
            AZUL "q:" RESET " Returns to the main menu.\n"
            AZUL "w a s d:" RESET " Moves the selected square.\n"
            AZUL "Enter:" RESET " Makes a play in the selected square.\n");
}



// Imprime o menu do jogo - Prints the game menu
void imprimeMenuJogo (InfoJogo I) {

    // Imprime o logo - Prints the logo
    printf ("________________________________________________________________________________________________________________________________________________________________________________________________________\n\n"
            "                                                             ████████ ██  ██████       ████████  █████   ██████       ████████  ██████  ███████ \n"
            "                                                                ██    ██ ██               ██    ██   ██ ██               ██    ██    ██ ██      \n"
            "                                                                ██    ██ ██      █████    ██    ███████ ██      █████    ██    ██    ██ █████   \n"
            "                                                                ██    ██ ██               ██    ██   ██ ██               ██    ██    ██ ██      \n"
            "                                                                ██    ██  ██████          ██    ██   ██  ██████          ██     ██████  ███████ \n"
            AZUL "\n                                                                                 Press 'q' to return to the main menu!\n" RESET
            "________________________________________________________________________________________________________________________________________________________________________________________________________\n\n");

    // Imprime o tabuleiro - Prints the board
    printf ("                                                                                             ╔═══╦═══╦═══╗\n");
    for (int i = 0; i < 3; i++) {
        printf ("                                                                                             ");
        for (int j = 0; j < 3; j++) {
            printf ("║");
            if (i == I -> L && j == I -> C) {
                if (I -> TurnoX) printf (AZUL);
                else printf (MAGENTA);
            } if (I -> Tabuleiro [i][j] == 'X') printf (" X ");
            else if (I -> Tabuleiro [i][j] == 'O') printf (" ○ ");
            else if (i != I -> L || j != I -> C) printf ("   ");
            else printf (" ☐ ");
            printf (RESET);
        } if (i == 2) printf ("║\n                                                                                             ╚═══╩═══╩═══╝\n");
        else printf ("║\n                                                                                             ╠═══╬═══╬═══╣\n");
    }
}



// Imprime o menu do fim do jogo - Prints the post game menu
void imprimeMenuFimJogo (InfoJogo I, char c) {

    // Imprime o logo - Prints the logo
    printf ("________________________________________________________________________________________________________________________________________________________________________________________________________\n\n");
    if (c == 'X')
        printf ("                                                     ██████  ██       █████  ██    ██ ███████ ██████      ██   ██     ██     ██  ██████  ███    ██ ██ \n"
                "                                                     ██   ██ ██      ██   ██  ██  ██  ██      ██   ██      ██ ██      ██     ██ ██    ██ ████   ██ ██ \n"
                "                                                     ██████  ██      ███████   ████   █████   ██████        ███       ██  █  ██ ██    ██ ██ ██  ██ ██ \n"
                "                                                     ██      ██      ██   ██    ██    ██      ██   ██      ██ ██      ██ ███ ██ ██    ██ ██  ██ ██    \n"
                "                                                     ██      ███████ ██   ██    ██    ███████ ██   ██     ██   ██      ███ ███   ██████  ██   ████ ██ \n");
    else if (c == 'O')
        printf ("                                                     ██████  ██       █████  ██    ██ ███████ ██████       ██████      ██     ██  ██████  ███    ██ ██ \n"
                "                                                     ██   ██ ██      ██   ██  ██  ██  ██      ██   ██     ██    ██     ██     ██ ██    ██ ████   ██ ██ \n"
                "                                                     ██████  ██      ███████   ████   █████   ██████      ██    ██     ██  █  ██ ██    ██ ██ ██  ██ ██ \n"
                "                                                     ██      ██      ██   ██    ██    ██      ██   ██     ██    ██     ██ ███ ██ ██    ██ ██  ██ ██    \n"
                "                                                     ██      ███████ ██   ██    ██    ███████ ██   ██      ██████       ███ ███   ██████  ██   ████ ██ \n");
    else
        printf ("                                                                                  ██████  ██████   █████  ██     ██ ██ \n"
                "                                                                                  ██   ██ ██   ██ ██   ██ ██     ██ ██ \n"
                "                                                                                  ██   ██ ██████  ███████ ██  █  ██ ██ \n"
                "                                                                                  ██   ██ ██   ██ ██   ██ ██ ███ ██    \n"
                "                                                                                  ██████  ██   ██ ██   ██  ███ ███  ██ \n");
    printf (AZUL "\n                                                                                Press enter to return to the main menu!\n" RESET
            "________________________________________________________________________________________________________________________________________________________________________________________________________\n\n");
    
    // Imprime o tabuleiro - Prints the board
    printf ("                                                                                             ╔═══╦═══╦═══╗\n");
    for (int i = 0; i < 3; i++) {
        printf ("                                                                                             ");
        for (int j = 0; j < 3; j++) {
            printf ("║");
            if (i == I -> L && j == I -> C) {
                if (I -> TurnoX) printf (AZUL);
                else printf (MAGENTA);
            } if (I -> Tabuleiro [i][j] == 'X') printf (" X ");
            else if (I -> Tabuleiro [i][j] == 'O') printf (" ○ ");
            else if (i != I -> L || j != I -> C) printf ("   ");
            else printf (" ☐ ");
            printf (RESET);
        } if (i == 2) printf ("║\n                                                                                             ╚═══╩═══╩═══╝\n");
        else printf ("║\n                                                                                             ╠═══╬═══╬═══╣\n");
    }
}