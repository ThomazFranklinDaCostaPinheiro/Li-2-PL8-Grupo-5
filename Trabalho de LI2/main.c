#include <stdio.h>
#include "Dados.h"
#include "Lógica.h"
#include "Interface.h"

interpretador(ESTADO *);

int main() {
    ESTADO *e = inicializar_estado();
    interpretador(e);
    return 0;
}