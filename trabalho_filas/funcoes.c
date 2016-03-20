#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

node* init() {
    return NULL;
};

int empty_queue(node *head) {
    if (head == NULL) {
        return 1;
    }
    return 0;
};

int full_queue(node *head) {
    if (head == NULL) {
        return 0;
    }
    return 1;
};

node * push(node *current, int value) {
    node *next;
    next = (node *) malloc(1*sizeof(node));
    next->num = value;
    next->prox = NULL;
    if (!empty_queue(current)) {
        current->prox = next;
    }
    printf("Valor %d adicionado na posição 0x%.8X\n", next->num, next);
    return next;
};

node * pull(node *head) {
    if (empty_queue(head)) {
        printf("Fila está vazia\n");
        return NULL;
    } else {
        node *new_head;
        new_head = head->prox;
        printf("Valor %d liberado da posição 0x%.8X\n", head->num, head);
        free(head);
        return new_head;
    }
};

void print_queue(node *head) {
    node *test=NULL;

    if (empty_queue(head)) {
        printf("Fila está vazia\n");
    } else {
        test = head;
        do {
            printf("0x%.8X = %d, ", test, test->num);
            test = test->prox;
        } while (test != NULL);
        printf("\n");
    }
};
