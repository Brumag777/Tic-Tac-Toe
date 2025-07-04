#include "TicTacToe.h"

// Função principal - Main function
int main () {

    // Armazena as configurações originais da terminal - Saves the original terminal configurations
    struct termios Original;
    tcgetattr (STDIN_FILENO, &Original);

    // Altera as configurações da terminal - Changes the terminal configurations
    struct termios Novo = Original;
    Novo.c_lflag &= ~(ICANON | ECHO);
    tcsetattr (STDIN_FILENO, TCSANOW, &Novo);

    // Corre o menu principal - Runs the main menu
    if (menuPrincipal ()) return 1;

    // Restaura a configuração original da terminal - Restores the original terminal configurations
    tcsetattr (STDIN_FILENO, TCSANOW, &Original);

    // Indica que a função correu corretamente - Indicates that the function ran correctly
    return 0;
}