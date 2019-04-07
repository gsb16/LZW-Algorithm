#include <string.h>
#include <unistd.h>
#include "dici.h"
#include "core.h"

int arq_byte;

void comprime(){
    char c;
    unsigned short valor;
    extern char *buf;
    int busca;
    c = fgetc(arq);
    do {
        buf = adicionaChar(buf, c);
        busca = buscaPalavra(buf);
        if(busca == -1){
            adicionaPalavra(buf);
            buf[strlen(buf)-1] = '\0';
            valor = buscaPalavra(buf);
            if(write(arq_byte, &valor, 2) <= 0){
				perror("Erro na escrita");
			}
            iniciaString(buf, c);
        }
    } while(c = fgetc(arq), c != EOF);
    valor = buscaPalavra(buf);
    if(write(arq_byte, &valor, 2) <= 0){
		perror("Erro na escrita");
	}
    close(arq_byte);
}

void descomprime(){
    unsigned short cc, pc;
    char *s, c;
    int rd;
    extern char *buf;
    buf = adicionaChar(buf, '\0');
    rd = read(arq_byte, &cc, 2);
    s = buscaChave(cc);
    fprintf(arq,"%s", s);
    do {
        pc = cc;
        if(!read(arq_byte, &cc, 2)) break;
        if(s = buscaChave(cc), s){
            fprintf(arq,"%s", s);
            strcpy(buf, buscaChave(pc));
            c = s[0];
            buf = adicionaChar(buf, c);
            adicionaPalavra(buf);
        } else {
            strcpy(buf, buscaChave(pc));
            c = buf[0];
            buf = adicionaChar(buf, c);
            fprintf(arq,"%s", buf);
            adicionaPalavra(buf);
        }
    } while(rd);
}
