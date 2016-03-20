#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

int main () {
    int option, entry;
    node *head, *tail;

    do {
        printf("Digite a opção desejada:\n1 - Inicializa fila\n2 - Inserção\n3 - Remoção\n4 - Verifica se está cheia\n5 - Verifica se está vazia\n6 - Imprime fila\n0 - Sair\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                head = init();
                tail = head;
                printf("Fila inicializada com NULL\n");
            break;
            case 2:
                printf("Digite um valor: ");
                scanf("%d", &entry);
                if (empty_queue(head)) {
                    head = push(head, entry);
                    tail = head;
                } else {
                    tail = push(tail, entry);
                }
            break;
            case 3:
                head = pull(head);
            break;
            case 4:
                if (full_queue(head))
                    printf("Fila está cheia\n");
                else
                    printf("Fila NÃO está cheia\n");
            break;
            case 5:
                if (empty_queue(head))
                    printf("Fila está vazia\n");
                else
                    printf("Fila NÃO está vazia\n");
            break;
            case 6:
                print_queue(head);
            break;
            case 0:
                printf("Encerrando...");
            break;
            default:
                printf("Opção inválida!\n");
        }

    } while (option != 0);

    return 0;
}
