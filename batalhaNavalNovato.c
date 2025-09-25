#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

    #define TAMANHO 10 // Define o tamanho do tabuleiro (10x10)
    #define NAVIO 3 // Valor usado para representar o navio no tabuleiro
    #define TAM_NAVIO 3 // Tamanho fixo dos navios 

    int main() {
        int tabuleiro[TAMANHO][TAMANHO]; // Matriz 10x10 que representa o tabuleiro
        int i, j;

        // === Inicializando o tabuleiro com 0 (água) ===
        for (i = 0; i < TAMANHO; i++) {
            for (j = 0; j < TAMANHO; j++) {
                tabuleiro[i][j] = 0;
            }
       }
       
       // === Coordenadas iniciais dos navios (definidas no código) ===
       int linhaHorizontal = 2; // Linha onde o navio horizontal começa
       int colunaHorizontal = 1; // Coluna inicial do navio horizontal

       int linhaVertical = 5; // Linha inicial do navio vertical
       int colunaVertical = 7; // Coluna onde o navio vertical começa

       // === Posiciona navio horizontal ===
       // validalção: garante que ele não ultrapasse os limites
       if (colunaHorizontal + TAM_NAVIO <= TAMANHO) {
          for (j = 0; j < TAM_NAVIO; j++) {
              tabuleiro[linhaHorizontal][colunaHorizontal + j] = NAVIO;
          }
       }

       // === Posiciona navio vertical ===
       // Validação: garante que ele não ultrapasse os limites
       if (linhaVertical + TAM_NAVIO <= TAMANHO) {
          for (i = 0; i < TAM_NAVIO; i++) {
              tabuleiro[linhaVertical + i][colunaVertical] = NAVIO;
        }
    }

       // === Exibe o tabuleiro ===
       printf("=== Tabuleiro Batalha Naval ===\n\n");
       for (i = 0; i < TAMANHO; i++) {
           for (j = 0; j < TAMANHO; j++) {
               printf("%d ", tabuleiro[i][j]); // Mostra o valor (0 = água, 3 = navio)
           }
           printf("\n"); // Quebra de linha a cada linha do tabuleiro
       }

       return 0;

    }
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0


