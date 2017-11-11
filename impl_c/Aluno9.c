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

/*
Essa rotina imprime os dados e o resultado do aluno.
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
	int pos, tam;
	Aluno aluno[50];

	for(pos = 0; pos < 50; pos++){
		int c, ra;
		char nome[TAM_MAX];

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

    printf("\n------------------------------------------------------------------------\n");
    printf("DADOS DOS ALUNOS\n");
    printf("------------------------------------------------------------------------\n");

	for (pos = 0; pos < tam; pos++){
		ImprimeResult(aluno[pos]);
		/*
		char primnome[TAM_MAX], ultnome[TAM_MAX], primultnome[TAM_MAX];

		PrimeiroNome(aluno.nome, primnome);
		UltimoNome(aluno.nome, ultnome);
		PrimeiroUltimoNome(aluno.nome, primultnome);

		printf("Primeiro nome: %s\n", primnome);
		printf("Ultimo nome: %s\n", ultnome);
		printf("Primeiro e ultimo nome: %s\n", primultnome);
		*/
	}

	return 0;
}
