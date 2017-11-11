#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM_MAX 40

struct rData {
	int dia, mes, ano;
};
typedef struct rData Data;

struct rAluno {
	int ra;
	char nome[TAM_MAX];
	Data matric;
	char curso;
	int faltas;
	float nota1, nota2;
};
typedef struct rAluno Aluno;

void limpabuffer() {
	char ch = getchar();
	while (ch != '\n' && ch != '\0');
}

/*
Calcula média final do aluno com a nota das duas provas.
*/
float CalculaMedia(float nota1, float nota2){
	float media, soma;
	soma = nota1 + nota2;
	media = soma / 2;
	return media;
}

/*
Imprime os dados e o resultado de um aluno.
*/
void ImprimeResult(Aluno aluno){
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

	if (aluno.faltas <= 10 && CalculaMedia(aluno.nota1, aluno.nota2) >= 6.5){
		strcpy(result, "APROVADO");
	} else {
		strcpy(result, "REPROVADO");
	}

	printf("Aluno %d - %s, matriculado em %02d/%02d/%04d\n", aluno.ra, aluno.nome, aluno.matric.dia, aluno.matric.mes, aluno.matric.ano);
	printf("Desempenho no curso de %s: %s\n", nomecurso, result);
	printf("Nota final: %.1f - Presenca: %.1f%%\n", CalculaMedia(aluno.nota1, aluno.nota2), 100 - (aluno.faltas * 2.5) );
	printf("\n");
}

/*
Imprime RA, nome e média final de uma lista de alunos.
*/
void ImprimelistaAlunos (Aluno lista[], int tam){
	int c;
	printf("\n------------------------------------------------------------------------\n");
    printf("LISTA DE ALUNOS:\n");
    printf("------------------------------------------------------------------------\n");

	printf("| %-6s | %-40s | %-4s |\n", "RA", "NOME", "NOTA");
	for (c = 0; c < tam; c++){
		printf("| %-6d | %-40s | %-4.2f |\n", lista[c].ra, lista[c].nome, CalculaMedia(lista[c].nota1, lista[c].nota2));
	}

	printf("------------------------------------------------------------------------\n");
}

int CompNome(const void *p1, const void *p2){
	Aluno *a = (Aluno *) p1;
	Aluno *b = (Aluno *) p2;
	return strcmp(a->nome, b->nome);
}

int CompMedia(const void *p1, const void *p2){
	Aluno *a = (Aluno *) p1;
	Aluno *b = (Aluno *) p2;
	float ma = CalculaMedia(a->nota1, a->nota2);
	float mb = CalculaMedia(b->nota1, b->nota2);
	if (ma < mb){
		return 1;
	} else {
		if (ma > mb){
			return -1;
		} else {
			return 0;
		}
	}
}

typedef int (*FuncaoCompara)(const void *, const void *);

void OrdenaInsercao(Aluno lista[], int tam, FuncaoCompara comp){
	int c, d, pos;
	Aluno aux;

	for (c = 1; c < tam; c++){
		pos = -1;
		for (d = c - 1; d >= 0 ; d--){
			if (comp(&lista[d], &lista[c]) > 0){
				pos = d;
			}
		}
		if (pos >= 0){
			aux = lista[c];
			for (d = c; d > pos; d--){
				lista[d] = lista[d - 1];
			}
			lista[pos] = aux;
		}
	}
}

int main (){
	int pos, tam;

	Aluno aluno[50];

	for(pos = 0; pos < 50; pos++){
		int c, ra;
		printf("RA:\n");
		scanf("%d", &ra);

		if (ra == 0)
			break;

		aluno[pos].ra = ra;

		printf("Nome:\n");
		limpabuffer();
		fgets(aluno[pos].nome, TAM_MAX - 3, stdin);
		for (c = 0; aluno[pos].nome[c] != '\0' && aluno[pos].nome[c] != '\n'; c++);
		aluno[pos].nome[c] = '\0';

		printf("Data matricula (DD/MM/AAAA):\n");
		scanf("%d/%d/%d", &aluno[pos].matric.dia, &aluno[pos].matric.mes, &aluno[pos].matric.ano);

		printf("Curso:\n");
		scanf(" %c", &aluno[pos].curso);

		printf("Numero de faltas:\n");
		scanf("%d", &aluno[pos].faltas);

		printf("Nota das provas (prova 1 e prova 2):\n");
		scanf("%f %f", &aluno[pos].nota1, &aluno[pos].nota2);
	}
	tam = pos;

	OrdenaInsercao(aluno, tam, CompNome);
	ImprimelistaAlunos(aluno, tam);

	OrdenaInsercao(aluno, tam, CompMedia);
	ImprimelistaAlunos(aluno, tam);

	return 0;
}
