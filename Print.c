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