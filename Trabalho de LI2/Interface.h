//
// Created by Thomaz on 12/03/2020.
//

#ifndef TRABALHO_DE_LI_INTERFACE_H
#define TRABALHO_DE_LI_INTERFACE_H

#include "Dados.h"
#include "Logica.h"

/** Essa função determina quem foi o vencedor do jogo.*/
int quem_ganha(ESTADO *estado);

/** Essa função indica se um jogador está encurralado, ou seja, sem possibilidades de jogar.*/
int encurralado(ESTADO *estado);

/** Essa função cria um novo ficheiro onde é gravado o estado do jogo.*/
int gravar(ESTADO *estado, char filename[]);

int armazenar(ESTADO *e,JOGADA jogada, int i);
COORDENADA conversor(char linha[]);

/** Essa função basicamente lê o ficheiro.*/
int lerfich(char filename[], ESTADO *estado);

/** Essa função determina se um jogador venceu.*/
int vencer(ESTADO *estado);

/* Essa função mostra o tabuleiro atualizado.*/
void mostrar_tabuleiro (ESTADO *estado);

/** Essa função interpreta os comandos do utilizador.*/
int interpretador(ESTADO *e);

#endif //TRABALHO_DE_LI_INTERFACE_H

