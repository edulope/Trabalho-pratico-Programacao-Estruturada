#include <stdio.h>
#include <stdlib.h>
#include "baralho.h"

// inicializa um baralho
Baralho iniciaBaralho(int tamanho){
    Baralho b;
	b.cartas = geralista(tamanho);
	b.tamanho = tamanho;
	b.posicao = 0;
	return b;
}

void leituraBaralho(Baralho *b){
    Lista *aux;
	aux = &((*b).cartas);
	 for(int i = 0; i< (*b).tamanho; i++){
        char *resposta;
        resposta = (char *) malloc(3*sizeof(char));
        scanf("%s", resposta);
        (*aux).naipe = resposta[1];
        if(resposta[0] == 'A'){
            atualizavalor(aux, 1);
        }
        else if(resposta[0] == '2'){
             atualizavalor(aux, 2);
        }
        else if(resposta[0] == '3'){
             atualizavalor(aux, 3);
        }
        else if(resposta[0] == '4'){
             atualizavalor(aux, 4);
        }
        else if(resposta[0] == '5'){
             atualizavalor(aux, 5);
        }
        else if(resposta[0] == '6'){
             atualizavalor(aux, 6);
        }
        else if(resposta[0] == '7'){
             atualizavalor(aux, 7);
        }
        else if(resposta[0] == '8'){
             atualizavalor(aux, 8);
        }
        else if(resposta[0] == '9'){
             atualizavalor(aux, 9);
        }
        else if(resposta[0] == '0'||resposta[0] == 'J'|| resposta[0] == 'Q'|| resposta[0] == 'K') {
             atualizavalor(aux, 10);
        }
        aux = auxprox(aux);
        free(resposta);
    }
    return;
}






// retorna a proxima carta do deck

int sorteiaCarta(Baralho *b){
    if((*b).posicao == (*b).tamanho){
        return 0;
    }
    Lista *aux;
    aux = &((*b).cartas);
    for(int i = 0; i<(*b).posicao;i++){
        aux = auxprox(aux);
    }
    printac(aux);
    (*b).posicao = (*b).posicao + 1;
    return valoraux(aux);
}





void roubaCarta(Baralho *b, int valor){
    Lista *aux;
    Lista *L;
    aux = &((*b).cartas);
    L = &((*b).cartas);
    for(int i = 0; i<(*b).posicao-1;i++){
        L = auxprox(L);
    }
    aux = L;
    while(auxprox(aux) != NULL){
        
        if(valor == valoraux(auxprox(aux))){
            rouba(aux, L);
            return;
        }
        else{
            aux = auxprox(aux);;
            if(aux == NULL){
                return;
            }
        }
    }
    return;
}

 




void terminaBaralho(Baralho *b){
    Lista *aux, *aux2;
    aux = &((*b).cartas);
    aux2 = &((*b).cartas);
    if((*aux2).prox != NULL){
	 aux2 = auxprox(aux2);
    }
    while(aux2 != NULL){
        aux = aux2;
        aux2 = auxprox(aux2);
        free(aux);
    }
    return;
}
