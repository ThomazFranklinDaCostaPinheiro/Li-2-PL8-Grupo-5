/**
@file Dados.h
Manipulação dos dados do estado do jogo.
*/

#ifndef TRABALHO_DE_LI_DADOS_H
#define TRABALHO_DE_LI_DADOS_H

/** Este tipo CASA é responsável por indicar qual peça está em certa coordenada. */
typedef enum {VAZIO, BRANCA, PRETA, UM, DOIS} CASA;
/** Este tipo COORDENADA é indicador de uma posição no tabuleiro. */
typedef struct {
    int coluna;
    int linha;
} COORDENADA;
/** Este tipo JOGADA indica um par de movimentos, realizados por ambos os jogadores. */
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;
/** Este tipo JOGADAS é responsavel por armazenar a lista de jogadas realizadas no jogo. */
typedef JOGADA JOGADAS[32];
/** Este tipo ESTADO é responsável por guardar o estado do jogo. */
typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;

/** Esta função inicia o tabuleiro.*/
ESTADO *inicializar_estado();
/** Converte um inteiro em um char que representa uma coluna. */
char conv_c(int col);
/** Converte um inteiro em um char que representa uma linha. */
char conv_l(int lin);

/** Esta função obtém o jogador que está a jogar.*/
int obter_jogador_atual(ESTADO *estado);
/** Esta função obtém o número de jogadas realizadas.*/
int obter_numero_de_jogadas(ESTADO *estado);
/** Esta função obtém qual o tipo de peça que determinada casa do tabuleiro é.*/
CASA obter_estado_casa(ESTADO *e, COORDENADA c);
/** Esta função obtém a casa associada a uma linha e uma coluna. */
CASA obter_casa(ESTADO *e, int y, int x);
/** Esta função obtém a linha associada com uma jogada e um jogador. */
int obter_linha(ESTADO *e, int player, int jogada);
/** Esta função obtém a coluna associada com uma jogada e um jogador. */
int obter_coluna(ESTADO *e, int player, int jogada);
/** Esta função obtém a coordenada associada com uma jogada e um jogador. */
COORDENADA obter_coord(ESTADO *e, int player, int jogada);
/** Esta função obtém a linha associada à ultima jogada. */
int obter_linha_ult(ESTADO *e);
/** Esta função obtém a coluna associada à ultima jogada. */
int obter_coluna_ult(ESTADO *e);
/** Esta função obtém a coordenada associada à ultima jogada. */
COORDENADA obter_coord_ult(ESTADO *e);
/** Obtém a jogada "n". */
JOGADA obter_jogadas(ESTADO *e,int n);

/** Esta função guarda dois inteiros como coordenada do jogador 1 numa jogada. */
int guardar_jogada1(ESTADO* e,int j, char cha, int l);
/** Esta função guarda dois inteiros como coordenada do jogador 2 numa jogada. */
int guardar_jogada2(ESTADO* e,int j, char cha, int l);
void guarda_ultima_jog(ESTADO *e, int y, int x);
void guarda_num_jogs(ESTADO *e, int n);
void alteracasa(ESTADO *e, int x, int y, CASA c);
void guarda_jogada(ESTADO *e, int j, int nj, int y, int x);
void guarda_jogada_coord(ESTADO *e, int j, int nj, COORDENADA c);
void guardar_jogador(ESTADO *e, int n);

#endif //TRABALHO_DE_LI_DADOS_H
