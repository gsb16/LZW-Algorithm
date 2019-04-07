# Compressor e Descompressor LZW

## Autores:
- Guilherme Bastos de Oliveira
- Gabriel de Souza Barreto

## Objetivo:
Trabalho para a disciplina de Redes 1
- Comprimir e descomprimir arquivos usando o algoritmo LZW

## Utilização:
### para comprimir um arquivo execute:
```
	./lzw -c <arq-origem> <arq-comprimido>
```
### para descomprimir um arquivo execute:
```
	./lzw -d <arq-comprimido> <arq-saida>
```

## Makefile:
- *make:* compila o programa
- *make clean:* deleta arquivos temporários de compilação
- *make purge:* executa clean e remove executavel
- *make remake:* executa purge e compila

## Decisões de Projeto
- __Método de leitura e escrita do arquivo comprimido:__ Para realizar a leitura e escrita do arquivo resultante da compressão foram utilizas as funções *read()* e *write()*, que permitem escrever *bytes* em um arquivo, desse modo, com uma 'largura' fixa dos dados é possível salvar e ler informações sem necessidade de um separador.
- __Tamanho do dicionário:__ o tamanho do dicionário foi escolhido baseado em dois fatores, o primeiro é o custo-beneficio entre velocidade e eficiência, o outro é a leitura e escrita, o mais apropriado sobre estes pontos foi um dicionário com 2^16 entradas, pois permite a existência de várias palavras e pode ser pesquisado em um tempo 'razoável'. Como 2^16 pode ser representado em 2 *bytes*, as chaves são impressas como um *short* no arquivo comprimido, e por essa ser uma definição fixa, a leitura pode ser feita de 2 em 2 *bytes*.
- __Estruturas de dados:__ o dicionário é armazenado em um vetor de vetores de *char*, onde cada índice do vetor pai representa uma chave e cada vetor filho é uma *string* armazenada no dicionário. Existe um *buffer* (vetor de *char*) para criar as palavras a serem inseridas no dicionário, ele é reutilizado a cada iteração.
