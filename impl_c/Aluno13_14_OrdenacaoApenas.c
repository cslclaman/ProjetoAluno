/*
Chave: o valor que identifica um elemento unicamente.
Por exemplo, se você tem uma lista de inteiros, a chave dessa lista será o número.
Essa lista estará ordenada se um determinado número estiver depois de um número menor que ele e estiver antes de um número maior.
Em uma lista de alunos como a do exercício, pede-se para ordenar duas vezes, cada uma com uma chave diferente:
	1: O nome (em ordem alfabética, crescente)
	2: A nota (média entre as duas provas de cada aluno, em ordem decrescente)
Então, no caso 1, a chave JOÃO é maior (ou seja, fica depois) que a chave DANIELA.
No caso 2, a chave 7,5 é maior (fica depois) que a chave 8,75 (lembre-se, ordem decrescente).
*/

//ORDENAÇÃO POR INSERÇÃO DIRETA
//Considere que você tem um vetor de elementos chamado lista
	int c, d, pos;
	/*Tipo do elemento*/ aux;

	for (c = 1; c < tam; c++){
		pos = -1;
		for (d = c - 1; d >= 0 ; d--){
			if (/* Elemento da posição d tiver chave maior que elemento da posição c */){
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

//ORDENAÇÃO POR SELEÇÃO DIRETA
//Considere que você tem um vetor de elementos chamado lista
	int c, d, pos;
	/*Tipo do elemento*/ aux;

	for (c = 0; c < tam - 1; c++){
		pos = -1;
		aux = lista[c];
		for (d = c + 1; d < tam; d++){
			if (/* Elemento aux tiver chave maior que elemento da posição d */){
				pos = d;
				aux = lista[d];
			}
		}
		if (pos >= 0){
			aux = lista[c];
			lista[c] = lista[pos];
			lista[pos] = aux;
		}
	}
