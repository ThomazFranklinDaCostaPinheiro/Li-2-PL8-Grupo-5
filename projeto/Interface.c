//
// Created by Thomaz on 12/03/2020.
//

#include "Logica.h"
#include "Dados.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int gravar(ESTADO *estado, char filename[]){
    FILE *fp;
    //strcat(filename,".txt");
    fp = fopen(filename,"w");
    int il = 7;
    while (il >= 0){
        int ic = 0;
        while (ic < 8){
            if (obter_casa(estado,il,ic) == UM)
                fprintf(fp,"1");
            else if (obter_casa(estado,il,ic) == DOIS)
                fprintf(fp,"2");
            else if (obter_casa(estado,il,ic) == VAZIO)
                fprintf(fp,".");
            else if (obter_casa(estado,il,ic) == BRANCA)
                fprintf(fp,"*");
            else
                fprintf(fp,"#");
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
    fprintf(fp,"\n");
    while (i < (obter_numero_de_jogadas(estado)-1)){
        xc1 = conv_c(obter_coluna(estado,1,i));
        yc1 = conv_l(obter_linha(estado,1,i));
        xc2 = conv_c(obter_coluna(estado,2,i));
        yc2 = conv_l(obter_linha(estado,2,i));
        fprintf(fp,"%02d: %c%c %c%c\n",i+1,xc1,yc1,xc2,yc2);
        i++;
    }
    if (obter_jogador_atual(estado) == 2) {
        xc1 = conv_c(obter_coluna(estado,1,i));
        yc1 = conv_l(obter_linha(estado,1,i));
        fprintf(fp,"%02d: %c%c",obter_numero_de_jogadas(estado),xc1,yc1);
    }
    fclose(fp);
    return(0);
}


int lerfich(char filename[], ESTADO *estado) {
    int nl = 7;
    int nc;
    char c;
    FILE *rf;
    if ((rf = fopen(filename, "r")) == NULL) {
        printf("Ficheiro nao encontrado>");
        return 0;
    }
    while (nl >= 0) {
        nc = 0;
        while (nc <= 7) {
            c = (char)fgetc(rf);
            if (c == '\n')
                nc--;
            else
                alteracasa(estado, nc, nl, qualcasa(c));
            nc++;
        }
        nl--;
    }
    fseek(rf, 82, SEEK_SET);
    char nj;
    char ch1 = 'e';
    char ch2 = 'e';
    char l1 = 5;
    char l2 = 5;
    int c1 = 5;
    int c2 = 5;
    while (fscanf(rf, "%c: %c%c %c%c\n", &nj, &ch1, &l1, &ch2, &l2) != EOF) {
        c1 = char_int(ch1);
        guarda_jogada(estado, 1, char_int(nj) - 1, char_int(l1) - 1, c1);
        c2 = char_int(ch2);
        guarda_jogada(estado, 2, char_int(nj) - 1, char_int(l2) - 1, c2);
        l2 = 5;
        ch2 = 'e';
    }
    guarda_num_jogs(estado, nj + 1);
    if ((obter_coluna(estado,2,nj) != 4)&&(obter_linha(estado,2,nj)) != 4){
        guardar_jogador(estado, 1);
        guarda_num_jogs(estado, nj + 1);
        guarda_ultima_jog(estado,l2-1,c2);
    }
    else{
        guardar_jogador(estado,2);
        guarda_num_jogs(estado, nj);
        guarda_ultima_jog(estado,l1-1,c1);
    }
    fclose(rf);
    mostrar_tabuleiro(estado);
    return 1;
}

int char_int(char c){
    int x;
    x = c - 'a';
    return x;
}

void mostrar_tabuleiro (ESTADO *estado){
    int il = 7;
    int njogador;
    int jogadatual;
    njogador = obter_jogador_atual(estado);
    jogadatual = obter_numero_de_jogadas(estado);
    while (il >= 0){
        int ic = 0;
        printf("%d ",(il+1));
        while (ic < 8){
            if (obter_casa(estado, il, ic) == UM)
                printf("1 ");
            else if (obter_casa(estado, il, ic) == DOIS)
                printf("2");
            else if (obter_casa(estado, il, ic) == VAZIO)
                printf(". ");
            else if (obter_casa(estado, il, ic) == BRANCA)
                printf("* ");
            else
                printf("# ");
            ic++;
        }
        printf("\n");
        il--;
    }
    printf ("  a b c d e f g h \n");
    printf("(%d,%d) Player%d (%d)>", (obter_coluna_ult(estado)), (obter_linha_ult(estado)), njogador, jogadatual);
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
    char n;
    if(sscanf(linha,"pos %c", &n ) == 1){
        pos(e,(int)(n-'0'));
        mostrar_tabuleiro(e);
    }
    if(strcmp(linha,"jog\n") == 0){
        jogs(e);
        mostrar_tabuleiro(e);
    }
    if(strcmp(linha,"jog2\n") == 0){
        jogs2(e);
        mostrar_tabuleiro(e);
    }
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
    printf("\n>");
    return 0;
}

void erros(int n){
    if(n==1)
        printf("Jogada Invalida\n");
}
