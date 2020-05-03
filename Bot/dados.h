//
// Created by Thomaz on 12/03/2020.
//

#ifndef TRABALHO_DE_LI_DADOS_H
#define TRABALHO_DE_LI_DADOS_H


typedef enum {VAZIO, BRANCA, PRETA, UM, DOIS} CASA;
typedef struct {
    int coluna;
    int linha;
} COORDENADA;
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;
typedef JOGADA JOGADAS[32];
typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;

ESTADO *inicializar_estado();
char conv_c(int col);
char conv_l(int lin);
int obter_jogador_atual(ESTADO *estado);
int obter_numero_de_jogadas(ESTADO *estado);
CASA obter_casa(ESTADO *e, int y, int x);
int obter_linha(ESTADO *e, int player, int jogada);
int obter_coluna(ESTADO *e, int player, int jogada);
int obter_linha_ult(ESTADO *e);
int obter_coluna_ult(ESTADO *e);
COORDENADA obter_coord_ult(ESTADO *e);
void guarda_ultima_jog(ESTADO *e, int y, int x);
void guarda_num_jogs(ESTADO *e, int n);
void alteracasa(ESTADO *e, int x, int y, CASA c);
void guarda_jogada(ESTADO *e, int j, int nj, int y, int x);
void guarda_jogada_coord(ESTADO *e, int j, int nj, COORDENADA c);
void guardar_jogador(ESTADO *e, int n);

#endif //TRABALHO_DE_LI_DADOS_H
