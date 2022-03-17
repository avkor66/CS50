#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{

    bool flag = true;

    string art = get_string("Введите  ваше имя: ");

    for(int i = 0, g = strlen(art); i < g; i++)
    {
        //isblank() true if space
        //isspace() true if space character
        //isgraph() true if character not space

        // printf("%c", toupper(art[i]));

        if(isgraph(art[i]) && flag)

        {
            printf("%c",toupper(art[i]));

            flag = false;
        }

        else if(isspace(art[i]) && !flag)

        {
            flag = true;
        }

        else

        {
            continue;
        }
    }
    printf("\n");
    return 1;
}
