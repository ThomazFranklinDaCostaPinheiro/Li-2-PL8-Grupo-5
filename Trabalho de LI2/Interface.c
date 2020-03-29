//
// Created by Thomaz on 12/03/2020.
//

#include "Logica.h"
#include "Dados.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



#define BUF_SIZE 1024

// Essa função determina quem foi o vencedor do jogo.

int quem_ganha(ESTADO *estado){
    if (estado->tab[7][0])
        return 1;
    else if (estado->tab[0][7])
        return 2;
    else if (estado->jogador_atual == 1)
        return 2;
    else
        return 1;
}

// Essa função indica se um jogador está encurralado, ou seja, sem possibilidades de jogar.

int encurralado(ESTADO *estado){
    int x = estado->ultima_jogada.coluna;
    int y = estado->ultima_jogada.linha;
    int i1 = y-1;
    int i2;
    while (i1 <= y+1){
        i2 = x-1;
        while (i2 <= x + 1){
            if (estado->tab[i1][i2] == VAZIO)
                return 0;
            i2++;
        }
        i1++;
    }
    return 1;
}


// Essa função cria um novo ficheiro onde é gravado o estado do jogo.

int gravar(ESTADO *estado, char filename[]){
    FILE *fp;
    strcat(filename,".txt");
    fp = fopen(filename,"w");
    int il = 7;
    int njogador;
    int jogadatual;
    njogador = estado->jogador_atual;
    jogadatual = estado->num_jogadas;
    while (il >= 0){
        int ic = 0;
        while (ic < 8){
            if (estado->tab[il][ic] == UM)
                fprintf(fp,"1 ");
            else if (estado->tab[il][ic] == DOIS)
                fprintf(fp,"2");
            else if (estado->tab[il][ic] == VAZIO)
                fprintf(fp,". ");
            else if (estado->tab[il][ic] == BRANCA)
                fprintf(fp,"* ");
            else
                fprintf(fp,"# ");
            ic++;
        }
        fprintf(fp,"\n");
        il--;
    }
    int i = 0;
    char xc1;
    char yc1;
    char xc2;
    char yc2;
    while (i < (estado->num_jogadas-1)){
        xc1 = conv_c(estado->jogadas[i].jogador1.coluna);
        yc1 = conv_l(estado->jogadas[i].jogador1.linha);
        xc2 = conv_c(estado->jogadas[i].jogador2.coluna);
        yc2 = conv_l(estado->jogadas[i].jogador2.linha);
        fprintf(fp,"%c%c %c%c\n",xc1,yc1,xc2,yc2);
        i++;
    }
    if (estado->jogador_atual == 2) {
        xc1 = conv_c(estado->jogadas[i].jogador1.coluna);
        yc1 = conv_l(estado->jogadas[i].jogador1.linha);
        fprintf(fp,"%c%c",xc1,yc1);
    }
    fclose(fp);
    return(0);
}

CASA qualcasa (char c){
    if (c == '#')
        return PRETA;
    else if (c == '*')
        return BRANCA;
    else if (c == '2')
        return DOIS;
    else if (c == '1')
        return UM;
    else
        return VAZIO;
}

int armazenar(ESTADO *e,JOGADA jogada, int i){
    e->jogadas[i].jogador1 = jogada.jogador1;
    if ((e->jogadas[i].jogador2.coluna != 9)&&(e->jogadas[i].jogador2.linha != 9))
        e->jogadas[i].jogador2 = jogada.jogador2;
}

COORDENADA conversor(char linha[]){
    char col;
    char lin;
    int x;
    int y;
    COORDENADA coord;
    sscanf(linha, "%c%c", col, lin);
    x = col;
    y = lin;
    coord.coluna = x;
    coord.linha = y;
    return coord;
}

int lerfich(char filename[], ESTADO *estado){
    int nl = 7;
    int nc;
    char c;
    FILE *rf;
    strcat(filename,".txt");
    if((rf = fopen(filename,"r")) == NULL){
        printf("Ficheiro nao encontrado>");
        return 0;
    }
    while(nl >= 0){
        nc = 0;
        while(nc <= 7){
            c = fgetc(rf);
            if (c == ' ')
                nc--;
            else if (c == '\n')
                nc--;
            else
                estado->tab[nl][nc] = qualcasa(c);
            nc++;
        }
        nl--;
    }
    fseek(rf,3,SEEK_CUR);
    char linha[BUF_SIZE];
    int i = 0;
    while(fgets(linha, BUF_SIZE,rf) != NULL){
        char j1[BUF_SIZE];
        char j2[BUF_SIZE];
        if (sscanf(linha, "%s %s", j1, j2) == 2){
            COORDENADA coord1 = conversor(j1);
            COORDENADA coord2 = conversor(j2);
            armazenar(estado, (JOGADA) {coord1, coord2}, i);
            i++;
            //printf("%d%d %d%d",coord1.coluna,coord1.linha,coord2.coluna,coord2.linha);
            //printf("%s\n", j1);
        }
        else {
            COORDENADA coord1 = conversor(j1);
            COORDENADA coord2 = {9,9};
            armazenar(estado, (JOGADA) {coord1, coord2}, i);
        }
    }
    fclose(rf);
    mostrar_tabuleiro(estado);
    return 1;
}


// Essa função determina se um jogador venceu.

int vencer(ESTADO *estado){
    if ((estado->ultima_jogada.linha == 0)&&(estado->ultima_jogada.coluna == 7))
        return 0;
    else if ((estado->ultima_jogada.linha == 7)&&(estado->ultima_jogada.coluna == 0))
        return 0;
    else if (encurralado(estado))
        return 0;
    else
        return 1;
}

void mostrar_tabuleiro (ESTADO *estado){
    int il = 7;
    int njogador;
    int jogadatual;
    njogador = estado->jogador_atual;
    jogadatual = estado->num_jogadas;
    while (il >= 0){
        int ic = 0;
        printf("%d ",(il+1));
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
        il--;
    }
    printf ("  a b c d e f g h \n");
    printf("(%d,%d) Player%d (%d)>", (estado->ultima_jogada.coluna+1), (estado->ultima_jogada.linha+1), njogador, jogadatual);
}

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2){
        COORDENADA coord = {*col - 'a', *lin - '1'};
        jogar(e, coord);
        mostrar_tabuleiro(e);
    }
    char fich[BUF_SIZE];
    if(strcmp(linha, "Q\n") == 0)
        exit(0);
    if(sscanf(linha,"gr %s", fich) == 1){
        gravar(e, fich);
        printf("Jogo Gravado\n");
        mostrar_tabuleiro(e);
    }
    if(sscanf(linha,"ler %s", fich) == 1){
        lerfich(fich,e);
    }
    if(strcmp(linha,"movs\n") == 0){
        movs(e);
    }
    char debug1;
    char debug2;
    if(sscanf(linha,"conv %c%c)",debug1,debug2) == 2){
        //COORDENADA cord;
        printf("Olá");
        //cord = conversor(linha);
        //printf("%d,%d",cord.coluna, cord.linha);
    }
    return 1;
}
