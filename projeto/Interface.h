/**
@file Interface.h
Esta camada é responsavel por mostrar informações relacionadas ao jogo.
 */

#ifndef TRABALHO_DE_LI_INTERFACE_H
#define TRABALHO_DE_LI_INTERFACE_H

#include "Dados.h"
#include "Logica.h"

/**
\brief Essa função cria um novo ficheiro onde é gravado o estado do jogo.
*/
int gravar(ESTADO *estado, char filename[]);
/**
\brief Essa função basicamente lê o ficheiro.
*/
int lerfich(char filename[], ESTADO *estado);
/**
\brief Essa função basicamente nos dá a coordenada atual.
@param coord É uma coordenada
*/
int write_coord(COORDENADA coord);
/**
\brief Essa função nos dá os movimentos realizados até o momento.
@param e É o estado do jogo
*/
int movs(ESTADO *e);
/**
\brief Essa função mostra o tabuleiro atualizado.
*/
void mostrar_tabuleiro (ESTADO *estado);
/**
\brief Essa função interpreta os comandos do utilizador.
*/
int interpretador(ESTADO *e);
/**
\brief Esta função escreve uma mensagem de erro.
*/
void erros(int n);

int char_int(char c);

#endif //TRABALHO_DE_LI_INTERFACE_H
