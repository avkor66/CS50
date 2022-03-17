#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float cash;
    for (;;){
        cash = get_float("Введите сдачу\n");
        if (cash <= 0) {
            printf("Вы ввели неверное число\n");
            continue;
        }
        else {
        break;
        }
    break;
    }
    int c25, c10, c5, c1;
    c25 = cash*100 / 25;
    c10 = (cash*100 - c25*25) / 10;
    c5 = (cash*100 - c25*25 - c10*10) / 5;
    c1 = cash*100 - c25*25 - c10*10 - c5*5;
    printf("Сдача в монетах 25 центов (шт): %i\n", c25);
    printf("Сдача в монетах 10 центов (шт): %i\n", c10);
    printf("Сдача в монетах 5 центов (шт): %i\n", c5);
    printf("Сдача в монетах 1 цент (шт): %i\n", c1);
}