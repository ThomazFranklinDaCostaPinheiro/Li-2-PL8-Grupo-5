/**
@file Logica.h
Essa camada é responsável pela lógica por tras do jogo.
 */

#ifndef TRABALHO_DE_LI_LOGICA_H
#define TRABALHO_DE_LI_LOGICA_H

#include "dados.h"
#include "interface.h"
#include "listas.h"

/**
\brief Essa função determina quem foi o vencedor do jogo.
*/
int quem_ganha(ESTADO *estado);

/**
\brief Essa função indica se um jogador está encurralado, ou seja, sem possibilidades de jogar.
*/
int encurralado(ESTADO *estado);

/**
\brief Função que verifica se duas peças são vizinhas.
 @param c1 Primeira coordenanda
 @param c2 Segunda coordenada
 @returns se for vizinho = 1, se não for = 0.
*/
int e_vizinho (COORDENADA c1, COORDENADA c2);

/**
\brief Essa função verifica se a casa em que se pretende jogar está vazia ou não.
@param c3 Coordenada a verificar
@param state Estado atual do jogo
@returns se for vazio = 1, se não for = 0.
*/
int e_vazio (COORDENADA c3, ESTADO* state);

/**
\brief Função que verifica se a coordenada pertence ao tabuleiro.
@param c Coordenada a ser verificada
@return Se for peça = 1, se não for = 0.
*/
int e_peca (COORDENADA c);

/**
\brief Função que devolve a casa associada com o caracter
@param c caracter a ser testado
@return casa associada ao caracter
 */
CASA qualcasa (char c);

/**
\brief Essa função determina se um jogador venceu.
*/
int vencer(ESTADO *estado);

/**
\brief Função que realiza a jogada.
@param e É o estado do jogo que será alterado
*/
int jogar(ESTADO *e, COORDENADA c);

/**
\brief Função que limpa o tabuleiro
*/
ESTADO * reset_tab (ESTADO *e);

/**
\brief Desenha no tabuleiro uma sequência dois movimentos
@param e É o estado que vai ser alterado
@param jogada É a jogada que vai ser desenhada
*/
int *desenha_jogada(ESTADO *e, JOGADA jogada);

/**
\brief Esta função permite mover o jogo para qualquer uma das suas fases.
@param e É o estado solicitado
@param i É a posição solicitada
*/
void pos (ESTADO *e, int i);

/**
\brief Cria uma lista das casas disponiveis em torno da peça branca
@param e Estado atual do tabuleiro
*/
LISTA casas_disp(ESTADO *e, COORDENADA c);

/**
\brief Devolve uma coordenada aleatória
@param l lista de coordenadas.
*/
COORDENADA rand_coord(LISTA l);

/**
\brief Realiza uma jogada segundo um algoritmo aleatório
@param e Estado a ser alterado aleatoriamente.
*/
int jogs(ESTADO *e);

/**
\brief Calcula a distancia entre dois pontos.
*/
double distancia(COORDENADA c1, COORDENADA c2);

/**
\brief Devolve uma coordenada segundo a heuristica da distancia euclidiana.
*/
COORDENADA euclidiana(LISTA l, int player);

/**
\brief Realiza uma jogada segundo um algoritmo de distância euclidiana.
*/
int jogs2(ESTADO *e);

int converte_tabaux(CASA c);
int ini_flood();


#endif //TRABALHO_DE_LI_LOGICA_H

