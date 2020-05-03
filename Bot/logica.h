#ifndef TRABALHO_DE_LI_LOGICA_H
#define TRABALHO_DE_LI_LOGICA_H

#include "dados.h"
#include "interface.h"
#include "listas.h"

int quem_ganha(ESTADO *estado);

int encurralado(ESTADO *estado);

int e_vizinho (COORDENADA c1, COORDENADA c2);

int e_vazio (COORDENADA c3, ESTADO* state);
int e_peca (COORDENADA c);
CASA qualcasa (char c);
int vencer(ESTADO *estado);
int jogar(ESTADO *e, COORDENADA c);
LISTA casas_disp(ESTADO *e, COORDENADA c);
double distancia(COORDENADA c1, COORDENADA c2);
COORDENADA euclidiana(LISTA l, int player);
int jogs2(ESTADO *e);

#endif //TRABALHO_DE_LI_LOGICA_H
