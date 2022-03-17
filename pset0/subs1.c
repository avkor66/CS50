#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    // int toupper(int argv);
    int q = strlen(argv[1]);
    if(q!=26)
    {
    printf("Ключ должен состоять из 26 символов, у вас же напечатано всего - \"%i\" символов в ключе.\n", q);
        return 1;
    }
    for(int n=0;n<26;n++)
    {
        if (argv[1][n] >= 65 && argv[1][n] <= 90)
        {
        continue;
        }
        else if (argv[1][n] >= 97 && argv[1][n] <= 122)
        {
        argv[1][n] = argv[1][n] - 32;
        continue;
        }
        else
        {
        printf("%s key\n", argv[0]);
        return 1;
        }
    }
    for(int r=0;r<26;r++)
    {
        for(int m=0;m<26;m++)
        {
        if(argv[1][r]==argv[1][m] && r!=m) { printf("Ключ должен состоять из 26 символов отличных друг от друга, у вас же символы в ключе повторяются.\n"); return 1; }
        else { break; }
        }
    }
    int o = get_int("Что вы хотите: зашифровать - 1; расшифровать - 2;\n Введите одну цифру: ");
    if (o==1)
    {
    string tns;
    tns = get_string("Введите ваш текст, который хотите зашифровать: ");
    int n = strlen(tns);

    printf("Ваш шифр: ");
    int j, l;
    for(int i=0;i<n;i++)
    {
        for (j=65, l=97; j<91 && l<123; j++, l++)
        {
            if (tns[i]==j)
            {
                printf("%c", argv[1][j-65]);
            }
            else if (tns[i]==l)
            {
                printf("%c", argv[1][l-97]+32);
            }
            else if (tns[i] < 65)
            {
                printf("%c", tns[i]);
                break;
            }
            else if (tns[i] > 90 && tns[i] < 97)
            {
                printf("%c", tns[i]);
                break;
            }
            else if (tns[i] > 122)
            {
                printf("%c", tns[i]);
                break;
            }
        }
    }
            printf("\n");
    }
    else if (o==2)
    {
    string ts, textabc;
    textabc = "abcdefghijklmnopqrstuvwxyz";
    ts = get_string("Введите ваш текст, который хотите расшифровать: ");
    int n = strlen(ts);
    printf("Ваш расшифрованный текст: ");
    int i, j, l;
        for(i=0;i<n;i++)
        {
            for (j=65, l=97; j<91 && l<123; j++, l++)
            {
                if (ts[i]==argv[1][j-65])
                {
                    printf("%c", textabc[j-65]-32);
                }
                else if (ts[i]-32==(argv[1][l-97]))
                {
                    printf("%c", textabc[l-97]);
                }
                else if (ts[i] < 65)
                {
                    printf("%c", ts[i]);
                    break;
                }
                else if (ts[i] > 90 && ts[i] < 97)
                {
                    printf("%c", ts[i]);
                    break;
                }
                else if (ts[i] > 122)
                {
                    printf("%c", ts[i]);
                    break;
                }
            }
        }
            printf("\n");
    }
    else
    {
    printf("Вы не ввели не \"1\" и не \"2\", попробуйте снова.\n");
    return 0;
    }
}