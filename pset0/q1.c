// Capitalizes a copy of a string

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char *s = get_string("s: ");

    char *t = malloc(strlen(s) + 1);

    for (int i = 0, n = strlen(s); i < n + 1 ; i++)
    {
        t[i] = s[i];
    }

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: \n");
    for(int i = 0; i<strlen(t)+100; i++)
    {
//    if(t[i] == '0')
  //  {
    //    break;
    //}
    //else {
    printf("%i%c\n", i, t[i]);

    //}
    }
    printf("\n");




    free(t);
}