#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct stack {
    int data;
    char *string;
    struct stack *next;
};

// struct stack *create(struct stack *head, int x);
// void list(struct stack *p);
// void searh(struct stack *k);

int main() {
    char n[255], m[255], h[255];
    printf("Введите слово: ");
    fgets(n, 255, stdin);
    printf("\nВвели: %s", n);

    printf("\nВведите строку: ");
    fgets(m, 255, stdin);

    printf("\nВвели: %s", m);
    printf("\nВведите символы: ");
    fgets(h, 255, stdin);
    printf("\nВвели: %s", h);





    // int i, n;
    // struct stack *head;
    // head = NULL;

    // printf("Введите число: ");
    // scanf("%d", &n);
    // for(i=0; i<=n;i++)
    // {
    //     head = create(head, i);
    //     printf("%d<--", head->data);
    // }
    // printf("\n");
    // list(head);
    // searh(head);
    // free(head);
}

struct stack *create(struct stack *head, int x) {
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
        printf("Я ищу...   ");
        printf("Проверил это %d\n", k->data);
        printf("Проверил и это %p\n", k->next);
        if ( k->data == 3)
        {
            printf("Я нашел К, Гип,гип Ура! %d\n\n", k->data);
            return;
        }
        k = k->next;
    }
    printf("\n  Я не нашел 3...\n");
}
