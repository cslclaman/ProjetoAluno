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
Conta:
	Número de alunos que cursa informática
	Maior nota de prova dentre os alunos de língua estrangeira
	Menor número de faltas dentre os alunos de Administração
*/
void ContagemAlunos(Aluno lista[], int tam, int *qtInf, float *maxLe, int *minAdm){
	int c;

	*qtInf = 0;
	*maxLe = 0;
	*minAdm = 40;

	for (c = 0; c < tam; c++){
		if (lista[c].curso == 'I'){
			*qtInf = *qtInf + 1;
		}
		if (lista[c].curso == 'L'){
			if (lista[c].nota1 > *maxLe){
				*maxLe = lista[c].nota1;
			}
			if (lista[c].nota2 > *maxLe){
				*maxLe = lista[c].nota2;
			}
		}
		if (lista[c].curso == 'A'){
			if (lista[c].faltas < *minAdm){
				*minAdm = lista[c].faltas;
			}
		}
	}
}

int main (){
	int pos, tam;

	int quantAlunosInformatica;
	float maiorNotaAlunosLinguas;
	int menorNumFaltaAlunosAdm;

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

	printf("\n------------------------------------------------------------------------\n");
    printf("DADOS DOS ALUNOS\n");
    printf("------------------------------------------------------------------------\n");

	for (pos = 0; pos < tam; pos++){
		ImprimeResult(aluno[pos]);
	}

	ContagemAlunos(aluno, tam, &quantAlunosInformatica, &maiorNotaAlunosLinguas, &menorNumFaltaAlunosAdm);

	printf("\n------------------------------------------------------------------------\n");
    printf("Quantidade de alunos que cursa informatica:                   %d\n", quantAlunosInformatica);
	printf("Maior nota de prova dos alunos que cursam Lingua Estrangeira: %.1f\n", maiorNotaAlunosLinguas);
	printf("Menor numero de faltas dos alunos que cursam Administracao:   %d\n", menorNumFaltaAlunosAdm);
    printf("------------------------------------------------------------------------\n");

	return 0;
}
