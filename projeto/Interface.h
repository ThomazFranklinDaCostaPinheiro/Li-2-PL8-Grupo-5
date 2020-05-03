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
@param estado É o estado do jogo a ser gravado.
@param filename É o nome do ficheiro.
*/
int gravar(ESTADO *estado, char filename[]);
/**
\brief Essa função basicamente lê o ficheiro.
@param filename É o nome do ficheiro.
@param estado É o estado a ser alterado.
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
@param estado É o estado a ser mostrado.
*/
void mostrar_tabuleiro (ESTADO *estado);
/**
\brief Essa função interpreta os comandos do utilizador.
@param e É o estado atual.
*/
int interpretador(ESTADO *e);
/**
\brief Esta função escreve uma mensagem de erro.
@param n É o indicador do erro
*/
void erros(int n);

/**
\brief Essa função passa um char para um int.
@param c É o char a ser convertido.
*/
int char_int(char c);

#endif //TRABALHO_DE_LI_INTERFACE_H
