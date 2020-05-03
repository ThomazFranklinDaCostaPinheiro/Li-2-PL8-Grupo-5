#include <stdio.h>
#include "dados.h"
#include "interface.h"


int main(int argc, char**argv){
    if(argc == 3){
        ESTADO *e = inicializar_estado();
        lerfich(argv[1],e);
        if(vencer(e)){
            jogs2(e);
            gravar(e,argv[2]);
            return 0;
        } else
            printf("Player%2d venceu",quem_ganha(e));
    } else
        printf("Argumentos insuficientes.");
}
