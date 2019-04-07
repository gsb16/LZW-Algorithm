#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "dici.h"

void adicionaPalavra(char *palavra){
    if(chave+1 < TAM_DICI){
        chave++;
        diciPalavras[chave] = (char *)malloc((strlen(palavra)+1) * sizeof(char));
        strcpy(diciPalavras[chave], palavra);
    }
}

int buscaPalavra(char *palavra){
    for(int i = 0; i < chave; i++){
        if(!strcmp(diciPalavras[i],palavra)){
            return i;
        }
    }
    return -1;
}

char *buscaChave(int n){
    if(n <= chave){
        return diciPalavras[n];
    } else {
        return 0;
    }
}

void iniciaDici(){
    char I[2];
    for(int i = 0; i < 256; i++){
        I[0] = i;
        I[1] = '\0';
        adicionaPalavra(I);
    }
}

char *adicionaChar(char *s, char c){
    int slen = s==NULL?0:strlen(s);
    char *t = s;
    if((slen+2) > ptam){
        ptam++;
        t = (char *)realloc((void *)s, ptam*sizeof(char));
        if(!t){
            perror("Deu ruim");
            exit(-1);
        }
    }

    t[slen] = c;
    t[slen+1] = '\0';

    return t;
}

void iniciaString(char *s, char c){
    s[0] = c;
    s[1] = '\0';
}
