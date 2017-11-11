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
	int c, c2;

	int ra;
	char nome[TAM_MAX];
	int dia, mes, ano;
	char curso;
	int faltas;
	float nota1, nota2, media;
	char nomecurso[TAM_MAX], result[TAM_MAX];

	char primnome[TAM_MAX], ultnome[TAM_MAX], primultnome[TAM_MAX];

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

	for (c = 0; nome[c] != '\0' && nome[c] != ' '; c++){
		primnome[c] = nome[c];
	}
	primnome[c] = '\0';

	for (c = strlen(nome) - 1; c >= 0 && nome[c] != ' '; c--);
	for (c = c + 1, c2 = 0; nome[c] != '\0'; c++, c2++){
		if (nome[c] >= 'a' && nome[c] <= 'z')
			ultnome[c2] = nome[c] - 'a' + 'A';
		else
			ultnome[c2] = nome[c];
	}
	ultnome[c] = '\0';

	for (c = 0; primnome[c] != '\0'; c++){
		primultnome[c] = primnome[c];
	}
	primultnome[c] = ' ';
	for (c = c + 1, c2 = 0; ultnome[c2] != '\0'; c++, c2++){
		primultnome[c] = ultnome[c2];
	}
	primultnome[c] = '\0';

	printf("Primeiro nome: %s\n", primnome);
	printf("Ultimo nome: %s\n", ultnome);
	printf("Primeiro e ultimo nome: %s\n", primultnome);

	return 0;
}
