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
	float nota1, nota2, media, presenca;
	char nomecurso[TAM_MAX], result[TAM_MAX];

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

	//Comparação com letras: sempre verifique com a letra maiúscula e com a minúscula
	if (curso == 'I' || curso == 'i'){ //SE o curso for 'I' ou for 'i'
		//Essa função copia o segundo parâmetro ("Informatica") para a string indicada pelo primeiro (nomecurso).
		strcpy(nomecurso, "Informatica");
	}
	if (curso == 'L' || curso == 'l'){
		strcpy(nomecurso, "Lingua estrangeira");
	}
	if (curso == 'A' || curso == 'a'){
		strcpy(nomecurso, "Administracao");
	}

	//Média simples.
	media = (nota1 + nota2) / 2;

	if (faltas <= 10 && media >= 6.5){
		strcpy(result, "APROVADO");
	} else {
		strcpy(result, "REPROVADO");
	}

	//Porcentagem: 40 aulas por ano = cada aula é 2.5% de presença. 100% menos % de faltas = % de presença
	presenca = 100 - (faltas * 2.5);

	printf("Aluno %d - %s, matriculado em %02d/%02d/%04d\n", ra, nome, dia, mes, ano);
	printf("Desempenho no curso de %s: %s\n", nomecurso, result);
	printf("Nota final: %.1f - Presenca: %.1f%%\n", media, presenca );

	return 0;
}
