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

int PesquisaAluno(Aluno lista[], int tam, char nomePesq[]){
	int c;
	for (c = 0; c < tam && strcmp(lista[c].nome, nomePesq) != 0; c ++);
	if (c == tam){
		return -1;
	} else {
		return c;
	}
}

int main (){
	int c, pos, tam, ra;
	char nome[TAM_MAX];
	Aluno aluno[50];

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

	ImprimelistaAlunos(aluno, tam);

	printf("Nome a pesquisar:\n");
	fgets(nome, TAM_MAX - 3, stdin);
	for (c = 0; nome[c] != '\0' && nome[c] != '\n'; c++);
	nome[c] = '\0';
	puts(nome);

	pos = PesquisaAluno(aluno, tam, nome);

	if (pos >= 0){
		printf("Aluno encontrado - posicao %d\n", pos);
	} else {
		printf("NOT FOUND\n");
	}

	return 0;
}
