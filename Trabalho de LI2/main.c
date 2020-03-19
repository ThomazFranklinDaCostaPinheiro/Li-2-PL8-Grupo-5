#include <stdio.h>
#include "Dados.h"
#include "Logica.h"
#include "Interface.h"


int main() {
    ESTADO *e = inicializar_estado();
    mostrar_tabuleiro(e);
    int i = 0;
    while(i <= 32){
        interpretador(e);
        i++;
    }
    return 0;
}
