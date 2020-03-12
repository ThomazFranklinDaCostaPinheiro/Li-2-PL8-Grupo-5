//
// Created by Thomaz on 12/03/2020.
//

#include "Dados.h"
#include <stdio.h>
#include <stdlib.h>

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
    e -> ultima_jogada.coluna = 5;
    e -> ultima_jogada.linha = 4;
    int i1 = 0;
    while (i1 < 32) {
        e -> jogadas[i1].jogador1.linha = 0;
        e -> jogadas[i1].jogador1.coluna = 0;
        e -> jogadas[i1].jogador2.linha = 0;
        e -> jogadas[i1].jogador2.coluna = 0;
        i1++;
    }
    e -> jogador_atual = 1;
    e -> num_jogadas = 0;
    return e;
}
