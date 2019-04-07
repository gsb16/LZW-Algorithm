#define TAM_DICI 65536

extern int chave, ptam;
extern char *diciPalavras[];

void adicionaPalavra(char *palavra);

char *adicionaChar(char *s, char c);

void iniciaString(char *s, char c);

int buscaPalavra(char *palavra);

char *buscaChave(int n);

void iniciaDici();
