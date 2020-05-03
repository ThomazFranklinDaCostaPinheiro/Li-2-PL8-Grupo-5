//
// Created by Thomaz on 12/03/2020.
//

#include "Dados.h"
#include <stdlib.h>


ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    int i2 = 0;
    int cont = 0;
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
    e -> tab[0][0] = UM;
    e -> tab[7][7] = DOIS;
    e -> tab[4][4] = BRANCA;
    e -> jogador_atual = 1;
    e -> num_jogadas = 1;
    while(cont < 32){
        e->jogadas[cont].jogador1.linha = 4;
        e->jogadas[cont].jogador1.coluna = 4;
        e->jogadas[cont].jogador2.linha = 4;
        e->jogadas[cont].jogador2.coluna = 4;
        cont++;
    }
    return e;
}

char conv_c(int col){
    char c;
    c = (char)(col+97);
    return c;
}

char conv_l(int lin){
    char c;
    c = (char)(lin+49);
    return c;
}

int obter_jogador_atual(ESTADO *estado){
    int x;
    x = estado->jogador_atual;
    return x;
}

int obter_numero_de_jogadas(ESTADO *estado){
    int y;
    y = estado->num_jogadas;
    return y;
}

CASA obter_casa(ESTADO *e, int y, int x){
    return e->tab[y][x];
}

int obter_coluna(ESTADO *e, int player, int jogada){
    if (player == 2)
        return e->jogadas[jogada].jogador2.coluna;
    else
        return e->jogadas[jogada].jogador1.coluna;
}

int obter_linha(ESTADO *e, int player, int jogada){
    if (player == 2)
        return e->jogadas[jogada].jogador2.linha;
    else
        return e->jogadas[jogada].jogador1.linha;
}

int obter_coluna_ult(ESTADO *e){
    return e->ultima_jogada.coluna;
}
int obter_linha_ult(ESTADO *e){
    return e->ultima_jogada.linha;
}

COORDENADA obter_coord_ult(ESTADO *e){
    return e->ultima_jogada;
}

COORDENADA obter_coord(ESTADO *e, int player, int jogada){
    if (player == 2)
        return  e->jogadas[jogada].jogador2;
    else
        return  e->jogadas[jogada].jogador1;
}

JOGADA obter_jogadas(ESTADO *e,int n){
    return e->jogadas[n];
}

void guarda_ultima_jog(ESTADO *e, int y, int x){
    e->ultima_jogada.coluna = x;
    e->ultima_jogada.linha = y;
}

void guarda_num_jogs(ESTADO *e, int n){
    e->num_jogadas = n;
}

void alteracasa(ESTADO *e, int x, int y, CASA c){
    e->tab[y][x] = c;
}

void guarda_jogada(ESTADO *e, int j, int nj, int y, int x){
    if(j == 1) {
        e->jogadas[nj].jogador1.coluna = x;
        e->jogadas[nj].jogador1.linha = y;
    }
    else{
        e->jogadas[nj].jogador2.coluna = x;
        e->jogadas[nj].jogador2.linha = y;
    }
}

void guarda_jogada_coord(ESTADO *e, int j, int nj, COORDENADA c){
    guarda_jogada(e,j,nj,c.linha,c.coluna);
}

void guardar_jogador(ESTADO *e, int n){
    e->jogador_atual = n;
}