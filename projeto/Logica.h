/**
@file Logica.h
Essa camada é responsável pela lógica por tras do jogo.
 */

#ifndef TRABALHO_DE_LI_LOGICA_H
#define TRABALHO_DE_LI_LOGICA_H

#include "Dados.h"
#include "Interface.h"
#include "Listas.h"

/**
\brief Essa função determina quem foi o vencedor do jogo.
@param estado O estado do jogo.
@returns O número do jogador que vence.
*/
int quem_ganha(ESTADO *estado);

/**
\brief Essa função indica se um jogador está encurralado, ou seja, sem possibilidades de jogar.
@param estado O estado do Jogo.
@returns 1 se o jogador estiver encurralado e 0 caso cntrário.
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
@returns Se for peça = 1, se não for = 0.
*/
int e_peca (COORDENADA c);

/**
\brief Função que devolve a casa associada com o caracter 
@param c caracter a ser testado
@returns casa associada ao caracter
 */
CASA qualcasa (char c);

/**
\brief Essa função determina se um jogador venceu.
@param estado O estado do jogo.
@returns 0 se alguém vencer e 1 se não houver vencedor.
*/
int vencer(ESTADO *estado);

/**
\brief Função que realiza a jogada.
@param e É o estado do jogo que será alterado
*/
int jogar(ESTADO *e, COORDENADA c);

/**
\brief Função que limpa o tabuleiro
@param e O estado do jogo.
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
@param e Estado atual do tabuleiro.
@param c A coordenada a ser testada.
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
@param c1 A primeira coordenada.
@param c2 A segunda coordenada.
@returns r A distância euclidiana.
*/
double distancia(COORDENADA c1, COORDENADA c2);

/**
\brief Devolve uma coordenada segundo a heuristica da distancia euclidiana.
@param l Lista de coordenadas disponiveis.
@param player O jogador em questão.
@returns c A coordenada do jogador em questão.
*/
COORDENADA euclidiana(LISTA l, int player);

/**
\brief Realiza uma jogada segundo um algoritmo de distância euclidiana.
@param e O estado em que vai ser feita a jogada
*/
int jogs2(ESTADO *e);


#endif //TRABALHO_DE_LI_LOGICA_H
