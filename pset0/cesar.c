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
    }
    int q = strlen(argv[1]);
    for(int i=0;i<q;i++)
    {
        if(argv[1][i]>='A' && argv[1][i]<='Z') {printf("%s key\n", argv[0]); return 1;}
        if(argv[1][i]>='a' && argv[1][i]<='z') {printf("%s key\n", argv[0]); return 1;}
    }

    int c = atoi (argv[1]);
    string plaintext, chiphertext;
    plaintext = get_string("plaintext = ");
    int u = strlen(plaintext);
    printf("chiphertext = ");
    int j, l, d;
    for(int i=0;i<u;i++)
    {
        d = plaintext[i]+c;
        j = plaintext[i];
        for(;plaintext[i]>=97 && plaintext[i]<=122;)
        {
        if(d>'z')
        {
        d=d-26;
        continue;
        }
        else
        {
        printf("%c", d);
        break;
        }
        }

        for(;plaintext[i]>=65 && plaintext[i]<=90;)
        {
        if(d>'Z')
        {
        d=d-26;
        continue;
        }
        else
        {
        printf("%c", d);
        break;
        }
        }
        for(;plaintext[i]<65 || plaintext[i]>122;)
        {
        printf("%c", j);
        break;
        }
        for(;plaintext[i]>90 && plaintext[i]<97;)
        {
        printf("%c", j);
        break;
        }
    }
            printf("\n");
}