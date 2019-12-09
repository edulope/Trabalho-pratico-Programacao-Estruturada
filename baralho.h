#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct baralho {
	int tamanho;
	Lista cartas;
	int posicao;
} Baralho;

// inicializa um baralho
Baralho iniciaBaralho(int tamanho);

// le os valores das cartas dados pela entrada padrão
void leituraBaralho(Baralho *b);

// retorna a proxima carta do deck
int sorteiaCarta(Baralho *b);

// rouba colocando uma carta de valor dado no topo do deck
// se ela nao existir nao faz nada
void roubaCarta(Baralho *b, int valor);

// termina um baralho
void terminaBaralho(Baralho *b);
