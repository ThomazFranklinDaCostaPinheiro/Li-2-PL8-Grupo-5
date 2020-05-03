#include <stdio.h>
#include "dados.h"
#include "interface.h"


int main(int argc, char**argv){
    ESTADO *e = inicializar_estado();
    lerfich(argv[1],e);
    while(vencer(e)){
        jogs2(e);
    }
    printf("\nO vencedor da partida e o Jogador%d", quem_ganha(e));
    gravar(e,argv[2]);
    return 0;
}
