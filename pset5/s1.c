#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>

#define N 255
#define M 20000

int main(void)
{
    FILE *f;
    int lines=0, words=0, chars=0, flag, i=0, index=0;
    int str[N];
    // str = malloc(M*sizeof(int));

    f=fopen("speller/texts/lalaland.txt", "r");

    for (int s = fgetc(f); s != EOF; s = fgetc(f))
    {
        chars++;
        if (isalpha(s) || (s == '\'' && index > 0))
        {
            // str[index] = s;
            index++;
            if(index>N)
            {
                while ((s = fgetc(f)) != EOF && isalpha(s));
                index=0;
            }
        }
        else if (isdigit(s))
        {
             while ((s = fgetc(f)) != EOF && isalpha(s));
             index=0;
        }
        else if (s == '\n')
        {
            lines++;
            index=0;
        }
        else if (index > 0 && (!isalpha(s) || s != '\''))
        {
            // str[index] = '\0';
            words++;
            index=0;
        }
    }
        printf("%i\n", lines);
        printf("%i\n", words);
        printf("%i\n", chars);



    fclose(f);

}