//
// Created by Thomaz on 12/03/2020.
//

#include "Dados.h"
#include <stdio.h>
#include <math.h>


//Função que verifica se duas peças são vizinhas.

int e_vizinho (COORDENADA c1, COORDENADA c2){
    int x1;
    int x2;
    int y1;
    int y2;
    x1 = c1.coluna;
    y1 = c1.linha;
    x2 = c2.coluna;
    y2 = c2.linha;
    if ((abs(x1-x2)<= 1)&&(abs(y1-y2)<= 1))
        return 1;
    else
        return 0;
}

// Essa função verifica se a casa em que se pretende jogar está vazia ou não.

int e_vazio (COORDENADA c3, ESTADO* state){
    int x3;
    int y3;
    x3 = c3.coluna-1;
    y3 = c3.linha-1;
    if (state->tab[x3][y3]==VAZIO || state->tab[x3][y3]==UM || state->tab[x3][y3]==DOIS)
        return 1;
    else
        return 0;
}

// Função que verifica se a coordenada pertence ao tabuleiro.

int e_peca (COORDENADA c){
    if (((c.coluna >= 0)&&(c.coluna <= 7))&&((c.linha >= 0)&&(c.linha <= 7)))
        return 1;
    else
        return 0;
}

//Função que realiza a jogada.

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
    if ((e_vazio(c,e))&&(e_vizinho(c,e->ultima_jogada))&&(e_peca(c))) {
        e->tab[yu][xu] = PRETA;
        e->tab[l][co] = BRANCA;
        if (e->jogador_atual == 1) {
            e->jogadas[e->num_jogadas-1].jogador1 = c;
            e->jogador_atual = 2;
        }
        else {
            e->jogadas[e->num_jogadas-1].jogador2 = c;
            e->jogador_atual = 1;
            e->num_jogadas= e->num_jogadas+1;
        }
        e->ultima_jogada.linha = l;
        e->ultima_jogada.coluna = co;
    }
    else{
        printf("Jogada Invalida\n");
        e->tab[yu][xu] = BRANCA;
    }
    return 1;
}

char conv_c(int col){
    char c;
    c = 'a' + col;
    return c;
}

char conv_l(int lin){
    char c;
    c = '1' + lin;
    return c;
}


int write_coord(COORDENADA coord){
    int x;
    int y;
    x = coord.coluna;
    y = coord.linha;
    char xc;
    char yc;
    xc = conv_c(x);
    yc = conv_l(y);
    printf("%c%c ",xc,yc);
    return 0;
}

int movs(ESTADO *e){
    int i = 0;
    while (i < (e->num_jogadas-1)){
        printf("j%d: ",(i+1));
        write_coord(e->jogadas[i].jogador1);
        write_coord(e->jogadas[i].jogador2);
        printf("\n");
        i++;
    }
    if (e->jogador_atual == 2) {
        printf("j%d: ",i+1);
        write_coord(e->jogadas[i].jogador1);
    }
    return 0;
}
