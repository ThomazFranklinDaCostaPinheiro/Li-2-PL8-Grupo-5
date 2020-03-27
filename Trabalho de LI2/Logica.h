//
// Created by Thomaz on 12/03/2020.
//

#ifndef TRABALHO_DE_LI_LOGICA_H
#define TRABALHO_DE_LI_LOGICA_H

#include "Dados.h"
#include "Interface.h"

/**Função que verifica se duas peças são vizinhas.*/
int e_vizinho (COORDENADA c1, COORDENADA c2);

/** Essa função verifica se a casa em que se pretende jogar está vazia ou não.*/
int e_vazio (COORDENADA c3, ESTADO* state);

/** Função que verifica se a coordenada pertence ao tabuleiro.*/
int e_peca (COORDENADA c);

/**Função que realiza a jogada.*/
int jogar(ESTADO *e, COORDENADA c);

#endif //TRABALHO_DE_LI_LOGICA_H
