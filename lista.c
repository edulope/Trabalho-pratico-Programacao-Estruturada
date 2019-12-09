#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista geralista(int tamanho){
	Lista *L;
	Lista *aux;
	L = (Lista*)malloc(sizeof(Lista));
	(*L).prox = NULL;
	aux = L;
	for(int i=0; i<tamanho-1;i++){
	    Lista *nova;
	    nova = (Lista*)malloc(sizeof(Lista));
	    (*nova).prox = NULL;
	    (*aux).prox = nova;
	    aux = nova;
	}

	return *L;
}

void atualizavalor(Lista *l, int n){
    l->valor = n;
    return;
}

Lista* auxprox(Lista *aux){
    Lista *aux2;
    aux2 = aux;
    aux2 = aux2->prox;
    return aux2;
}

int valoraux(Lista *aux){
    return aux->valor;
}

void printac(Lista *aux){
    printf("Carta: %d-%c\n", (*aux).valor, (*aux).naipe);
    return;
}
void rouba(Lista *aux,Lista *L){
    Lista *aux2;
    aux2 = auxprox(aux);
    aux->prox = aux->prox->prox;
    aux2->prox = L->prox;
    L->prox = aux2;
    return;
}
