#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct jogador {
	int pont;
	int aposta;
	int total;
	char *nome;
} Jogador;

// incializa um jogador, dado o seu nome
Jogador initJogador(char *nome);

// atualiza o valor da aposta e outras variaveis no inicio de uma partida
void initPartida(Jogador *j, int aposta);

// imprime na tela no nome de um jogador
void imprimeJogador(Jogador j);

// adiciona o valor de uma carta a pontuacao do jogador
void somaPonto(Jogador *j, int valor);

// retorna o valor da pontuacao do jogador
int retornaPonto(Jogador j);

// imprime na tela o valor ganho ou perdido pelo jogador
void imprimeResultado(Jogador j);

// atualiza o total de dinheiro do jogador e imprime na tela que ele ganhou
void vitoria(Jogador *j);

// atualiza o total de dinheiro do jogador e imprime na tela que ele perdeu
void derrota(Jogador *j);
