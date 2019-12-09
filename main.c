#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lista.h"
#include"baralho.h"
#include"jogador.h"


int main(){
	//preparação
	Baralho b;
	Jogador j;
	int aposta;
	char *nome;
	nome = (char *) malloc(100*sizeof(char));
	int tamanho;
	scanf("%d", &tamanho);
	b = iniciaBaralho(tamanho);
	leituraBaralho(&b);
	printf("Digite seu nome:\n");
	scanf(" %s", nome);
	j= initJogador(nome);
	free(nome);
	printf("Digite sua aposta:\n");
	scanf("%d", &aposta);
	initPartida((&j),aposta);
	//inicio do jogo
	char respostafinal = 'S';
	char resposta = 'S';
	int boolean = 0;
	int dealer = 0;
	int pontuar = 0;
	int valor = (-1)*(retornaPonto(j));
	somaPonto(&j,valor);
	
	while(respostafinal == 'S'){



		if(boolean == 0){
			imprimeJogador(j);
			boolean = 1;
		}



		if(boolean == 1){
			int valor = sorteiaCarta(&b);
			if (valor != 0){
				somaPonto(&j, valor);
				pontuar = retornaPonto(j);
				if(pontuar< 21){
					printf("Deseja continuar (S/N):\n");
					scanf(" %c", &resposta);
					if(resposta == 'N'){
						printf("Dealer\n");
						boolean = 2;
					}
					if(resposta == 'R'){
					    printf("Digite o valor:\n");
						scanf(" %d", &tamanho);
						roubaCarta(&b, tamanho);
					}
				}
				if(pontuar == 21){
						printf("Dealer\n");
						vitoria(&j);
						boolean = 3;
				}
				if(pontuar> 21){
					printf("Dealer\n");
					derrota(&j);
					boolean = 3;
				}
			}
			else{
				printf("Nao ha mais cartas.\n");
					pontuar = retornaPonto(j);
					if(pontuar != 0){
						vitoria(&j);
					}
				imprimeResultado(j);
				break;
			}
		}



		if(boolean == 2){
			int valor = sorteiaCarta(&b);
			if(valor !=0){
			dealer = dealer + valor;
				if(dealer>21){
					vitoria(&j);
					boolean = 3;
					}
				if(dealer<= 21 && dealer >= 17){
					pontuar = retornaPonto(j);
					if(pontuar >=dealer){
						vitoria(&j);
						boolean = 3;
					}
				else{
						derrota(&j);
						boolean = 3;
					}
				}
			}
			else{
				printf("Nao ha mais cartas.\n");
				pontuar = retornaPonto(j);
					if(pontuar >=dealer){
						vitoria(&j);
					}
					else{
						derrota(&j);
					}
				imprimeResultado(j);
				break;
			}
		}



		if(boolean == 3){
			printf("Deseja fazer nova aposta (S/N):\n");
			scanf(" %c", &respostafinal);
			if(respostafinal == 'N'){
				imprimeResultado(j);
				break;
			}
			else{
				boolean = 0;
				dealer = 0;
				int valor = (-1)*(retornaPonto(j));
				somaPonto(&j,valor);
				printf("Digite sua aposta:\n");
				scanf("%d", &aposta);
				initPartida(&j,aposta);
			}
		}



	}
	free(j.nome);
    return 0;
}
