#include <stdio.h>
#include <stdlib.h>

// Представляет узел
typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(void)
{
    // Список размером 0, изначально ни на что не указывающий
    node *list = NULL;


    // Добавить номер в список
    node *n;



    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;
    // Теперь мы идем наш первый узел, на который указывает список, и устанавливаем следующий указатель
    // на нем, чтобы указать на наш новый узел, добавив его в конец списка:
    list = n;

    // Добавить номер в список
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    // Теперь мы идем наш первый узел, на который указывает список, и устанавливаем следующий указатель
    // на нем, чтобы указать на наш новый узел, добавив его в конец списка:
    list->next = n;

    // Добавить номер в список
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    // Мы можем следовать нескольким узлам с этим синтаксисом, используя следующий указатель
    // снова и снова, чтобы добавить наш третий новый узел в конец списка:
    list->next->next = n;
    // Обычно, однако, мы бы хотели добавить цикл и временную переменную
    // новый узел в нашем списке.
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 4;
    n->next = NULL;
    // Мы можем следовать нескольким узлам с этим синтаксисом, используя следующий указатель
    // снова и снова, чтобы добавить наш третий новый узел в конец списка:
    list->next->next->next = n;
    // Обычно, однако, мы бы хотели добавить цикл и временную переменную
    // новый узел в нашем списке.
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->number = 5;
    n->next = NULL;
    // Мы можем следовать нескольким узлам с этим синтаксисом, используя следующий указатель
    // снова и снова, чтобы добавить наш третий новый узел в конец списка:
    list->next->next->next->next = n;
    // Обычно, однако, мы бы хотели добавить цикл и временную переменную
    // новый узел в нашем списке.
    node *tm = malloc(sizeof(node));
    if (tm != NULL)
    {
        tm->number = 0;
        tm->next = list;
    }
    list = tm;

    tm = malloc(sizeof(node));
    node *newq = list;

    while (newq->next != NULL)
        newq = newq->next;

        tm->number = 6;
        tm->next = NULL;
        newq->next = tm;

    tm = NULL;
    tm = malloc(sizeof(node));
    node *newqq = list;

        tm->number = 6;
    while (newqq->next != NULL)
    {
        if (newqq->number == 4)
        {
        tm->next = newqq->next;
        newqq->next = tm;
        break;
        }
        else
        {
        newqq = newqq->next;
        }
    }

    // node *tm2 = malloc(sizeof(node));
    // if (tm2 != NULL)
    // {
    //     tm2->number = 0;
    //     tm2->next = NULL;
    // }
    // tm2->next = list[3].next;
    // list[3] = *tm2;

    // node *sp = list;
    // while (sp->next != NULL)
    // {
    //     sp = sp->next;
    // }
    // do
    // {
    //     node *tr;
    //     tr = malloc(sizeof(node));
    //     tr = list->next;
    //     if (tr == NULL)
    //         list->next = tm;
    // }
    // while (list->next != NULL);
    // list->next->next->next->next->next = tm;
    // while(list->next != NULL)
    // {
    //     list = list->next;
    //     if (list->next == NULL)
    //         list->next = tm;
    // }
    // list = tm;
    // while (list->next != NULL)
    // {
    //     list = list->next;
    // }
    // list->next = tm;
    // list->next = tmp2;
    // Распечатать список
    // Здесь мы можем перебрать все узлы в нашем списке с временным
    // переменная Во-первых, у нас есть временный указатель, tmp, который указывает на
    // список. Тогда наше условие продолжения состоит в том, что tmp не равен NULL, и
    // наконец, мы обновляем tmp до следующего указателя.
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        // Внутри узла мы просто распечатаем сохраненное число:
        printf("%i\n", tmp->number);
    }

    // Свободный список
    // Поскольку мы освобождаем каждый узел по мере продвижения, мы будем использовать цикл while
    // и следуем за следующим указателем каждого узла перед его освобождением, но посмотрим
    // это более подробно в Задаче 5.
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}
