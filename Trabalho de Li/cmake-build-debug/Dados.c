//
// Created by Thomaz on 12/03/2020.
//

#include "Dados.h"

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e->jogador_atual = 1;
    e->num_jogadas = 0;
// Falta a resto da inicialização.
    return e;
}
