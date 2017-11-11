#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM_MAX 40

void limpabuffer() {
	char ch = getchar();
	while (ch != '\n' && ch != '\0');
}

int main (){
	int c;

	int ra;
	char nome[TAM_MAX];
	int dia, mes, ano;
	char curso;
	int faltas;
	float nota1, nota2, media;
	char nomecurso[TAM_MAX], result[TAM_MAX];

	printf("RA:\n");
	scanf("%d", &ra);

	limpabuffer();

	printf("Nome:\n");
	fgets(nome, TAM_MAX - 3, stdin);
	for (c = 0; nome[c] != '\0' && nome[c] != '\n'; c++);
	nome[c] = '\0';

	printf("Data matricula (DD/MM/AAAA):\n");
	scanf("%d/%d/%d", &dia, &mes, &ano);

	printf("Curso:\n");
	scanf(" %c", &curso);

	printf("Numero de faltas:\n");
	scanf("%d", &faltas);

	printf("Nota das provas (prova 1 e prova 2):\n");
	scanf("%f %f", &nota1, &nota2);

	if (curso == 'I'){
		strcpy(nomecurso, "Informatica");
	}
	if (curso == 'L'){
		strcpy(nomecurso, "Lingua estrangeira");
	}
	if (curso == 'A'){
		strcpy(nomecurso, "Administracao");
	}

	media = (nota1 + nota2) / 2;

	if (faltas <= 10 && media >= 6.5){
		strcpy(result, "APROVADO");
	} else {
		strcpy(result, "REPROVADO");
	}

	printf("Aluno %d - %s, matriculado em %02d/%02d/%04d\n", ra, nome, dia, mes, ano);
	printf("Desempenho no curso de %s: %s\n", nomecurso, result);
	printf("Nota final: %.1f - Presenca: %.1f%%\n", media, 100 - (faltas * 2.5) );

	return 0;
}
