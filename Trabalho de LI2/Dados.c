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


CASA obter_estado_casa(ESTADO *e, COORDENADA c){
    int a;
    int b;
    b = e->ultima_jogada.linha;
    a = e->ultima_jogada.coluna;
    CASA casa;
    casa = e->tab[a][b];
    return casa;
}
