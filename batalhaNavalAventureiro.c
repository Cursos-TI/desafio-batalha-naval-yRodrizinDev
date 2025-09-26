#include <stdio.h>
#include <stdbool.h>

// Constantes para facilitar a leitura
#define TAMANHO 10        // tamanho do tabuleiro 10x10
#define NAVIO 3           // valor que representa um navio
#define TAMANHO_NAVIO 3   // comprimento fixo dos navios

// Função: inicializa o tabuleiro com zeros (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função: valida se é possível posicionar o navio na posição desejada
bool podePosicionar(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, bool diagonal) {
    for (int k = 0; k < TAMANHO_NAVIO; k++) {
        int i = linha;
        int j = coluna;

        if (!diagonal) {
            if (direcao == 0) j += k;  // horizontal →
            else i += k;              // vertical ↓
        } else {
            if (direcao == 0) { i += k; j += k; } // diagonal principal ↘
            else { i += k; j -= k; }             // diagonal secundária ↙
        }

        // Validação dos limites
        if (i < 0 || i >= TAMANHO || j < 0 || j >= TAMANHO) {
            return false;
        }

        // Checa se já existe navio na posição
        if (tabuleiro[i][j] == NAVIO) {
            return false;
        }
    }
    return true;
}

// Função: coloca efetivamente o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int direcao, bool diagonal) {
    for (int k = 0; k < TAMANHO_NAVIO; k++) {
        int i = linha;
        int j = coluna;

        if (!diagonal) {
            if (direcao == 0) j += k;  // horizontal
            else i += k;              // vertical
        } else {
            if (direcao == 0) { i += k; j += k; }  // diagonal ↘
            else { i += k; j -= k; }               // diagonal ↙
        }

        tabuleiro[i][j] = NAVIO;
    }
}

// Função: exibe o tabuleiro completo
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n=== TABULEIRO COMPLETO ===\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // 🚢 Posicionamento dos 4 navios (fixos para este nível)
    if (podePosicionar(tabuleiro, 0, 0, 0, false))
        posicionarNavio(tabuleiro, 0, 0, 0, false); // horizontal no topo

    if (podePosicionar(tabuleiro, 2, 0, 1, false))
        posicionarNavio(tabuleiro, 2, 0, 1, false); // vertical na esquerda

    if (podePosicionar(tabuleiro, 4, 4, 0, true))
        posicionarNavio(tabuleiro, 4, 4, 0, true); // diagonal principal ↘

    if (podePosicionar(tabuleiro, 6, 8, 1, true))
        posicionarNavio(tabuleiro, 6, 8, 1, true); // diagonal secundária ↙

    // Exibe o resultado final
    exibirTabuleiro(tabuleiro);

    return 0;
}
