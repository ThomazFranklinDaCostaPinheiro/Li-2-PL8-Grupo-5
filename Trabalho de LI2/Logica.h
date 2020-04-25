//
// Created by Thomaz on 12/03/2020.
//

#ifndef TRABALHO_DE_LI_LOGICA_H
#define TRABALHO_DE_LI_LOGICA_H

#include "Dados.h"
#include "Interface.h"
#include "Listas.h"

/** Essa função determina quem foi o vencedor do jogo.*/
int quem_ganha(ESTADO *estado);
/** Essa função indica se um jogador está encurralado, ou seja, sem possibilidades de jogar.*/
int encurralado(ESTADO *estado);
/**Função que verifica se duas peças são vizinhas.*/
int e_vizinho (COORDENADA c1, COORDENADA c2);
/** Essa função determina se um jogador venceu.*/
int vencer(ESTADO *estado);
/** Essa função verifica se a casa em que se pretende jogar está vazia ou não.*/
int e_vazio (COORDENADA c3, ESTADO* state);
/** Função que verifica se a coordenada pertence ao tabuleiro.*/
int e_peca (COORDENADA c);
/**Função que realiza a jogada.*/
int jogar(ESTADO *e, COORDENADA c);
/** Essa função nos dá os movimentos realizados até o momento. */
int movs(ESTADO *e);
/** Essa função basicamente nos dá a coordenada atual.*/
int write_coord(COORDENADA coord);
/** Esta função permite mover o jogo para qualquer uma das suas fases. */
ESTADO *pos (ESTADO *e, int i);
/** Função que limpa o tabuleiro */
ESTADO * reset_tab (ESTADO *e);
/** Desenha no tabuleiro uma sequência dois movimentos */
int *desenha_jogada(ESTADO *e, JOGADA jogada);
/** Função que devolve uma coordenada a que foi adicionad os valores x e y */
COORDENADA *offset(COORDENADA c, int x, int y);
/** Cria uma lista das casas disponiveis em torno da peça branca */
LISTA casas_disp(ESTADO *e);
/** Devolve uma coordenada aleatória */
COORDENADA rand_coord(LISTA l);
/** Realiza uma jogada segundo um algoritmo */
int jogs(ESTADO *e);

#endif //TRABALHO_DE_LI_LOGICA_H
