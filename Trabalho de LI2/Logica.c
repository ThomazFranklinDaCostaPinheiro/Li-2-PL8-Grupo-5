//
// Created by Thomaz on 12/03/2020.
//

#include "Dados.h"
#include "Logica.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Listas.h"

int quem_ganha(ESTADO *estado){
    if ((obter_linha_ult(estado) == 0)&&(obter_coluna_ult(estado) == 0))
        return 1;
    else if ((obter_linha_ult(estado) == 7)&&(obter_coluna_ult(estado) == 7))
        return 2;
    else if (obter_jogador_atual(estado) == 1)
        return 2;
    else
        return 1;
}


int encurralado(ESTADO *estado){
    int x = obter_coluna_ult(estado);
    int y = obter_linha_ult(estado);
    int i1 = y-1;
    int i2;
    while (i1 <= y+1){
        i2 = x-1;
        while (i2 <= x + 1){
            if (obter_casa(estado, i1, i2) == VAZIO)
                return 0;
            i2++;
        }
        i1++;
    }
    return 1;
}

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
    if (obter_casa(state, y3, x3)==VAZIO || obter_casa(state, y3, x3)==UM || obter_casa(state, y3, x3)==DOIS)
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
    xu = obter_coluna_ult(e);
    yu = obter_linha_ult(e);
    int l;
    int co;
    l = c.linha;
    co = c.coluna;
    if ((e_vazio(c,e)) && (e_vizinho(c, obter_coord_ult(e))) && (e_peca(c))) {
        alteracasa(e,xu,yu,PRETA);
        alteracasa(e,co,l,BRANCA);
        if (obter_jogador_atual(e) == 1){
            guarda_jogada_coord(e,1,obter_numero_de_jogadas(e)-1,c);
            guardar_jogador(e,2);
        }
        else {
            guarda_jogada_coord(e,2,obter_numero_de_jogadas(e)-1,c);
            guardar_jogador(e,1);
            guarda_num_jogs(e,obter_numero_de_jogadas(e)+1);
        }
        guarda_ultima_jog(e,l,co);
    }
    else{
        printf("Jogada Invalida\n");
        alteracasa(e,xu,yu,BRANCA);
    }
    int nj;
    nj = obter_numero_de_jogadas(e);
    while(nj < 32){
        guarda_jogada(e,1,nj,4,4);
        guarda_jogada(e,2,nj,4,4);
        nj++;
    }
    return 1;
}

int vencer(ESTADO *estado){
    if ((obter_linha_ult(estado) == 0)&&(obter_coluna_ult(estado) == 0))
        return 0;
    else if ((obter_linha_ult(estado) == 7)&&(obter_coluna_ult(estado) == 7))
        return 0;
    else if (encurralado(estado))
        return 0;
    else
        return 1;
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
    while (i < (obter_numero_de_jogadas(e)-1)){
        printf("j%d: ",(i+1));
        write_coord(obter_coord(e, 1, i));
        write_coord(obter_coord(e, 2, i));
        printf("\n");
        i++;
    }
    if (obter_jogador_atual(e) == 2) {
        printf("j%d: ",i+1);
        write_coord(obter_coord(e, 1, i));
    }
    return 0;
}

ESTADO * reset_tab (ESTADO *e){
    int i2 = 0;
    while (i2 < 8) {
        int i3 = 0;
        while (i3 < 8) {
            alteracasa(e,i2,i3,VAZIO);
            i3++;
        }
        i2++;
    }
    alteracasa(e,0,0,UM);
    alteracasa(e,7,7,DOIS);
    alteracasa(e,4,4,PRETA);
    return e;
}

int *desenha_jogada(ESTADO *e, JOGADA jogada){
    int x1 = jogada.jogador1.coluna;
    int y1 = jogada.jogador1.linha;
    alteracasa(e,x1,y1,PRETA);
    int x2 = jogada.jogador2.coluna;
    int y2 = jogada.jogador2.linha;
    alteracasa(e,x2,y2,PRETA);
    return 0;
}


ESTADO *pos (ESTADO *e, int i){
    int in = 0;
    JOGADA play;
    reset_tab(e);
    int x;
    int y;
    if (i == 0){
        reset_tab(e);
        alteracasa(e,4,4,BRANCA);
        guarda_ultima_jog(e,4,4);
    }
    else{
        while (in < i){
            play = obter_jogadas(e, in);
            desenha_jogada(e,play);
            in++;
        }
        if(obter_linha(e,2,in-1) == 9){
            y = obter_linha(e,1,in-1);
            x = obter_coluna(e,1,in-1);
            alteracasa(e,x,y,BRANCA);
            guarda_ultima_jog(e,y,x);
            guarda_num_jogs(e,i);
        }
        else{
            y = obter_linha(e,2,in-1);
            x = obter_coluna(e,2,in-1);
            alteracasa(e,x,y,BRANCA);
            guarda_ultima_jog(e,y,x);
            guarda_num_jogs(e,i);
        }
    }
}

