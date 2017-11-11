#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM_MAX 40

int main (){
	int ra;
	char nome[TAM_MAX];
	int dia, mes, ano;
	char curso;
	int faltas;
	float nota1, nota2;

	printf("RA:\n");
	scanf("%d", &ra);

	printf("Nome:\n");
	scanf("%s", nome);

	printf("Data matricula (DD/MM/AAAA):\n");
	scanf("%d/%d/%d", &dia, &mes, &ano);

	printf("Curso:\n");
	scanf(" %c", &curso);

	printf("Numero de faltas:\n");
	scanf("%d", &faltas);

	printf("Nota das provas (prova 1 e prova 2):\n");
	scanf("%f %f", &nota1, &nota2);

	printf("RA: %d\nNome: %s\nMatricula: %d/%d/%d\nCurso: %c\n", ra, nome, dia, mes, ano, curso);
	printf("Num faltas: %d\nNota das provas: %f - %f\n", faltas, nota1, nota2);

	return 0;
}
