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
    if (estado->tab[7][0])
        return 1;
    else if (estado->tab[0][7])
        return 2;
    else if (estado->jogador_atual == 1)
        return 2;
    else
        return 1;
}


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
        fprintf(fp,"0%d: %c%c %c%c\n",i+1,xc1,yc1,xc2,yc2);
        i++;
    }
    if (estado->jogador_atual == 2) {
        xc1 = conv_c(estado->jogadas[i].jogador1.coluna);
        yc1 = conv_l(estado->jogadas[i].jogador1.linha);
        fprintf(fp,"0%d: %c%c",estado->num_jogadas,xc1,yc1);
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
    int j1;
    int j2;
    int j;
    char ch1 = 'z';
    char ch2 ='z';
    int l1 = 9;
    int l2 = 9;
    while(fscanf(rf,"%d%d: %c%d %c%d ",j1,j2,ch1,l1,ch2,l2) != EOF){
        j = j1 * 10 + j2;
        guardar_jogada1(estado, j, ch1, l1);
        guardar_jogada2(estado, j, ch2, l2);
    }
    fclose(rf);
    mostrar_tabuleiro(estado);
    return 1;
}

int guardar_jogada1(ESTADO* e,int j, char cha, int l){
    int c;
    c = conv_c(cha);
    e->jogadas[j].jogador1.coluna = c;
    e->jogadas[j].jogador1.linha = l;
    return 0;
}

int guardar_jogada2(ESTADO* e,int j, char cha, int l){
    int c;
    c = conv_c(cha);
    e->jogadas[j].jogador2.coluna = c;
    e->jogadas[j].jogador2.linha = l;
    return 0;
}


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
    printf("(%d,%d) Player%d (%d)>", (estado->ultima_jogada.coluna), (estado->ultima_jogada.linha), njogador, jogadatual);
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
    char num[2];
    int n;
    if(sscanf(linha,"pos %s", num) == 1){
        n = atoi(num);
        pos(e,n);
        mostrar_tabuleiro(e);
    }
    if(strcmp(linha,"jog\n") == 0){
        jogs(e);
        mostrar_tabuleiro(e);
    }
    return 1;
}
