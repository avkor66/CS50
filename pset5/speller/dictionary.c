// Реализует функциональность словаря

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Представляет узел в хеш-таблице
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *nodes;

// Количество сегментов в хеш-таблице
const unsigned int N = 1;

// Хеш-таблица
node *table[N];

// Возвращает true, если слово находится в словаре, иначе false
bool check(const char *word)
{
    // TODO
    node *fnodes = nodes;
    while(fnodes != NULL)
    {
        if ((strlen(fnodes->word)==strlen(word)) && (strcasecmp(fnodes->word, word)==0))
        {
            return true;
        }
        else
        {
            fnodes = fnodes->next;
        }
    }
    return false;
}

// Хеширует слово в число
unsigned int hash(const char *word)
{
    int hash = toupper(word[0])-'A';
    return hash % 150000;
}

// Загружает словарь в память, возвращая true в случае успеха, иначе false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        printf("Could not open %s.\n", dictionary);
        unload();
        return false;
    }
    node *ptr = nodes;
    char newword[LENGTH+1];
    while (fgets(newword, LENGTH+1, file))
    {
        int f = strlen(newword);
        newword[f-1] = '\0';
        ptr = malloc(sizeof(node));
        int h = hash(newword);
        if (ptr == NULL)
        {
            return false;
        }
        strcpy(ptr->word, newword);
        ptr->next = nodes;
        nodes = ptr;
    }
    fclose(file);
    return true;


    // int index = 0;
    // for (int c = fgetc(file); c != EOF; c = fgetc(file))
    // {

    //     ptr = malloc(sizeof(node));
    //     // Разрешить только алфавитные символы и апострофы
    //     if (isalpha(c) || (c == '\'' && index > 0))
    //     {
    //         // Добавляем символ в слово
    //         newword[index] = c;
    //         index++;

    //         // Игнорируем строки алфавита слишком длинные, чтобы быть словами
    //         if (index > LENGTH)
    //         {
    //             // потребляем остаток алфавитной строки
    //             while ((c = fgetc(file)) != EOF && isalpha(c));

    //             // Готовимся к новому слову
    //             index = 0;
    //         }
    //     }

    //     // Игнорируем слова с номерами (как MS Word может)
    //     else if (isdigit(c))
    //     {
    //         // потребляем остаток буквенно-цифровой строки
    //         while ((c = fgetc(file)) != EOF && isalnum(c));

    //         // Готовимся к новому слову
    //         index = 0;
    //     }

    //     // Должно быть, мы нашли целое слово
    //     else if (index > 0)
    //     {
    //         // Завершить текущее слово
    //         newword[index] = '\0';

    //         index = 0;
    //     }
    //     strcpy(ptr->word, newword);
    //     ptr->next = nodes;
    //     nodes = ptr;
    // }
    // fclose(file);
    // return true;







    // if(table[h]->next==NULL)
    // {
    //     table[h]->next = ptr;
    // }
    // else
    // {
    //     ptr->next = table[h]->next;
    //     table[h]->next = ptr;
    // }
}

// Возвращает количество слов в словаре, если загружено, иначе 0, если еще не загружено
unsigned int size(void)
{
    // TODO
    int i;
    node *pointer = nodes;
    for (i = 0; pointer->next != NULL; i++)
    {
        pointer = pointer->next;
    }
    return (i+1);
}

// выгружает словарь из памяти, возвращая true в случае успеха, иначе false
bool unload(void)
{
    // TODO
    while (nodes != NULL)
    {
        node *tmp = nodes->next;
        free(nodes);
        nodes = tmp;
    }
    return true;
}
