//
// Created by Thomaz on 12/03/2020.
//

#ifndef TRABALHO_DE_LI_LOGICA_H
#define TRABALHO_DE_LI_LOGICA_H

#include "Dados.h"
#include "Interface.h"

int e_vizinho (COORDENADA c1, COORDENADA c2);
int e_vazio (COORDENADA c3, ESTADO* state);
int e_peca (COORDENADA c);
int jogar(ESTADO *e, COORDENADA c);

#endif //TRABALHO_DE_LI_LOGICA_H
