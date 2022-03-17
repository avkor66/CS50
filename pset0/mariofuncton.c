#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Введите размер пирамиды: ");
    }
    while (n < 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > (i+1); j--)
        {
            printf(" ");
        }

        for (int j = 0; j < (i+1); j++)
        {
            printf("#");
        }
            printf("  ");
        for (int j = 0; j < (i+1); j++)
        {
            printf("#");
        }
        printf("\n");
    }
}