// Реализует проверку орфографии

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/resource.h>
#include <sys/time.h>

#include "dictionary.h"

// Undefine любые определения
#undef calculate
#undef getrusage

// Словарь по умолчанию
#define DICTIONARY "dictionaries/large"

// Опытный образец
double calculate(const struct rusage *b, const struct rusage *a);

int main(int argc, char *argv[])
{
    // Проверяем правильное количество аргументов
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./speller [DICTIONARY] text\n");
        return 1;
    }

    // Структуры для временных данных
    struct rusage before, after;

    // Тесты
    double time_load = 0.0, time_check = 0.0, time_size = 0.0, time_unload = 0.0;

    // Определить словарь для использования
    char *dictionary = (argc == 3) ? argv[1] : DICTIONARY;

    // Загрузить словарь
    getrusage(RUSAGE_SELF, &before);
    bool loaded = load(dictionary);
    getrusage(RUSAGE_SELF, &after);

    // Выход, если словарь не загружен
    if (!loaded)
    {
        printf("Could not load %s.\n", dictionary);
        return 1;
    }

    // Расчет времени загрузки словаря
    time_load = calculate(&before, &after);

    // Попробуем открыть текст
    char *text = (argc == 3) ? argv[2] : argv[1];
    FILE *file = fopen(text, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", text);
        unload();
        return 1;
    }

    // Готовимся сообщать об ошибках
    printf("\nMISSPELLED WORDS\n\n");

    // Готовимся к проверке орфографии
    int index = 0, misspellings = 0, words = 0;
    char word[LENGTH + 1];

    // Проверка правописания каждого слова в тексте
    for (int c = fgetc(file); c != EOF; c = fgetc(file))
    {
        // Разрешить только алфавитные символы и апострофы
        if (isalpha(c) || (c == '\'' && index > 0))
        {
            // Добавляем символ в слово
            word[index] = c;
            index++;

            // Игнорируем строки алфавита слишком длинные, чтобы быть словами
            if (index > LENGTH)
            {
                // потребляем остаток алфавитной строки
                while ((c = fgetc(file)) != EOF && isalpha(c));

                // Готовимся к новому слову
                index = 0;
            }
        }

        // Игнорируем слова с номерами (как MS Word может)
        else if (isdigit(c))
        {
            // потребляем остаток буквенно-цифровой строки
            while ((c = fgetc(file)) != EOF && isalnum(c));

            // Готовимся к новому слову
            index = 0;
        }

        // Должно быть, мы нашли целое слово
        else if (index > 0)
        {
            // Завершить текущее слово
            word[index] = '\0';

            // Обновить счетчик
            words++;
            // for(int y =0; y<50;y++)
            // printf("%c", word[y]);
            // printf("- bil perviy\n");

            // Проверка правописания слова
            getrusage(RUSAGE_SELF, &before);
            bool misspelled = !check(word);
            getrusage(RUSAGE_SELF, &after);

            // Проверка правописания слова
            time_check += calculate(&before, &after);

            // Напечатать слово, если написано с ошибкой
            if (misspelled)
            {
                printf("%s\n", word);
                misspellings++;
            }

            // Готовимся к следующему слову
            index = 0;
        }
    }

    // Проверяем, была ли ошибка
    if (ferror(file))
    {
        fclose(file);
        printf("Error reading %s.\n", text);
        unload();
        return 1;
    }

    // Закрыть текст
    fclose(file);

    // Определяем размер словаря
    getrusage(RUSAGE_SELF, &before);
    unsigned int n = size();
    getrusage(RUSAGE_SELF, &after);

    // Вычисляем время для определения размера словаря
    time_size = calculate(&before, &after);

    // выгрузить словарь
    getrusage(RUSAGE_SELF, &before);
    bool unloaded = unload();
    getrusage(RUSAGE_SELF, &after);

    // Прервать, если словарь не выгружен
    if (!unloaded)
    {
        printf("Could not unload %s.\n", dictionary);
        return 1;
    }

    // Вычисляем время для выгрузки словаря
    time_unload = calculate(&before, &after);

    // Отчет о тестах
    printf("\nWORDS MISSPELLED:     %d\n", misspellings);
    printf("WORDS IN DICTIONARY:  %d\n", n);
    printf("WORDS IN TEXT:        %d\n", words);
    printf("TIME IN load:         %.2f\n", time_load);
    printf("TIME IN check:        %.2f\n", time_check);
    printf("TIME IN size:         %.2f\n", time_size);
    printf("TIME IN unload:       %.2f\n", time_unload);
    printf("TIME IN TOTAL:        %.2f\n\n",
           time_load + time_check + time_size + time_unload);

    // Успех
    return 0;
}

// Возвращает количество секунд между b и a
double calculate(const struct rusage *b, const struct rusage *a)
{
    if (b == NULL || a == NULL)
    {
        return 0.0;
    }
    else
    {
        return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
                  (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
                 ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
                  (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
                / 1000000.0);
    }
}
