#include <stdio.h>

float add (int,int); /* function prototype for add */

int main()
{
    printf("%f\n", add(3,2));
}

float add(int i, int j)
{
    return i+j;
}