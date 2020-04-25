//
// Created by Thomaz on 12/03/2020.
//

#ifndef TRABALHO_DE_LI_LOGICA_H
#define TRABALHO_DE_LI_LOGICA_H

#include "Dados.h"
#include "Interface.h"
#include "Listas.h"

int quem_ganha(ESTADO *estado);
int encurralado(ESTADO *estado);
/**Função que verifica se duas peças são vizinhas.*/
int e_vizinho (COORDENADA c1, COORDENADA c2);
/** Essa função verifica se a casa em que se pretende jogar está vazia ou não.*/
int e_vazio (COORDENADA c3, ESTADO* state);
/** Função que verifica se a coordenada pertence ao tabuleiro.*/
int e_peca (COORDENADA c);
/**Função que realiza a jogada.*/
int jogar(ESTADO *e, COORDENADA c);
/** Essa função nos dá os movimentos realizados até o momento. */
int movs(ESTADO *e);
/** Essa função basicamente nos dá a coordenada atual.*/
int write_coord(COORDENADA coord);

ESTADO *pos (ESTADO *e, int i);
ESTADO * reset_tab (ESTADO *e);
int *desenha_jogada(ESTADO *e, JOGADA jogada);
ESTADO *pos (ESTADO *e, int i);
COORDENADA *offset(COORDENADA c, int x, int y);
LISTA casas_disp(ESTADO *e);
COORDENADA rand_coord(LISTA l);
int jogs(ESTADO *e);
int vencer(ESTADO *estado);

#endif //TRABALHO_DE_LI_LOGICA_H
