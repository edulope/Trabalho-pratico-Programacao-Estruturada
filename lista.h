#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct lista{
	char naipe;
	int valor;
	struct lista *prox;
} Lista;


Lista geralista(int tamanho);

void atualizavalor(Lista *l, int n);


Lista* auxprox(Lista *aux);



int valoraux(Lista *aux);



void printac(Lista *aux);


void rouba(Lista *aux,Lista *L);

#endif
