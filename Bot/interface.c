//
// Created by Thomaz on 12/03/2020.
//

#include "logica.h"
#include "dados.h"
#include <string.h>
#include <stdio.h>

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
    fprintf_s(fp,"\n");
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
            c = (char) fgetc(rf);
            if (c == '\n')
                nc--;
            else{
                alteracasa(estado, nc, nl, qualcasa(c));
                if(qualcasa(c) == BRANCA)
                    guarda_ultima_jog(estado,nl,nc);
            }
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
    int c1;
    int c2;
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
    }
    else{
        guardar_jogador(estado,2);
        guarda_num_jogs(estado, nj);
    }
    fclose(rf);
    return 1;
}

int char_int(char c){
    int x;
    x = c - 'a';
    return x;
}

void erros(int n){
    if(n==1)
        printf("Jogada Invalida\n");
}
