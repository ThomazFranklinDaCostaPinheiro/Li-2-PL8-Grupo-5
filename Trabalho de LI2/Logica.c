//
// Created by Thomaz on 12/03/2020.
//

#include "Dados.h"
#include "Logica.h"
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
    if ((abs(x1-x2)<= 1)&&(abs(y1-y2)<= 1))
        return 1;
    else
        return 0;
}


int e_vazio (COORDENADA c3, ESTADO* state){
    int x3;
    int y3;
    x3 = c3.coluna;
    y3 = c3.linha;
    if (state->tab[y3][x3]==VAZIO || state->tab[y3][x3]==UM || state->tab[y3][x3]==DOIS)
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
    int nj;
    nj = e->num_jogadas;
    while(nj < 32){
        e->jogadas[nj].jogador1.coluna = 4;
        e->jogadas[nj].jogador1.linha = 4;
        e->jogadas[nj].jogador2.coluna = 4;
        e->jogadas[nj].jogador2.linha = 4;
        nj++;
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

ESTADO * reset_tab (ESTADO *e){
    int i2 = 0;
    while (i2 < 8) {
        int i3 = 0;
        while (i3 < 8) {
            e->tab[i2][i3] = VAZIO;
            i3++;
        }
        i2++;
    }
    e -> tab[0][0] = UM;
    e -> tab[7][7] = DOIS;
    e -> tab[4][4] = PRETA;
    return e;
}

int *desenha_jogada(ESTADO *e, JOGADA jogada){
    int x1 = jogada.jogador1.coluna;
    int y1 = jogada.jogador1.linha;
    e->tab[y1][x1] = PRETA;
    int x2 = jogada.jogador2.coluna;
    int y2 = jogada.jogador2.linha;
    e->tab[y2][x2] = PRETA;
    return 0;
}


ESTADO *pos (ESTADO *e, int i){
    int in = 0;
    JOGADA play;
    reset_tab(e);
    int x;
    int y;
    while (in < i){
        play = e->jogadas[in];
        desenha_jogada(e,play);
        in++;
    }
    if(e->jogadas[in-1].jogador2.linha == 9){
        y = e->jogadas[in-1].jogador1.linha;
        x = e->jogadas[in-1].jogador1.coluna;
        e->tab[y][x] = BRANCA;
        e->ultima_jogada.coluna = x;
        e->ultima_jogada.linha = y;
        e->num_jogadas = i;
    }
    else{
        y = e->jogadas[in-1].jogador2.linha;
        x = e->jogadas[in-1].jogador2.coluna;
        e->tab[y][x] = BRANCA;
        e->ultima_jogada.coluna = x;
        e->ultima_jogada.linha = y;
        e->num_jogadas = i + 1;
    }
}

COORDENADA *offset(COORDENADA c, int x, int y){
    COORDENADA *r;
    r->linha = c.linha + y;
    r->coluna = c.coluna + x;
    return r;
}

LISTA casas_disp(ESTADO *e){
    COORDENADA c;
    c = e->ultima_jogada;
    LISTA l = criar_lista();
    COORDENADA *c1 = offset(c,0,1);
    COORDENADA *c2 = offset(c,0,(-1));
    COORDENADA *c3 = offset(c,1,0);
    COORDENADA *c4 = offset(c,(-1),0);
    COORDENADA *c5 = offset(c,1,1);
    COORDENADA *c6 = offset(c,(-1),1);
    COORDENADA *c7 = offset(c,1,(-1));
    COORDENADA *c8 = offset(c,(-1),(-1));
    if (e_peca(*c1))
        l = insere_cabeca(l,c1);
    if (e_peca(*c2))
        l = insere_cabeca(l,c2);
    if (e_peca(*c3))
        l = insere_cabeca(l,c3);
    if (e_peca(*c4))
        l = insere_cabeca(l,c4);
    if (e_peca(*c5))
        l = insere_cabeca(l,c5);
    if (e_peca(*c6))
        l = insere_cabeca(l,c6);
    if (e_peca(*c7))
        l = insere_cabeca(l,c7);
    if (e_peca(*c8))
        l = insere_cabeca(l,c8);
    return l;
}

COORDENADA rand_coord(LISTA l){
    srand((unsigned)time(NULL));
    int n;
    n = (rand() %7);
    while (n > 0){
        l = remove_cabeca(l);
        n--;
    }
    COORDENADA *c = (COORDENADA *) devolve_cabeca(l);
    return *c;
}

int jogs(ESTADO *e){
    jogar(e,rand_coord(casas_disp(e)));
    return 0;
}
