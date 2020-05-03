/**
@file Listas.h
Essa camada é responsável pela manipulação de listas ligadas.
 */

#ifndef TRABALHO_DE_LI2_LISTAS_H
#define TRABALHO_DE_LI2_LISTAS_H

typedef struct nodo {
    void *valor;
    struct nodo *proximo;
} NODO, *LISTA;

/**
\brief Cria uma lista vazia.
@returns Retorna uma lista vazia
*/
LISTA criar_lista();
/** 
\brief Insere um valor na cabeça da lista
@param L É uma lista ligada
@param valor É o valor a ser inserido na cabeça.
@returns Retorna a lista com a cabeça inserida.
*/
LISTA insere_cabeca(LISTA L, void *valor);
/**
\brief Devolve a cabeça da lista 
@param L É uma lista ligada.
*/
void *devolve_cabeca(LISTA L);
/**
\brief Devolve a cauda da lista
@param L É uma lista ligada.
@returns Retorna o resto da lista sem a cabeça.
*/
LISTA proximo(LISTA L);
/**
\brief Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
@param L É uma lista ligada
@returns Retorna a lista sem a cabeça.
*/
LISTA remove_cabeca(LISTA L);
/**
\brief Devolve verdareiro se a lista é vazia 
@param L
@returns Retorna 1, se a lista estiver vazia e 0 se não estiver vazia.
*/
int lista_esta_vazia(LISTA L);

#endif //TRABALHO_DE_LI2_LISTAS_H
