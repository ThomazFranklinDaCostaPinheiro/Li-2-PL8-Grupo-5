//
// Created by Thomaz on 12/03/2020.
//

#include "Lógica.h"
#include "Dados.h"
#include <stdio.h>

int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    int xu;
    int yu;
    xu = e->ultima_jogada.coluna;
    yu = e->ultima_jogada.linha;
    e->tab[xu][yu] = PRETA;
    int l;
    int co;
    l = c.linha;
    co = c.coluna;
    e->tab[c][l] = BRANCA;
    return 1;
}
