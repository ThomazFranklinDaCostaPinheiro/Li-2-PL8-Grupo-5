//
// Created by Thomaz on 12/03/2020.
//

#include "Logica.h"
#include "Dados.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


#define BUF_SIZE 1024

/** Essa função determina quem foi o vencedor do jogo.*/

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

/** Essa função indica se um jogador está encurralado, ou seja, sem possibilidades de jogar.*/

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

/** Essa função cria um novo ficheiro onde é gravado o estado do jogo.*/

int gravar(ESTADO *estado, char filename[]){
    FILE *fp;
    strcat(filename,".txt");
    fp = fopen(filename,"w");
    int il = 7;
    int ncomandos;
    int njogador;
    int jogadatual;
    ncomandos = estado->num_jogadas;
    njogador = estado->jogador_atual;
    jogadatual = (estado->num_jogadas/2);
    while (il >= 0){
        int ic = 0;
        fprintf(fp,"%d ",(il+1));
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
    fprintf (fp,"  A B C D E F G H \n");
    fprintf(fp,"(%d,%d)#%d Player%d (%d)", (estado->ultima_jogada.coluna+1), (estado->ultima_jogada.linha+1), ncomandos, njogador, jogadatual);
    fclose(fp);
}

/** Essa função basicamente lê o ficheiro.*/

int lerfich(char filename[], ESTADO *estado){
    FILE *rf;
    strcat(filename,".txt");
    if((rf = fopen(filename,"r")) == NULL){
        printf("Ficheiro nao encontrado>");
        return 0;
    }
    char p;
    while((p = fgetc(rf)) != EOF)
        putchar(p);
    fclose(rf);
    return 1;
}

/** Essa função determina se um jogador venceu.*/

int vencer(ESTADO *estado){
    if ((estado->ultima_jogada.linha == 7)&&(estado->ultima_jogada.coluna == 0))
        return 0;
    else if ((estado->ultima_jogada.linha == 7)&&(estado->ultima_jogada.coluna == 0))
        return 0;
    else if (encurralado(estado))
        return 0;
    else
        return 1;
}
/* Essa função mostra o tabuleiro atualizado.*/

void mostrar_tabuleiro (ESTADO *estado){
    int il = 7;
    int ncomandos;
    int njogador;
    int jogadatual;
    ncomandos = estado->num_jogadas;
    njogador = estado->jogador_atual;
    jogadatual = (estado->num_jogadas/2);
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
    printf("(%d,%d)#%d Player%d (%d)>", (estado->ultima_jogada.coluna+1), (estado->ultima_jogada.linha+1), ncomandos, njogador, jogadatual);
}

/** Essa função interpreta os comandos do utilizador.*/

int interpretador(ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    int in1 = 0;
    int in2 = 0;
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
    return 1;
}
