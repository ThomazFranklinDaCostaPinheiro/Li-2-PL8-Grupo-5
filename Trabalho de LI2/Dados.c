//
// Created by Thomaz on 12/03/2020.
//

#include "Dados.h"
#include <stdlib.h>

//Essa função inicia o tabuleiro.

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    int i2 = 0;
    while (i2 < 8) {
        int i3 = 0;
        while (i3 < 8) {
            e->tab[i2][i3] = VAZIO;
            i3++;
        }
        i2++;
    }
    e -> ultima_jogada.coluna = 4;
    e -> ultima_jogada.linha = 4;
    int i1 = 0;
    while (i1 < 32) {
        e -> jogadas[i1].jogador1.linha = 4;
        e -> jogadas[i1].jogador1.coluna = 4;
        e -> jogadas[i1].jogador2.linha = 4 ;
        e -> jogadas[i1].jogador2.coluna = 4;
        i1++;
    }
    e -> tab[7][0] = UM;
    e -> tab[0][7] = DOIS;
    e -> tab[4][4] = BRANCA;
    e -> jogador_atual = 1;
    e -> num_jogadas = 0;
    return e;
}

//Essa função obtém o jogador que está a jogar.

int obter_jogador_atual(ESTADO *estado){
    int x;
    x = estado->jogador_atual;
    return x;
}

//Essa função obtém o número de jogadas realizadas.

int obter_numero_de_jogadas(ESTADO *estado){
    int y;
    y = estado->num_jogadas;
    return y;
}

// Essa função obtém qual o estado de determinada casa do tabuleiro.

CASA obter_estado_casa(ESTADO *e, COORDENADA c){
    int a;
    int b;
    b = e->ultima_jogada.linha;
    a = e->ultima_jogada.coluna;
    CASA casa;
    casa = e->tab[a][b];
    return casa;
}
