//Bibliotecas básicas da linguagem C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Constante para tamanho máximo do nome do aluno
#define TAM_MAX 40

//Funcão principal do programa
int main (){

	//Declaração de variáveis
	int ra;
	char nome[TAM_MAX];
	int dia, mes, ano;
	char curso;

	//Leitura dos dados de um aluno
	printf("RA:\n");
	scanf("%d", &ra); //%d => inteiro com sinal (se fosse unsigned int, seria %u)

	printf("Nome:\n");
	scanf("%s", nome); //%s => char[] (String)

	printf("Data matricula (DD/MM/AAAA):\n");
	scanf("%d/%d/%d", &dia, &mes, &ano); //Ao colocar símbolos na máscara, o programa ignora-os na leitura.

	printf("Curso:\n");
	scanf(" %c", &curso); // %c => char (letra). O espaço antes do % desconsidera ocasionais espaços, enters ou tabs antes do caracter

	//Impressão dos dados
	printf("RA: %d\nNome: %s\nMatricula: %d/%d/%d\nCurso: %c\n", ra, nome, dia, mes, ano, curso);

	return 0;
}
