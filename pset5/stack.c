#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define P 255

struct stack {
    int data;
    char str[P];
    struct stack *next;
};

struct stack *create(struct stack *head, int x);
void list(struct stack *p);
void searh(struct stack *k);

int main() {
    int i=0, n;
    struct stack *head;
    head = NULL;

    printf("Введите число: ");
    // scanf("%d", &n);
    scanf("%d", &n);
    printf("Ввели: %d\n", n);

    while (getchar() != '\n');
    // rewind(stdin);
    // fflush(stdin);
    while(i<=n)
    {

        head = create(head, i);
        printf("%d and ", head->data);
        printf("%s\n", head->str);
        i++;
    }
    printf("\n");
    list(head);
    searh(head);
    free(head);
}

struct stack *create(struct stack *head, int x) {
    struct stack *element;
    element = (struct stack *)malloc(sizeof(struct stack));
    char newstr[P];
    printf("Введите слово: \n");

    fgets(newstr, P, stdin);

    for(int i = 0;i < strlen(newstr);i++)
    {
        element -> str[i] = newstr[i];
    }
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
        printf("Проверил и это %s\n", k->str);
        if ( k->data == 3)
        {
            printf("Я нашел К, Гип,гип Ура! %d\n\n", k->data);
            return;
        }
        k = k->next;
    }
    printf("\n  Я не нашел 3...\n");
}
