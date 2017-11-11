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

int main (){
	int c, total, alunosI, alunosL, alunosA;
	Aluno aluno;

	FILE *arqAluno;
	arqAluno = fopen("ListaAlunosNome.cmalp", "rb");

	total = alunosI = alunosL = alunosA = 0;

	for(c = 0; c < 50; c++){
		fread(&aluno, sizeof(Aluno), 1, arqAluno);
		if (feof(arqAluno) == 1){
			break;
		}

		total++;

		if (aluno.curso == 'I'){
			alunosI++;
		}
		if (aluno.curso == 'L'){
			alunosL++;
		}
		if (aluno.curso == 'A'){
			alunosA++;
		}
	}

	printf("Total de alunos: %d\nPorcentagem de alunos de:\n", total);
	printf("\tInformatica:        %.2f%%\n", (float)alunosI / (float)total * 100 );
	printf("\tLingua estrangeira: %.2f%%\n", (float)alunosL / (float)total * 100 );
	printf("\tAdministracao:      %.2f%%\n", (float)alunosA / (float)total * 100 );

	fclose(arqAluno);

	return 0;
}
