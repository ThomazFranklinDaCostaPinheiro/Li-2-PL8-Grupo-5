#ifndef TRABALHO_DE_LI_INTERFACE_H
#define TRABALHO_DE_LI_INTERFACE_H

#include "dados.h"
#include "logica.h"

int gravar(ESTADO *estado, char filename[]);
int lerfich(char filename[], ESTADO *estado);
void erros(int n);
int char_int(char c);


#endif //TRABALHO_DE_LI_INTERFACE_H

