//
// Created by Thomaz on 12/03/2020.
//

#include "Logica.h"
#include "Dados.h"
#include <stdio.h>
#include <math.h>

int e_vizinho (COORDENADA c1, COORDENADA c2){
    int x1;
    int x2;
    int y1;
    int y2;
    x1 = c1.coluna;
    y1 = c1.linha;
    x2 = c2.coluna;
    y2 = c2.linha;
    if (abs(x1-x2)<= 1){
        if (abs(y1-y2)<= 1)
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

int e_vazio (COORDENADA c3, ESTADO* state){
    int x3;
    int y3;
    x3 = c3.coluna;
    y3 = c3.linha;
    if (state->tab[x3][y3]==VAZIO || state->tab[x3][y3]==UM || state->tab[x3][y3]==DOIS)
        return 1;
    else
        return 0;
}

int e_peca (COORDENADA c){
    if (((c.coluna >= 0)&&(c.coluna <= 7))&&((c.linha >= 0)&&(c.linha <= 7)))
        return 1;
    else
        return 0;
}

int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    int xu;
    int yu;
    xu = e->ultima_jogada.coluna;
    yu = e->ultima_jogada.linha;
    int l;
    int co;
    l = c.linha;
    co = c.coluna;
    if ((e_vazio(c,e))&&(e_vizinho(c,e->ultima_jogada))&&(e_peca(c))){
        e->tab[yu][xu] = PRETA;
        e->tab[l][co] = BRANCA;
        e->ultima_jogada.linha = l;
        e->ultima_jogada.coluna = co;
        e->num_jogadas= e->num_jogadas+1;
        if (e->jogador_atual == 1)
            e->jogador_atual = 2;
        else
            e->jogador_atual = 1;
    }
    else{
        printf("Jogada Invalida\n");
        e->tab[yu][xu] = BRANCA;
    }
    return 1;
}
