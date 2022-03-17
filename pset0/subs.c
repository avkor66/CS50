#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After:  ");
    int v = 65;
    for (int i = 0, n = strlen(s); i < n; i++, v++)
    {
        printf("%c", toupper(s[i]));
        if (v == 67)
        {
            printf("%c", v);
            printf("%c", v);
            printf("%c", v);
            printf("%c", v);
        }
    }
    printf("\n");
}