//
// Created by Thomaz on 12/03/2020.
//

#ifndef TRABALHO_DE_LI_DADOS_H
#define TRABALHO_DE_LI_DADOS_H

/** Esse tipo CASA é responsável por indicar qual peça está em certa coordenada.*/

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

/**Essa função inicia o tabuleiro.*/

ESTADO *inicializar_estado();

/**Essa função obtém o jogador que está a jogar.*/

int obter_jogador_atual(ESTADO *estado);

/**Essa função obtém o número de jogadas realizadas.*/

int obter_numero_de_jogadas(ESTADO *estado);

/** Essa função obtém qual o estado de determinada casa do tabuleiro.*/

CASA obter_estado_casa(ESTADO *e, COORDENADA c);



#endif //TRABALHO_DE_LI_DADOS_H
