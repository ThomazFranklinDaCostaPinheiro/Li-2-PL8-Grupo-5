//
// Created by Thomaz on 12/03/2020.
//

#ifndef TRABALHO_DE_LI_INTERFACE_H
#define TRABALHO_DE_LI_INTERFACE_H

#include "Dados.h"
#include "Logica.h"

/** Essa função cria um novo ficheiro onde é gravado o estado do jogo.*/
int gravar(ESTADO *estado, char filename[]);
/** Essa função basicamente lê o ficheiro.*/
int lerfich(char filename[], ESTADO *estado);
/** Essa função mostra o tabuleiro atualizado.*/
void mostrar_tabuleiro (ESTADO *estado);
/** Essa função interpreta os comandos do utilizador.*/
int interpretador(ESTADO *e);
int char_int(char c);


#endif //TRABALHO_DE_LI_INTERFACE_H
