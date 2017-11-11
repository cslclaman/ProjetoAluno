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

float CalculaMedia(float nota1, float nota2){
	float media, soma;
	soma = nota1 + nota2;
	media = soma / 2;
	return media;
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

int main (){
	int c, pos, tam, ra;
	char nome[TAM_MAX];
	Aluno aluno[50];

	FILE *arqAluno;

	for(pos = 0; pos < 50; pos++){
		printf("RA:\n");
		scanf("%d", &ra);

		printf("Nome:\n");
		limpabuffer();
		fgets(nome, TAM_MAX - 3, stdin);
		for (c = 0; nome[c] != '\0' && nome[c] != '\n'; c++);
		nome[c] = '\0';

		if (strcmp(nome, "FIM") == 0)
			break;

		aluno[pos].ra = ra;
		strcpy(aluno[pos].nome, nome);

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

	qsort(aluno, tam, sizeof(Aluno), CompNome);
	arqAluno = fopen("ListaAlunosNome.cmalp", "wb");
	fwrite(aluno, sizeof(Aluno), tam, arqAluno);
	fclose(arqAluno);

	qsort(aluno, tam, sizeof(Aluno), CompMedia);
	arqAluno = fopen("ListaAlunosNota.cmalp", "wb");
	fwrite(aluno, sizeof(Aluno), tam, arqAluno);
	fclose(arqAluno);

	return 0;
}
