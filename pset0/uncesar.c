#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int atoi (const char *str);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("%s key\n", argv[0]);
        return 1;
    }
    int q = strlen(argv[1]);
    for(int i=0;i<q;i++)
    {
        if(argv[1][i]>='A' && argv[1][i]<='Z') {printf("%s key\n", argv[0]); return 1;}
        if(argv[1][i]>='a' && argv[1][i]<='z') {printf("%s key\n", argv[0]); return 1;}
    }
    int c = atoi (argv[1]);
    string plaintext, chiphertext;
    chiphertext = get_string("chiphertext = ");
    int u = strlen(chiphertext);
    printf("plaintext = ");
    int j, l, d;
    for(int i=0;i<u;i++)
    {
        d = chiphertext[i]-c;
        j = chiphertext[i];
        for(;chiphertext[i]>=97 && chiphertext[i]<=122;)
        {
        if(d<'a')
        {
        d=d+26;
        continue;
        }
        else
        {
        printf("%c", d);
        break;
        }
        }

        for(;chiphertext[i]>=65 && chiphertext[i]<=90;)
        {
        if(d<'A')
        {
        d=d+26;
        continue;
        }
        else
        {
        printf("%c", d);
        break;
        }
        }
        for(;chiphertext[i]<65 || chiphertext[i]>122;)
        {
        printf("%c", j);
        break;
        }
        for(;chiphertext[i]>90 && chiphertext[i]<97;)
        {
        printf("%c", j);
        break;
        }
    }
            printf("\n");
}