LISTA casas_disp(ESTADO *e){
    COORDENADA c;
    c = obter_coord_ult(e);
    LISTA l = criar_lista();
    COORDENADA *c1 = malloc(sizeof(NODO));
    COORDENADA *c2 = malloc(sizeof(NODO));
    COORDENADA *c3 = malloc(sizeof(NODO));
    COORDENADA *c4 = malloc(sizeof(NODO));
    COORDENADA *c5 = malloc(sizeof(NODO));
    COORDENADA *c6 = malloc(sizeof(NODO));
    COORDENADA *c7 = malloc(sizeof(NODO));
    COORDENADA *c8 = malloc(sizeof(NODO));
    c1->coluna = c.coluna+1;
    c1->linha = c.linha+1;
    c2->coluna = c.coluna+1;
    c2->linha = c.linha;
    c3->coluna = c.coluna+1;
    c3->linha = c.linha-1;
    c4->coluna = c.coluna;
    c4->linha = c.linha+1;
    c5->coluna = c.coluna;
    c5->linha = c.linha-1;
    c6->coluna = c.coluna-1;
    c6->linha = c.linha+1;
    c7->coluna = c.coluna-1;
    c7->linha = c.linha;
    c8->coluna = c.coluna-1;
    c8->linha = c.linha-1;
    if (e_peca(*c1)&&(e_vazio(*c1,e)))
        l = insere_cabeca(l,c1);
    if (e_peca(*c2)&&(e_vazio(*c2,e)))
        l = insere_cabeca(l,c2);
    if (e_peca(*c3)&&(e_vazio(*c3,e)))
        l = insere_cabeca(l,c3);
    if (e_peca(*c4)&&(e_vazio(*c4,e)))
        l = insere_cabeca(l,c4);
    if (e_peca(*c5)&&(e_vazio(*c5,e)))
        l = insere_cabeca(l,c5);
    if (e_peca(*c6)&&(e_vazio(*c6,e)))
        l = insere_cabeca(l,c6);
    if (e_peca(*c7)&&(e_vazio(*c7,e)))
        l = insere_cabeca(l,c7);
    if (e_peca(*c8)&&(e_vazio(*c8,e)))
        l = insere_cabeca(l,c8);
    return l;
}

COORDENADA rand_coord(LISTA l){
    srand((unsigned)time(NULL));
    int n;
    n = (rand() %7);
    //printf("%d\n",n);
    while ((proximo(l)) && (n > 0)){
        //printf("%d Eureka\n", n);
        l = remove_cabeca(l);
        n--;
    }
    COORDENADA c = *(COORDENADA *) devolve_cabeca(l);
    while (!lista_esta_vazia(l))
        l = remove_cabeca(l);
    return c;
}

int jogs(ESTADO *e){
    jogar(e,rand_coord(casas_disp(e)));
    return 0;
}

double distancia(COORDENADA c1, COORDENADA c2){
    double r;
    int x1 = c1.coluna;
    int x2 = c2.coluna ;
    int y1 = c1.linha;
    int y2 = c1.linha;
    r = abs(x1 - x2) + abs(y1 - y2);
    return r;
}

COORDENADA euclidiana(LISTA l, int player){
    COORDENADA c;
    COORDENADA casa1;
    COORDENADA cabeca;
    casa1.coluna = 0;
    casa1.linha = 0;
    COORDENADA casa2;
    casa2.coluna = 7;
    casa2.linha = 7;
    c = *(COORDENADA *)devolve_cabeca(l);
    while (!lista_esta_vazia(l) && !lista_esta_vazia(proximo(l))){
        cabeca = *(COORDENADA *)(devolve_cabeca(l));
        if(player == 1){
            if(distancia(cabeca,casa1) < distancia(c,casa1)){
                c = cabeca;
            }
        }
        else{
            if(distancia(cabeca,casa2) < distancia(c,casa2)){
                c = cabeca;
            }
        }
        l = proximo(l);
    }
    return c;
}

int jogs2(ESTADO *e){
    jogar(e,euclidiana(casas_disp(e),obter_jogador_atual(e)));
    return 0;
}

COORDENADA altera_coord(COORDENADA c, int x, int y){
    c.coluna = c.coluna + x;
    c.linha = c.linha + y;
    return c;
}

COORDENADA flood(ESTADO *e){
    int flood[8][8];
    int x;
    int y;

}

int floodaux(ESTADO *es, int flood[8][8], COORDENADA c, int val){
    

}
