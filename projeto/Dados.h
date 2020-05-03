/**
@file Dados.h
Manipulação dos dados do estado do jogo.
*/

#ifndef TRABALHO_DE_LI_DADOS_H
#define TRABALHO_DE_LI_DADOS_H

/**
\brief Este tipo CASA é responsável por indicar qual peça está em certa coordenada.
*/
typedef enum {VAZIO, BRANCA, PRETA, UM, DOIS} CASA;
/** 
\brief Este tipo COORDENADA é indicador de uma posição no tabuleiro.
*/
typedef struct {
    int coluna;
    int linha;
} COORDENADA;
/**
\brief Este tipo JOGADA indica um par de movimentos, realizados por ambos os jogadores.
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;
/**
\brief Este tipo JOGADAS é responsavel por armazenar a lista de jogadas realizadas no jogo. 
*/
typedef JOGADA JOGADAS[32];
/**
\brief Este tipo ESTADO é responsável por guardar o estado do jogo. 
*/
typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;

/** 
\brief Esta função inicia o tabuleiro.
*/
ESTADO *inicializar_estado();
/** 
\brief Converte um inteiro em um char que representa uma coluna.
@param col É um inteiro a ser convertido.
@returns retorna o char correspondente a coluna
*/
char conv_c(int col);
/** 
\brief Converte um inteiro em um char que representa uma linha.
@param lin É um inteiro a ser convertido
@returns retorna o char correspondente a linha
*/
char conv_l(int lin);
/**
\brief Esta função obtém o jogador que está a jogar.
@param estado É o estado atual do jogo.
@returns Retorna o jogador atual.
*/
int obter_jogador_atual(ESTADO *estado);
/**
\brief Esta função obtém o número de jogadas realizadas.
@param estado É o estado atual do jogo.
@returns retorna o numero de jogadas.
*/
int obter_numero_de_jogadas(ESTADO *estado);
/**
\brief Esta função obtém a casa associada a uma linha e uma coluna.
@param e é o estado
@param y é uma linha
@param x é uma coluna
@returns retorna a casa
*/
CASA obter_casa(ESTADO *e, int y, int x);
/** 
\brief Esta função obtém a linha associada com uma jogada e um jogador.
@param e É o estado atual
@param player É o jogador em questao
@param jogada É a jogada em questao
@returns Vai retornar a linha associada a jogada do jogador em questao.
*/
int obter_linha(ESTADO *e, int player, int jogada);
/**
\brief Esta função obtém a coluna associada com uma jogada e um jogador.
@param e É o estado atual
@param player É o jogador em questao
@param jogada É a jogada em questao
@returns Vai retornar a coluna associada a jogada do jogador em questao
*/
int obter_coluna(ESTADO *e, int player, int jogada);
/**
\brief Esta função obtém a coordenada associada com uma jogada e um jogador.
@param e É o estado atual
@param player É o jogador em questao
@param jogada É a jogada em questao
@returns Retorna a coordenada associada ao jogador e a jogada.
*/
COORDENADA obter_coord(ESTADO *e, int player, int jogada);
/**
\brief Esta função obtém a linha associada à ultima jogada.
@param e É o estado atual
@returns Retorna a linha da ultima jogada
*/
int obter_linha_ult(ESTADO *e);
/**
\brief Esta função obtém a coluna associada à ultima jogada.
@param e É o estado atual
@returns Retorna a coluna da ultima jogada
*/
int obter_coluna_ult(ESTADO *e);
/**
\brief Esta função obtém a coordenada associada à ultima jogada.
@param e É o estado atual
@returns Retorna a ultima coordenada
*/
COORDENADA obter_coord_ult(ESTADO *e);
/**
\brief Obtém a jogada "n".
@param e É o estado atual
@param n É a ordem da jogada a ser obtida
@returns Retorna a jogada da ordem solicitada
*/
JOGADA obter_jogadas(ESTADO *e,int n);
/**
\brief Esta função guarda a coordenada que recebe a ultima jogada.
@param e É o estado atual
@param y É uma linha
@param x É uma coluna
*/
void guarda_ultima_jog(ESTADO *e, int y, int x);
/**
\brief Esta função guarda o numero de jogadas.
@param e É o estado atual
@param n É a jogada a ser guardada
*/
void guarda_num_jogs(ESTADO *e, int n);
/**
\brief Esta funçao recebe uma coordenada e substitui pela coordenada que recebe.
@param e É o estado atual
@param x É uma coluna
@param y É uma linha
@param c É a casa em que a peça vai ser colocada.
*/
void alteracasa(ESTADO *e, int x, int y, CASA c);
/**
\brief Esta função guarda uma jogada consoante ao jogador e numero da jogada.
@param e É o estado atual
@param j É o jogador da vez
@param nj É o numero de jogadas
@param y É uma linha
@param x É uma coluna
*/
void guarda_jogada(ESTADO *e, int j, int nj, int y, int x);
/**
\brief Esta função recebe uma coordenada e a guarda na jogada.
@param e É o estado atual
@param j É o jogador da vez
@param nj É o numero de jogadas
@param c É a coordenada a ser guardada
*/
void guarda_jogada_coord(ESTADO *e, int j, int nj, COORDENADA c);
/**
\brief Essa função guarda o jogador atual.
@param e É o estado atual
@param n É o jogador a ser guardado
*/
void guardar_jogador(ESTADO *e, int n);

#endif //TRABALHO_DE_LI_DADOS_H
