//
// Created by Thomaz on 12/03/2020.
//

#ifndef TRABALHO_DE_LI_INTERFACE_H
#define TRABALHO_DE_LI_INTERFACE_H

#include "Dados.h"
#include "Logica.h"

int quem_ganha(ESTADO *estado);
int encurralado(ESTADO *estado);
int gravar(ESTADO *estado, char filename[]);
int lerfich(char filename[], ESTADO *estado);
int vencer(ESTADO *estado);
void mostrar_tabuleiro (ESTADO *estado);
int interpretador(ESTADO *e);

#endif //TRABALHO_DE_LI_INTERFACE_H

