#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dici.h"
#include "io.h"
#include "core.h"

char *diciPalavras[TAM_DICI];
char *buf = NULL, op, c;
int chave = -1, d, ptam = 1;
FILE *arq;

int main(int argc, char *argv[]){
    iniciaDici();
    op = operacao(argc, argv);

    switch (op) {
        case 'c':
            comprime();
            break;
        case 'd':
            descomprime();
            break;
    }

    return 0;
}
