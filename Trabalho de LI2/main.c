#include <stdio.h>
#include "Dados.h"
#include "Interface.h"


int main() {
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(e);
    while(vencer(e)){
        interpretador(e);
    }
    printf("\nO vencedor da partida e o Jogador%d", quem_ganha(e));
    return 0;
}
