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
*/
int quem_ganha(ESTADO *estado);
/**
\brief Essa função indica se um jogador está encurralado, ou seja, sem possibilidades de jogar.
*/
int encurralado(ESTADO *estado);
/**
\brief Função que verifica se duas peças são vizinhas.
*/
int e_vizinho (COORDENADA c1, COORDENADA c2);
/** 
\brief Essa função determina se um jogador venceu.
*/
int vencer(ESTADO *estado);
/**
\brief Essa função verifica se a casa em que se pretende jogar está vazia ou não.
*/
int e_vazio (COORDENADA c3, ESTADO* state);
/**
\brief Função que verifica se a coordenada pertence ao tabuleiro.
*/
int e_peca (COORDENADA c);
/**
\brief Função que realiza a jogada.
*/
int jogar(ESTADO *e, COORDENADA c);
/**
\brief Essa função nos dá os movimentos realizados até o momento.
*/
int movs(ESTADO *e);
/**
\brief Essa função basicamente nos dá a coordenada atual.
*/
int write_coord(COORDENADA coord);
/**
\brief Esta função permite mover o jogo para qualquer uma das suas fases.
*/
ESTADO *pos (ESTADO *e, int i);
/**
\brief Função que limpa o tabuleiro
*/
ESTADO * reset_tab (ESTADO *e);
/** 
\brief Desenha no tabuleiro uma sequência dois movimentos 
*/
int *desenha_jogada(ESTADO *e, JOGADA jogada);
/**
\brief Cria uma lista das casas disponiveis em torno da peça branca 
*/
LISTA casas_disp(ESTADO *e);
/**
\brief Devolve uma coordenada aleatória
*/
COORDENADA rand_coord(LISTA l);
/** 
\brief Realiza uma jogada segundo um algoritmo aleatório
*/
int jogs(ESTADO *e);
/** 
\brief Devolve uma coordenada segundo a heuristica da distancia euclidiana.
*/
COORDENADA euclidiana(LISTA l, int player);
/**
\brief Calcula a distancia entre dois pontos. 
*/
double distancia(COORDENADA c1, COORDENADA c2);
/**
\brief Realiza uma jogada segundo um algoritmo de distância euclidiana.
*/
int jogs2(ESTADO *e);

#endif //TRABALHO_DE_LI_LOGICA_H
