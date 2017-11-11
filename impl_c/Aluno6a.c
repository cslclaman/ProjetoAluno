#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM_MAX 40

struct {
	in
}

void limpabuffer() {
	char ch = getchar();
	while (ch != '\n' && ch != '\0');
}

void ImprimeResult(struct Aluno aluno){
	char nomecurso[TAM_MAX], result[TAM_MAX];

	if (aluno.curso == 'I'){
		strcpy(nomecurso, "Informatica");
	}
	if (aluno.curso == 'L'){
		strcpy(nomecurso, "Lingua estrangeira");
	}
	if (aluno.curso == 'A'){
		strcpy(nomecurso, "Administracao");
	}

	media = (aluno.nota1 + aluno.nota2) / 2;

	if (aluno.faltas <= 10 && media >= 6.5){
		strcpy(result, "APROVADO");
	} else {
		strcpy(result, "REPROVADO");
	}

	printf("Aluno %d - %s, matriculado em %02d/%02d/%04d\n", ra, nome, dia, mes, ano);
	printf("Desempenho no curso de %s: %s\n", nomecurso, result);
	printf("Nota final: %.1f - Presenca: %.1f%%\n", media, 100 - (faltas * 2.5) );
}

void PrimeiroNome(char *nome, char *saida){
	int c;
	for (c = 0; nome[c] != '\0' && nome[c] != ' '; c++){
		saida[c] = nome[c];
	}
	saida[c] = '\0';
}

void UltimoNome(char *nome, char *saida){
	int c, d;
	for (c = strlen(nome) - 1; c >= 0 && nome[c] != ' '; c--);

	for (c = c + 1, d = 0; nome[c] != '\0'; c++, d++){
		if (nome[c] >= 'a' && nome[c] <= 'z')
			saida[d] = nome[c] - 'a' + 'A';
		else
			saida[d] = nome[c];
	}
	saida[d] = '\0';
}

void PrimeiroUltimoNome(char *nome, char *saida){
	int c, d;
	char prinome[TAM_MAX], ultnome[TAM_MAX];
	PrimeiroNome(nome, prinome);
	UltimoNome(nome, ultnome);

	for (c = 0; prinome[c] != '\0'; c++){
		saida[c] = prinome[c];
	}
	saida[c] = ' ';
	for (c = c + 1, d = 0; ultnome[d] != '\0'; c++, d++){
		saida[c] = ultnome[d];
	}
	saida[c] = '\0';
}

int main (){
	int c;

	int ra;
	char nome[TAM_MAX];
	int dia, mes, ano;
	char curso;
	int faltas;
	float pagto;
	float nota1, nota2;

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





	PrimeiroNome(nome, primnome);
	UltimoNome(nome, ultnome);
	PrimeiroUltimoNome(nome, primultnome);

	printf("Primeiro nome: %s\n", primnome);
	printf("Ultimo nome: %s\n", ultnome);
	printf("Primeiro e ultimo nome: %s\n", primultnome);

	return 0;
}
