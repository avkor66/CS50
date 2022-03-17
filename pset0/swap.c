#include <cs50.h>
#include <stdio.h>



int main(void)
{
        int a = get_int("Введите первое число:");
        printf("\n");
        printf("Вы ввели первое число: %i\n", a);
        printf("Вы ввели первое число с адресом: %p\n", &a);
        printf("\n");
        int b = get_int("Введите второе число:");
        printf("\n");
        printf("Вы ввели второе число: %i\n", b);
        printf("\n");
        printf("Меняем...\n");
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        printf("Поменяли.\n");
        printf("\n");
        printf("\n");
        printf("Вы ввели первое число: %i\n", a);
        printf("Вы ввели первое число с адресом: %p\n", &a);
        printf("\n");
        printf("Вы ввели второе число: %i\n", b);




}