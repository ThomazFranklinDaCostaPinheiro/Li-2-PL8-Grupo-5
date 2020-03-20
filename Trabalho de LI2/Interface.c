//
// Created by Thomaz on 12/03/2020.
//

#include "Logica.h"
#include "Dados.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024


int quem_ganha(ESTADO *estado){
    if (estado->tab[0][7])
        return 1;
    else if (estado->tab[7][0])
        return 2;
    else if (estado->jogador_atual == 1)
        return 2;
    else
        return 1;
}

int vencer(ESTADO *estado){
    if (((estado->ultima_jogada.linha == 7)&&(estado->ultima_jogada.coluna) == 0))
        return 0;
    else if (((estado->ultima_jogada.linha == 0)&&(estado->ultima_jogada.coluna) == 7))
        return 0;
    else
        return 1;
}

void mostrar_tabuleiro (ESTADO *estado){
    int il = 0;
    int ncomandos;
    int njogador;
    int jogadatual;
    ncomandos = estado->num_jogadas;
    njogador = estado->jogador_atual;
    jogadatual = (estado->num_jogadas/2);
    while (il < 8){
        int ic = 0;
        printf("%d ", (il+1));
        while (ic < 8){
            if (estado->tab[il][ic] == UM)
                printf("1 ");
            else if (estado->tab[il][ic] == DOIS)
                printf("2");
            else if (estado->tab[il][ic] == VAZIO)
                printf(". ");
            else if (estado->tab[il][ic] == BRANCA)
                printf("* ");
            else
                printf("# ");
            ic++;
        }
        printf("\n");
        il++;
    }
    printf ("  a b c d e f g h \n");
    printf("(%d,%d)#%d Player%d (%d)>", (estado->ultima_jogada.coluna+1), (estado->ultima_jogada.linha+1), ncomandos, njogador, jogadatual);
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
    return 1;
}
