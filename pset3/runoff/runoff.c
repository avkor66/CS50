#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Макс избирателей и кандидатов
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// Предпочтения [i] [j] - это j-ое предпочтение избирателя i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Кандидаты имеют имя, подсчет голосов, исключенный статус
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Массив кандидатов
candidate candidates[MAX_CANDIDATES];

// Числа избирателей и кандидатов
int voter_count;
int candidate_count;

// Функциональные прототипы
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Проверка на недопустимое использование
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Заполняем массив кандидатов
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // Запрашиваем количество избирателей
    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Продолжаем запрашивать голоса
    for (int i = 0; i < voter_count; i++)
    {

        // Запрос для каждого ранга
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);
            vote(i, j, name);

            // Записать голосование, если оно недействительно
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }

        }

        printf("\n");
    }

    //Продолжаем удерживать второй тур до тех пор, пока не появится победитель
    while (true)
    {
        // Подсчитать голоса по оставшимся кандидатам
        tabulate();

        // Проверяем, выиграны ли выборы
        bool won = print_winner();

        if (won)
        {
            break;
        }

        // Устранить кандидатов на последнем месте
        int min = find_min();

        bool tie = is_tie(min);

        // Если ничья, все выигрывают
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);

                }
            }
            break;
        }

        // Устранить кого-либо с минимальным количеством голосов
        eliminate(min);

        // Сброс голосования возвращается к нулю
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Записать предпочтения, если голосование действительно
bool vote(int voter, int rank, string name)
{
    for(int i=0;i<candidate_count;i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Подсчет голосов за не исключенных кандидатов
void tabulate(void)
{
    for (int i=0;i<voter_count;i++)
    {
        for (int j=0, n=0;j<candidate_count;j++)
        {

            if(preferences[i][n] == j && candidates[j].eliminated != true)
            {
                candidates[j].votes ++;
            }
            else if(preferences[i][n] == j && candidates[j].eliminated == true)
            {
                n++;
                j=-1;
            }
        }
    }
    return;
}

// Распечатать победителя выборов, если он есть
bool print_winner(void)
{
    for(int i=0;i<candidate_count;i++)
    {
        if(candidates[i].votes >= voter_count/2+1)
        {
        printf("Winner is %s!!!\n", candidates[i].name);
        return true;
        }
    }
    return false;
}

// Возвращаем минимальное количество голосов, оставшихся у любого кандидата
int find_min(void)
{
    int min=voter_count;
    for(int i=0;i<candidate_count;i++)
    {
        if(min > candidates[i].votes && candidates[i].eliminated != true)
        {
            min = candidates[i].votes;
        }
    }
    return (int) min;
}

// Возвращаем true, если выборы связаны между всеми кандидатами, иначе false
bool is_tie(int min)
{
    int counter = 0;
    int count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (min == candidates[i].votes && candidates[i].eliminated != true) //Если минималное число равно элементу массива, то прибавляем counter
            {
                counter++;
            }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].eliminated == true) //Если минималное число равно элементу массива, то прибавляем counter
            {
                count++;
            }
    }
    if(counter == candidate_count-count)
    {
        return true;
    }
    return false;
}

// Устранить кандидата (или кандидатов) на последнем месте
void eliminate(int min)
{
    for(int i=0;i<candidate_count;i++)
    {
        if(candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}
