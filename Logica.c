#include "TicTacToe.h"

// Inicializa a informação do jogo - Inicializes the information of the game
InfoJogo inicializaJogo (int ModoJogo) {

    // Aloca memória para o struct - Alocates memory for the struct
    InfoJogo I = malloc (sizeof (INFOJOGO));

    // Verifica se ocorreu um erro ao alocar a memória - Checks if there was an error when alocating the memory
    if (I == NULL) return NULL;

    // Define as componentes do struct - Defines the struct's components
    for (int i = 0; i < 3; i++) I -> Tabuleiro [i][0] = I -> Tabuleiro [i][1] = I -> Tabuleiro [i][2] = ' ';
    I -> TurnoX = I -> L = I -> C = 1;
    I -> ModoJogo = ModoJogo;

    // Retorna o struct - Returns the struct
    return I;
}



// Altera o quadrado selecionado - Moves the selected square
void mudaQuadradoSelecionado (InfoJogo I, char Input) {
    if (Input == 'w') {
        if (I -> L) I -> L--;
    } else if (Input == 's') {
        if (I -> L < 2) I -> L++;
    } else if (Input == 'd') {
        if (I -> C < 2) I -> C++;
    } else if (I -> C) I -> C--;
}



// Realiza uma jogada - Makes a play
int realizaJogada (InfoJogo I) {

    // Verifica se a jogada é inválida - Checks if the play is invalid
    if (I -> Tabuleiro [I -> L][I -> C] != ' ') return 0;

    // Realiza a jogada - Makes the play
    if (I -> TurnoX) I -> Tabuleiro [I -> L][I -> C] = 'X';
    else I -> Tabuleiro [I -> L][I -> C] = 'O';

    // Altera o turno - Changes the turn
    I -> TurnoX = !I -> TurnoX;

    // Indica que foi realizada uma jogada - Indicates that a play was made
    return 1;
}



// Verifica se o jogo acabou - Checks if the game is finished
int fimJogo (InfoJogo I) {

    // Verifica se o jogo acabou (por vitória ou empate) - Checks if the game if over (by victory or draw)
    if (I -> TurnoX == 0 && vitoria (I -> Tabuleiro, 'X')) {
        menuFim (I, 'X');
        return 1;
    } else if (I -> TurnoX && vitoria (I -> Tabuleiro, 'O')) {
        menuFim (I, 'O');
        return 1;
    } else if (tabuleiroPreenchido (I -> Tabuleiro)) {
        menuFim (I, '-');
        return 1;
    }

    // O jogo ainda não acabou - The game is not over yet
    return 0;
}



// Verifica se um jogador (ou o computador) ganhou - Checks if a player (or the computer) won
int vitoria (char Tabuleiro [3][3], char c) {

    // Verifica as linhas e as colunas - Checks the lines and the columns
    for (int i = 0; i < 3; i++)
        if (Tabuleiro[i][0] == c && Tabuleiro[i][1] == c && Tabuleiro[i][2] == c) return 1;
        else if (Tabuleiro[0][i] == c && Tabuleiro[1][i] == c && Tabuleiro[2][i] == c) return 1;

    // Verifica as diagonais - Checks the diagonals
    if (Tabuleiro [0][0] == c && Tabuleiro [1][1] == c && Tabuleiro [2][2] == c) return 1;
    if (Tabuleiro [2][0] == c && Tabuleiro [1][1] == c && Tabuleiro [0][2] == c) return 1;

    // Não houve vitória - There was no victory
    return 0;
}



// Verifica se o tabuleiro está completamente preenchido - Checks if the board is completly filled
int tabuleiroPreenchido (char Tabuleiro [3][3]) {
    
    // Procura espaços vazios - Looks for empty spaces
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (Tabuleiro [i][j] == ' ') return 0;

    // O tabuleiro está totalmente preenchido - The board is completly filled
    return 1;
}