#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{

    float a;
    float b;

    a = get_int("Введите x: ");

    b = get_int("Введите y: ");

    printf("Если разделить x на y (x / y) то получим: %.50f\n", a / b);


    float x = get_float("Введите x: ");
    float y = get_int("Введите y: ");

    printf("Если возвести x в степень y то получим: %.50f\n", pow(x, y));

}