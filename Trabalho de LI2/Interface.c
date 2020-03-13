//
// Created by Thomaz on 12/03/2020.
//

#include "Interface.h"
#include <string.h>
#include <stdio.h>
#include "Dados.h"
#include <string.h>

#define BUF_SIZE 1024

int jogar(ESTADO *e, COORDENADA c);

void mostrar_tabuleiro(ESTADO estado){
    int il = 0;
    while (il < 8){
        int ic = 0;
        while (ic < 8){
            if ((ic == 0) && (il == 7))
                printf("1 ");
            else if ((ic == 7) && (il == 0))
                printf("2");
            else if (estado.tab[il][ic] == VAZIO)
                printf(". ");
            else if (estado.tab[il][ic] == BRANCA)
                printf("* ");
            else
                printf("# ");
            ic++;
        }
        printf("\n");
        il++;
    }
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(*e);
    }
    return 1;
}
