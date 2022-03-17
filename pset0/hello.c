#include <cs50.h>
#include <stdio.h>


int main(void)
{
    //string name = get_string("What's your name?\n");
    //printf("hello, %s\n", name);
    float f = get_float("Введите число\n");
    int n = f;
    int i = n % 3;
    printf("Ваше введенное число с точкой: %i\n", n);
    printf("Количество четвертаков: %i\n", i);
}