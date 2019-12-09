#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"jogador.h"

Jogador initJogador(char *nome){
	Jogador j;
	j.total = 0;
	j.nome = (char *) malloc(100*sizeof(char));
	memcpy(j.nome, nome, 100*sizeof(char));
	j.aposta = 0;
	j.pont = 0;
	j.total = 0;
	return j;
}

void initPartida(Jogador *j, int aposta){
	(*j).aposta = aposta;
	return;
}

void imprimeJogador(Jogador j){
	printf("%s\n", j.nome);
	return;
}

void somaPonto(Jogador *j, int valor){
	(*j).pont = (*j).pont + valor;
	return;
}

int retornaPonto(Jogador j){
	return j.pont;
}

void imprimeResultado(Jogador j){
	if(j.total >= 0){
		printf("%s, voce ganhou %d reais.\n",j.nome, j.total);
	}
	else{
		int abs = j.total*(-1);
		printf("%s, voce perdeu %d reais.\n",j.nome, abs);
	}
	return;
}

void vitoria(Jogador *j){
	printf("Voce ganhou!\n");
	(*j).total = (*j).total + (*j).aposta;
	return;
}

void derrota(Jogador *j){
	printf("voce perdeu!\n");
	(*j).total = (*j).total - (*j).aposta;
	return;

}
