#include "TicTacToe.h"

// Realiza a jogada do computador fácil - Makes the play of the easy computer
void computadorFacil (InfoJogo I) {

    // Inicia um ciclo até encontrar uma jogada válida - Starts a cicle until a valid play is found
    while (1) {

        // Gera um número aleatório de 0 a 8 - Generates a random number from 0 to 8
        int n = rand () % 9;

        // Altera o quadrado selecionado - Changes the selected square
        I -> L = n / 3;
        I -> C = n % 3;

        // Verifica se a jogada é válida - Checks if the play is valid
        if (I -> Tabuleiro [I -> L][I -> C] == ' ') break;
    }

    // Realiza a jogada - Makes the play
    I -> Tabuleiro [I -> L][I -> C] = I -> TurnoAI;
}



// Realiza a jogada do computador médio - Makes the play of the medium computer
void computadorMedio (InfoJogo I) {

    // Procura uma jogada que leva à vitória - Looks for a play that leads to a win
    if (jogadaVitoria (I)) return;

    // Procura uma jogada que previe a derrota - Looks for a play that prevents the loss
    if (jogadaAntiDerrota (I)) return;

    // Realiza uma jogada aleatória - Makes a random play
    computadorFacil (I);
}



// Realiza a jogada do computador difícil - Make the play of the hard computer
void computadorDificil (InfoJogo I) {

    // Procura uma jogada que leva à vitória - Looks for a play that leads to a win
    if (jogadaVitoria (I)) return;

    // Procura uma jogada que previe a derrota - Looks for a play that prevents the loss
    if (jogadaAntiDerrota (I)) return;

    // Procura um fork - Looks for a fork
    if (jogadaFork (I)) return;

    // Procura uma jogada nos cantos ou no meio - Looks for a play in the corners or the middle
    if (jogadaEficiente (I)) return;

    // Realiza uma jogada aleatória - Makes a random play
    computadorFacil (I);
}