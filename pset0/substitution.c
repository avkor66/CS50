#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string text, textspy, textnospy, textabc, textabc2;
    int i, n, k, l, m, g, e, w = 0;
    textabc = "abcdefghijklmnopqrstuvwxyz";
    textabc2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int p = strlen(textabc);

    int c = get_int("Что вам нужно?\n Зашифровать, введите \"1\"         Расшифровать, введите \"2\"\n");
    if (c == 1)
    {
    for(;;)
    {
        text = get_string("Введите ключ:\n");
        i = strlen(text);
        if(i==26)
        {
            break;
        }
        else
        {
            printf("Вы ввели неверное число символов, ключ состоит из 26 символов.\n");
            continue;
        }
        break;
    }

    //Текст для шифрования
    textnospy = get_string("Введите текст для шифрования:\n");
    g = strlen(textnospy);
    printf("Ваш шифр: \n");
    for(i=0;i<g;i++)
    {
        k = textnospy[i];
        switch(k)
        {
            case 97: {e = textnospy[i]; w = text[0]; e = w;printf("%c",w); break; }
            case 98: {e = textnospy[i]; w = text[1]; e = w;printf("%c",w); break; }
            case 99: {e = textnospy[i]; w = text[2]; e = w;printf("%c",w); break; }
            case 100: {e = textnospy[i]; w = text[3]; e = w;printf("%c",w); break; }
            case 101: {e = textnospy[i]; w = text[4]; e = w;printf("%c",w); break; }
            case 102: {e = textnospy[i]; w = text[5]; e = w;printf("%c",w); break; }
            case 103: {e = textnospy[i]; w = text[6]; e = w;printf("%c",w); break; }
            case 104: {e = textnospy[i]; w = text[7]; e = w;printf("%c",w); break; }
            case 105: {e = textnospy[i]; w = text[8]; e = w;printf("%c",w); break; }
            case 106: {e = textnospy[i]; w = text[9]; e = w;printf("%c",w); break; }
            case 107: {e = textnospy[i]; w = text[10]; e = w;printf("%c",w); break; }
            case 108: {e = textnospy[i]; w = text[11]; e = w;printf("%c",w); break; }
            case 109: {e = textnospy[i]; w = text[12]; e = w;printf("%c",w); break; }
            case 110: {e = textnospy[i]; w = text[13]; e = w;printf("%c",w); break; }
            case 111: {e = textnospy[i]; w = text[14]; e = w;printf("%c",w); break; }
            case 112: {e = textnospy[i]; w = text[15]; e = w;printf("%c",w); break; }
            case 113: {e = textnospy[i]; w = text[16]; e = w;printf("%c",w); break; }
            case 114: {e = textnospy[i]; w = text[17]; e = w;printf("%c",w); break; }
            case 115: {e = textnospy[i]; w = text[18]; e = w;printf("%c",w); break; }
            case 116: {e = textnospy[i]; w = text[19]; e = w;printf("%c",w); break; }
            case 117: {e = textnospy[i]; w = text[20]; e = w;printf("%c",w); break; }
            case 118: {e = textnospy[i]; w = text[21]; e = w;printf("%c",w); break; }
            case 119: {e = textnospy[i]; w = text[22]; e = w;printf("%c",w); break; }
            case 120: {e = textnospy[i]; w = text[23]; e = w;printf("%c",w); break; }
            case 121: {e = textnospy[i]; w = text[24]; e = w;printf("%c",w); break; }
            case 122: {e = textnospy[i]; w = text[25]; e = w;printf("%c",w); break; }
            case 65: {e = textnospy[i]; w = text[0]; e = w;printf("%c",w-32); break; }
            case 66: {e = textnospy[i]; w = text[1]; e = w;printf("%c",w-32); break; }
            case 67: {e = textnospy[i]; w = text[2]; e = w;printf("%c",w-32); break; }
            case 68: {e = textnospy[i]; w = text[3]; e = w;printf("%c",w-32); break; }
            case 69: {e = textnospy[i]; w = text[4]; e = w;printf("%c",w-32); break; }
            case 70: {e = textnospy[i]; w = text[5]; e = w;printf("%c",w-32); break; }
            case 71: {e = textnospy[i]; w = text[6]; e = w;printf("%c",w-32); break; }
            case 72: {e = textnospy[i]; w = text[7]; e = w;printf("%c",w-32); break; }
            case 73: {e = textnospy[i]; w = text[8]; e = w;printf("%c",w-32); break; }
            case 74: {e = textnospy[i]; w = text[9]; e = w;printf("%c",w-32); break; }
            case 75: {e = textnospy[i]; w = text[10]; e = w;printf("%c",w-32); break; }
            case 76: {e = textnospy[i]; w = text[11]; e = w;printf("%c",w-32); break; }
            case 77: {e = textnospy[i]; w = text[12]; e = w;printf("%c",w-32); break; }
            case 78: {e = textnospy[i]; w = text[13]; e = w;printf("%c",w-32); break; }
            case 79: {e = textnospy[i]; w = text[14]; e = w;printf("%c",w-32); break; }
            case 80: {e = textnospy[i]; w = text[15]; e = w;printf("%c",w-32); break; }
            case 81: {e = textnospy[i]; w = text[16]; e = w;printf("%c",w-32); break; }
            case 82: {e = textnospy[i]; w = text[17]; e = w;printf("%c",w-32); break; }
            case 83: {e = textnospy[i]; w = text[18]; e = w;printf("%c",w-32); break; }
            case 84: {e = textnospy[i]; w = text[19]; e = w;printf("%c",w-32); break; }
            case 85: {e = textnospy[i]; w = text[20]; e = w;printf("%c",w-32); break; }
            case 86: {e = textnospy[i]; w = text[21]; e = w;printf("%c",w-32); break; }
            case 87: {e = textnospy[i]; w = text[22]; e = w;printf("%c",w-32); break; }
            case 88: {e = textnospy[i]; w = text[23]; e = w;printf("%c",w-32); break; }
            case 89: {e = textnospy[i]; w = text[24]; e = w;printf("%c",w-32); break; }
            case 90: {e = textnospy[i]; w = text[25]; e = w;printf("%c",w-32); break; }
            default:{printf("%c",textnospy[i]); break; }
        }
    }printf("\n");
    }
    else if (c==2)
    {
    for(;;)
    {
        text = get_string("Введите ключ:\n");
        i = strlen(text);
        if(i==26)
        {
            break;
        }
        else
        {
            printf("Вы ввели неверное число символов, ключ состоит из 26 символов.\n");
            continue;
        }
        break;
    }

    textspy = get_string("Введите шифр:\n");
    l = strlen(textspy);
    printf("Расшифрованное сообщение:\n");
    for(i=0;i<l;i++)
    {
        k = textspy[i];

        switch(k)
        {
            case 97: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 98: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 99: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 100: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 101: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 102: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 103: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 104: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 105: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 106: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 107: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 108: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 109: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 110: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 111: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 112: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 113: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 114: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 115: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 116: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 117: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 118: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 119: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 120: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 121: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 122: {
                for (n=0;n<26;n++){m=text[n];if(k==m){printf("%c",textabc[n]);}else{continue;}}break;}
            case 65: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 66: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 67: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 68: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 69: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 70: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 71: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 72: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 73: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 74: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 75: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 76: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 77: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 78: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 79: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 80: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 81: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 82: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 83: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 84: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 85: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 86: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 87: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 88: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 89: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            case 90: {
                for (n=0;n<26;n++){m=text[n];if(k==m || k==(m-32)){printf("%c",textabc2[n]);}else{continue;}}break;}
            default:{printf("%c",textspy[i]); break; }
        }
    }printf("\n");
    }
    else {
        printf("Вы не ввели не \"1\" и не \"2\", попробуйте снова.\n");
    }
}