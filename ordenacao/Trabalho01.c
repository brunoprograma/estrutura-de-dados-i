#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 30

typedef struct _node {
	int data;
	struct _node *prev;
	struct _node *next;
} node;

void preencheLista(node **lista, int n);
void printLista(node *lista);
void insertionSortLista(node *lista);
void preencheVetor(int vetor[], int n);
void printVetor(int vetor[], int n);
void insertionSortVetor(int vetor[], int n);

int main() {
	int vetor[MAX];
	node *lista = NULL;
	clock_t start, stop;

	printf("Preenchendo vetor e lista com números aleatórios...\n");
	preencheVetor(vetor, MAX);
	printf("Vetor\n");
	printVetor(vetor, MAX);
	preencheLista(&lista, MAX);
	printf("Lista\n");
	printLista(lista);

	printf("Iniciando insertionSort em vetor...\n");
	start = clock();
	insertionSortVetor(vetor, MAX);
	stop = clock();
	printf("insertionSort em vetor concluído!\n");
	printVetor(vetor, MAX);
	printf("Tempo decorrido: %lf segundos.\n", ((double)(stop - start) / CLOCKS_PER_SEC));

	printf("Iniciando insertionSort em lista...\n");
	start = clock();
	insertionSortLista(lista);
	stop = clock();
	printf("insertionSort em lista concluído!\n");
	printLista(lista);
	printf("Tempo decorrido: %lf segundos.\n", ((double)(stop - start) / CLOCKS_PER_SEC));

	return 0;
}

void preencheLista(node **lista, int n) {
	node *temp, *head = NULL, *last = NULL;
	int data, i;

	srand(time(NULL));

	for (i = 0; i < n; i++) {
		data = rand() % n;
		temp = (node *) malloc(sizeof(node));
		temp->data = data;
		temp->prev = NULL;
		temp->next = NULL;
		if (last == NULL) {
			head = last = temp;
		} else {
			last->next = temp;
			temp->prev = last;
			last = temp;
		}
	}

	*lista = head;
}

void printLista(node *lista) {
	node *test;

	for (test = lista; test != NULL; test = test->next) {
		printf("%d ", test->data);
	}

	printf("\n");
}

void insertionSortLista(node *lista) {
	int chave;
	node *i, *j;

	if (lista->next == NULL)
		return;

	for (j = lista->next; j != NULL; j = j->next) {
		chave = j->data;
		i = j->prev;
		while (i != NULL && i->data > chave) {
			i->next->data = i->data;
			i = i->prev;
		}
		if (i == NULL)
			lista->data = chave;
		else
			i->next->data = chave;
	}
}

void preencheVetor(int vetor[], int n) {
	int data, i;

	srand(time(NULL));

	for (i = 0; i < n; i++) {
		data = rand() % n;
		vetor[i] = data;
	}
}

void printVetor(int vetor[], int n) {
	int i;

	for (i=0; i < n; i++) {
		printf("%d ", vetor[i]);
	}
	printf("\n");
}

void insertionSortVetor(int vetor[], int n) {
	int i, j, chave;

	for (j = 1; j < n; j++) {
		chave = vetor[j];
		i = j - 1;
		while (i >= 0 && vetor[i] > chave) {
			vetor[i+1] = vetor[i];
			i--;
		}
		vetor[i+1] = chave;
	}
}