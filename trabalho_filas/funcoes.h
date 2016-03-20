struct Node{
    int num;
    struct Node *prox;
};
typedef struct Node node;

node* init();
int empty_queue(node *head);
int full_queue(node *head);
node * push(node *last, int value);
node * pull(node *head);
void print_queue(node *head);
