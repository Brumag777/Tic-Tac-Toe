#include "TicTacToe.h"

// Determina o turno oposto - Determines the opposing turn
char turnoOposto (char c) {
    if (c == 'X') return 'O';
    return 'X';
}



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

    // Define o turno do computador
    if (rand () % 2) I -> TurnoAI = 'O';
    else I -> TurnoAI = 'X';

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

    // Verifica se é a jogada do computador - Checks if it's the computer's play
    if (I -> ModoJogo && ((I -> TurnoX && I -> TurnoAI == 'X') || (I -> TurnoX == 0 && I -> TurnoAI == 'O'))) {
        if (I -> ModoJogo == 1) computadorFacil (I);
        else if (I -> ModoJogo == 2) computadorMedio (I);
        else computadorDificil (I);
        I -> TurnoX = !I -> TurnoX;
        return 1;
    }

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



// Procura uma jogada que leva à vitória - Looks for a play that leads to a win
int jogadaVitoria (InfoJogo I) {

    // Procura espaços vazios - Looks for empty spaces
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (I -> Tabuleiro [i][j] == ' ') {
                I -> Tabuleiro [i][j] = I -> TurnoAI;
                if (vitoria (I -> Tabuleiro, I -> TurnoAI)) {
                    I -> L = i;
                    I -> C = i;
                    return 1;
                } I -> Tabuleiro [i][j] = ' ';
            }

    // Não há nenhuma jogada que leva à vitória - There is no play that leads to victory
    return 0;
}



// Procura uma jogada que previne a derrota - Looks for a play that prevents defeat
int jogadaAntiDerrota (InfoJogo I) {

    // Procura espaços vazios - Looks for empty spaces
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (I -> Tabuleiro [i][j] == ' ') {
                I -> Tabuleiro [i][j] = turnoOposto (I -> TurnoAI);
                if (vitoria (I -> Tabuleiro, turnoOposto (I -> TurnoAI))) {
                    I -> L = i;
                    I -> C = j;
                    I -> Tabuleiro [i][j] = I -> TurnoAI;
                    return 1;
                } I -> Tabuleiro [i][j] = ' ';
            }

    // Não há nenhuma jogada que previe a derrota - There is no play that prevents defeat
    return 0;
}



// Procura um fork - Looks for a fork
int jogadaFork (InfoJogo I) {

    // Procura espaços vazios - Looks for empty spaces
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (I -> Tabuleiro [i][j] == ' ') {
                I -> Tabuleiro [i][j] = I -> TurnoAI;
                I -> L = i;
                I -> C = j;
                if (verificaFork (I)) {
                    I -> L = i;
                    I -> C = j;
                    return 1;
                } I -> Tabuleiro [i][j] = ' ';
            }

    // Não há nenhum fork - There is no fork
    return 0;
}



// Verifica se uma jogada leva a um fork - Checks if a play leads to a fork
int verificaFork (InfoJogo I) {

    // Número de possibilidades de vitória - Number os possibilities of victory
    int n = 0;
    
    // Verifica a coluna - Checks the column
    for (int i = 0; i < 3; i++)
        if (I -> Tabuleiro [i][I -> C] != ' ') {
            if (I -> Tabuleiro [i][I -> C] != I -> TurnoAI) break;
        } else if (i != I -> L) {
            I -> Tabuleiro [i][I -> C] = I -> TurnoAI;
            if (vitoria (I -> Tabuleiro, I -> TurnoAI)) n++;
            I -> Tabuleiro [i][I -> C] = ' ';
        }

    // Verifica a linha - Checks the line
    for (int j = 0; j < 3; j++)
        if (I -> Tabuleiro [I -> L][j] != ' ') {
            if (I -> Tabuleiro [I -> L][j] != I -> TurnoAI) break;
        } else if (j != I -> C) {
            I -> Tabuleiro [I -> L][j] = I -> TurnoAI;
            if (vitoria (I -> Tabuleiro, I -> TurnoAI)) n++;
            I -> Tabuleiro [I -> L][j] = ' ';
        }

    // Verifica a primeira diagonal - Checks the first diagonal
    if (I -> L == I -> C) {
        for (int k = 0; k < 3; k++)
            if (I -> Tabuleiro [k][k] != ' ') {
                if (I -> Tabuleiro [k][k] != I -> TurnoAI) break;
            } else if (k != I -> L) {
                I -> Tabuleiro [k][k] = I -> TurnoAI;
                if (vitoria (I -> Tabuleiro, I -> TurnoAI)) n++;
                I -> Tabuleiro [k][k] = ' ';
            }
    }

    // Verifica a segunda diagonal - Checks the second diagonal
    if (I -> L == 2 - I -> C) {
        for (int k = 0; k < 3; k++)
            if (I -> Tabuleiro [k][2 - k] != ' ') {
                if (I -> Tabuleiro [k][2 - k] != I -> TurnoAI) break;
            } else if (k != I -> L) {
                I -> Tabuleiro [k][2 - k] = I -> TurnoAI;
                if (vitoria (I -> Tabuleiro, I -> TurnoAI)) n++;
                I -> Tabuleiro [k][2 - k] = ' ';
            }
    }

    // Indica se foi criado um fork - Indicates if a fork was made
    return n > 1;
}



// Procura uma jogada nos cantos ou no meio - Looks for a play in the corners or the middle
int jogadaEficiente (InfoJogo I) {

    // Verifica se existe uma jogada nos cantos ou no meios - Checks if there is a play in the corners or the middle
    if (I -> Tabuleiro [0][0] != ' ' && I -> Tabuleiro [0][2] != ' ' &&
        I -> Tabuleiro [1][1] != ' ' && I -> Tabuleiro [2][0] != ' ' &&
        I -> Tabuleiro [2][2] != ' ') return 0;

    // Inicia um ciclo até encontrar uma jogada válida - Starts a cicle until a valid play is found
    while (1) {

        // Gera um número aleatório de 0 a 4 - Generates a random number from 0 to 4
        int n = rand () % 5;

        // Verifica se a jogada é válida - Checks if the play is valid
        if (n == 0 && jogadaEficienteAux (&I -> Tabuleiro [0][0], I -> TurnoAI)) break;
        if (n == 1 && jogadaEficienteAux (&I -> Tabuleiro [0][2], I -> TurnoAI)) break;
        if (n == 2 && jogadaEficienteAux (&I -> Tabuleiro [1][1], I -> TurnoAI)) break;
        if (n == 3 && jogadaEficienteAux (&I -> Tabuleiro [2][0], I -> TurnoAI)) break;
        if (n == 4 && jogadaEficienteAux (&I -> Tabuleiro [2][2], I -> TurnoAI)) break;
    }

    // Indica que foi realiza uma jogada - Indicates that a play was made
    return 1;
}



// Função auxiliar à 'jogadaEficiente' - Auxiliar function of 'jogadaEficiente'
int jogadaEficienteAux (char *c, char TurnoAI) {
    if (*c != ' ') return 0;
    *c = TurnoAI;
    return 1;
}