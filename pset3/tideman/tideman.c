#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Максимальное количество кандидатов
#define MAX 9

// Предпочтения [i] [j] - число избирателей, которые предпочитают i над j
int preferences[MAX][MAX];

// заблокирован [i] [j] означает, что i заблокирован через j
bool locked[MAX][MAX];

// У каждой пары есть победитель, проигравший
typedef struct
{
    int winner;
    int loser;
}
pair;

// Массив кандидатов
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;


// Функциональные прототипы
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Проверка на недопустимое использование
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Заполняем массив кандидатов
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Очистить график заблокированных в парах
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Запрос голосов
    for (int i = 0; i < voter_count; i++)
    {
        // ранг [i] - предпочтение i-го избирателя
        int ranks[candidate_count];

        // Запрос для каждого ранга
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);
            //vote(j, name, ranks);
            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }
    // for (int o = 0; o<10; o++)
    // {
    //     for (int p = 0; p<10; p++)
    //     {
    //         printf("%i", preferences[o][p]);
    //     }
    //     printf("\n");
    // }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Обновление рангов при новом голосовании
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for(int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Обновление предпочтений с учетом рейтинга одного избирателя
void record_preferences(int ranks[])
{
    //TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; i > j; j++)
        {
            preferences[ranks[j]][ranks[i]] ++;
        }
    }
    return;
}

// Записываем пары кандидатов, где один предпочтительнее другого
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(preferences[i][j]>preferences[j][i] && i != j)
            {
            pairs[pair_count].winner = i;
            pairs[pair_count].loser = j;
            pair_count++;
            }
            else if (preferences[i][j]<preferences[j][i] && i != j)
            {
            pairs[pair_count].loser = i;
            pairs[pair_count].winner = j;
            pair_count++;
            }
            else
            {
                continue;
            }
        }

    }
    // printf("%i", pairs[0].winner);
    // printf("%i\n", pairs[0].loser);
    // printf("%i", pairs[1].winner);
    // printf("%i\n", pairs[1].loser);
    // printf("%i", pairs[2].winner);
    // printf("%i\n", pairs[2].loser);
    // printf("%i\n", pair_count);
    return;
}

// Сортировка пар в порядке убывания по силе победы
void sort_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        for(int j = 0; j < pair_count; j++)
        {
            if (preferences[pairs[j].winner][pairs[j].loser]<preferences[pairs[j+1].winner][pairs[j+1].loser])
            {
            pair tmp = pairs[j];
            pairs[j] = pairs[j+1];
            pairs[j+1] = tmp;
            }
        }

    }
    // printf("%i", pairs[0].winner);
    // printf("%i\n", pairs[0].loser);
    // printf("%i", pairs[1].winner);
    // printf("%i\n", pairs[1].loser);
    // printf("%i", pairs[2].winner);
    // printf("%i\n", pairs[2].loser);
    // printf("%i", pairs[3].winner);
    // printf("%i\n", pairs[3].loser);
    // printf("%i", pairs[4].winner);
    // printf("%i\n", pairs[4].loser);
    // printf("%i", pairs[5].winner);
    // printf("%i\n", pairs[5].loser);
    // printf("%i", pairs[6].winner);
    // printf("%i\n", pairs[6].loser);
    // printf("%i\n", pair_count);

    return;
}

// Блокируем пары в графике кандидата по порядку, не создавая циклов
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i <pair_count; i++)
    {
        locked[pairs[i].winner][pairs[i].loser] = true;
    }





    // for (int o = 0; o<candidate_count; o++)
    // {
    //     for (int p = 0; p<candidate_count; p++)
    //     {
    //         printf("%i", locked[p][o]);
    //     }
    //     printf("\n");
    // }

    return;
}

// Распечатать победителя выборов
void print_winner(void)
{
    // TODO
    pair win[candidate_count];
    for (int j = 0; j < candidate_count; j++)
    {
        win[j].winner = 0;
        win[j].loser = 0;
    }
    for (int i = 0; i<candidate_count; i++)
    {
        for (int j = 0; j<candidate_count; j++)
        {
            win[i].winner += locked[i][j];
            win[i].loser = i;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            if (win[j].winner<win[j+1].winner)
            {
            pair tmp = win[j];
            win[j] = win[j+1];
            win[j+1] = tmp;
            }
        }

    }
    printf("Победил: %s\n", candidates[win[0].loser]);
    return;
}

