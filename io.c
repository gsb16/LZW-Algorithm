#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "io.h"

char operacao(int argc, char *argv[]){
    if(argc != 4){
        printf("Eu não funciona assim, leia o readme.md para instruções.\n");
        exit(-1);
    }

    if(argv[1][1] == 'c'){
        arq = fopen(argv[2], "r");
        arq_byte = open(argv[3], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    } else if(argv[1][1] == 'd'){
        arq_byte = open(argv[2], O_RDONLY);
        arq = fopen(argv[3], "w+");
    }

    return argv[1][1];
}
