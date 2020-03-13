#include <stdio.h>
#include "Dados.h"
#include "Logica.h"
#include "Interface.h"


int main() {
    ESTADO *e = inicializar_estado();
    interpretador(e);
    return 0;
}
