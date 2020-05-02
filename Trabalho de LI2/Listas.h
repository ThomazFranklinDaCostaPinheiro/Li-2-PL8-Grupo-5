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
\brief Cria uma lista vazia
*/
LISTA criar_lista();
/** 
\brief Insere um valor na cabeça da lista
*/
LISTA insere_cabeca(LISTA L, void *valor);
/**
\brief Devolve a cabeça da lista 
*/
void *devolve_cabeca(LISTA L);
/**
\brief Devolve a cauda da lista
*/
LISTA proximo(LISTA L);
/**
\brief Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
*/
LISTA remove_cabeca(LISTA L);
/**
\brief Devolve verdareiro se a lista é vazia 
*/
int lista_esta_vazia(LISTA L);

#endif //TRABALHO_DE_LI2_LISTAS_H
