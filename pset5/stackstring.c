#include <stdio.h>
#include <stdlib.h>

#define M 20

struct stack {
    char data[M];
    struct stack *next;
};

struct stack *create(struct stack *head, char *x);
void list(struct stack *p);
void searh(struct stack *k);

int main() {
    char i[M];
    struct stack *head;
    head = NULL;

    head = create(head, i[]);

    fgets(head, M, stdin);

    for(i=0; i<=n;i++)
    {
        head = create(head, i);
        printf("%d<--", head->data);
    }
    printf("\n");
    list(head);
    searh(head);
    free(head);
}

struct stack *create(struct stack *head, char *x) {
    struct stack *element;
    element = (struct stack *)malloc(sizeof(struct stack));
    element -> next = head;
    element -> data = x;
    return element;
}

void list(struct stack *p) {
    while (p != NULL)
    {
        printf("%d-->", p->data);
        p = p->next;
    }
    printf("\n");

}

void searh(struct stack *k) {
    while (k != NULL)
    {
        if ( k->data == 33)
        {
            printf("Я нашел К, Гип,гип Ура! %d", k->data);
            return;
        }
        k = k->next;

    }
    printf("\n  Я не нашел 33...\n");

}
