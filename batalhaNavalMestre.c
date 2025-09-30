#include <stdio.h>
#include <string.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

#define BOARD_SIZE 10
#define SKILL_SIZE 7   // usamos 7x7 para formas mais nítidas
#define WATER 0
#define SHIP 3
#define AFFECT 5

/* 
  Funções:
  - create_cone: gera uma matriz 7x7 com um "cone" apontando para baixo.
  - create_cross: gera uma matriz 7x7 em forma de cruz (centro é origem).
  - create_octa: gera uma matriz 7x7 representando vista frontal (losango).
  - overlay_skill: sobrepõe a matriz de habilidade no tabuleiro, centrando no ponto de origem.
  - print_board: imprime o tabuleiro no console.
  - init_ships: posiciona alguns navios de exemplo (valor 3).
*/

/* Gera a matriz de habilidade 'cone' apontando para baixo.
   Lógica: para cada linha i (0..n-1), marcamos colunas
   j onde abs(j-center) <= i (ou seja, cone que se alarga para baixo).
*/
void create_cone(int m[SKILL_SIZE][SKILL_SIZE]) {
    int n = SKILL_SIZE;
    int center = n / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ( (j - center) < 0 ? (center - j) <= i : (j - center) <= i) {
                // equivale a: if (abs(j-center) <= i)
                m[i][j] = 1;
            } else {
                m[i][j] = 0;

            }
        }
    }
}
/* Gera a matriz de habilidade 'cross' (cruz) com origem no centro.
   Lógica: marca se a linha é a linha central ou a coluna é a coluna. 
*/
void create_cross(int m[SKILL_SIZE][SKILL_SIZE]) {
    int n = SKILL_SIZE;
    int center = n / 2;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == center || j == center) m[i][j] = 1;
            else m[i][j] = 0;
        }
    }
}

/* Gera a matriz de habilidade 'octa' (aproximação do losango visto de frente). 
   Lógica: marca posições onde |i-center| + |j-center| <= radius (diamond).
   radius define "quão largo" é o losango; usamos center (3) para preencher bem.
*/
void create_octa(int m[SKILL_SIZE][SKILL_SIZE]) {
    int n = SKILL_SIZE;
    int center = n / 2;
    int radius = center; // para 7x7, radius = 3 => forma de losango ocupando boa área
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int dist = (i > center ? i - center : center - i)
                     + (j > center ? j - center : center - j); // // |i-center| + |j-center|
            if (dist <= radius) m[i][j] = 1;
            else m[i][j] = 0;
        }
    } 
}

/* Sobrepõe a matriz de habilidade (skill_mat, tamanho SKILL_SIZE) no tabuleiro (board),
   centrando a skill em (origin_r, origin_c) - coordenadas do tabuleiro.
   Se a célula da skill == 1, marcamos o tabuleiro com AFFECT (5), 
   respeitando os limites do tabuleiro (checagem de bounds).
   OBS: Aqui escolhi sobrescrever qualquer valor por AFFECT (inclusive navio = 3),
   para que a área de efeito fique visualmente destacada. Se preferir preservar
   navios (mostrar 3 onde havia navio), mude a atribuição condicionando board[][] != SHIP.
*/

void overlay_skill(int board[BOARD_SIZE][BOARD_SIZE]), int skill_mat[SKILL_SIZE][SKILL_SIZE],
                   int origin_r, int origin_c {
     int n = SKILL_SIZE;
     int center = n / 2;

    // Para cada célula da skill, calcule a posição correspondente no tabuleiro
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (skill_mat[i][j] == 1) {
                int board_r = origin_r + (i - center);
                int board_c = origin_c + (j - center);

                // Verifique se está dentro dos limites do tabuleiro
                if (board_r >= 0 && board_r < BOARD_SIZE && board_c >= 0 && board_c < BOARD_SIZE)
                   board[board_r][board_c] = AFFECT; {

                 }
             }
         }
     }
 }

 /* Imprime o tabuleiro no console.
   Utilizamos números (0,3,5) conforme solicitado; você pode trocar por caracteres se quiser.
*/
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("Tabuleiro (0 = agua, 3 = navio, 5 = area afetada): \n\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            print("%d ", board[i][j]);

        }
        printf("\n");
    }
    printf("\n");
}

/* Inicializa um exemplo de navios no tabuleiro (valores = 3).
   - um navio horizontal
   - um navio vertical
   - um navio diagonal (exemplo extra)
   Esses posicionamentos são apenas para demonstração.
*/
void init_ships(int board[BOARD_SIZE][BOARD_SIZE]) {
    
}
