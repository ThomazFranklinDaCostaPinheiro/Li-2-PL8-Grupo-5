//
// Created by danie on 18/04/2020.
//

#include "Listas.h"
#include <stdio.h>
#include <stdlib.h>

LISTA criar_lista(){
    LISTA r = malloc(sizeof(NODO));
    r->proximo = NULL;
    return r;
}

LISTA insere_cabeca(LISTA L, void *valor){
    LISTA r = malloc(sizeof(NODO));
    r->valor = valor;
    r->proximo = L;
    return r;
}

void *devolve_cabeca(LISTA L){
    return (L->valor);
}

LISTA proximo(LISTA L){
    return (L->proximo);
}

LISTA remove_cabeca(LISTA L){
    LISTA temp = NULL;
    temp = L->proximo;
    free(L);
    return temp;
}

int lista_esta_vazia(LISTA L){
    if(L == NULL)
        return 1;
    else
        return 0;
}
