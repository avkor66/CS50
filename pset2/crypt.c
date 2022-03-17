// #include <cs50.h>
#include <stdio.h>
#define _XOPEN_SOURCE
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>
#include <crypt.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[]);



int main(int argc, char *argv[])
{
    // Проверяем правильное количество аргументов
    if (argc != 2)
    {
        printf("программа должна принимать два значения.\n");
        return 1;
    }
    char *abc = "1234567890";
    char *pass = argv[1];
    char id[3];
    int i,j,n,m,k,l,y,x,z;
    for(i = 0; i<2; i++)
    {
        id[i] = pass[i];
        if(i==1)
        {
            id[2] = '\0';
        }
    }
    char *iii;
    // printf("%s\n",iii);
    int argvs=strlen(pass);
    int r = strlen(abc);
    int de;
    for(int yy = 2; yy <10;yy++)
    {
    char cc[yy];
    if(yy==2)
    {
        for(i=0;i<r;i++)
        {
        cc[0]=abc[i];
        cc[1]='\0';
                                            iii=crypt(cc, id);
                                    for(z=0;z<argvs;z++)
                                    {
                                        if(iii[z]!=pass[z])
                                        {
                                            de = 0;
                                            break;
                                        }
                                        else
                                        {
                                            de+=1;
                                            continue;
                                        }
                                    }
                                    if(de==argvs)
                                    {
                                        printf("%s\n",cc);
                                    }

        }
    }

        if(yy==3)
    {
    for(i=0;i<r;i++)
    {
        cc[0]=abc[i];
        for(j=0;j<r;j++)
        {
            cc[1]=abc[j];
                                   de = 0;
                                    cc[2]='\0';
                                    iii=crypt(cc, id);
                                    for(z=0;z<argvs;z++)
                                    {
                                        if(iii[z]!=pass[z])
                                        {
                                            de = 0;
                                            break;
                                        }
                                        else
                                        {
                                            de+=1;
                                            continue;
                                        }
                                    }
                                    if(de==argvs)
                                    {
                                        printf("%s\n",cc);
                                    }

        }
                                    // printf("%s\n",cc);
    }
    }


        if(yy==4)
    {
    for(i=0;i<r;i++)
    {
        cc[0]=abc[i];
        for(j=0;j<r;j++)
        {
            cc[1]=abc[j];
            for(n=0;n<r;n++)
            {
                cc[2]=abc[n];
                                    de = 0;
                                    cc[3]='\0';
                                    iii=crypt(cc, id);
                                    for(z=0;z<argvs;z++)
                                    {
                                        if(iii[z]!=pass[z])
                                        {
                                            de = 0;
                                            break;
                                        }
                                        else
                                        {
                                            de+=1;
                                            continue;
                                        }
                                    }
                                    if(de==argvs)
                                    {
                                        printf("%s\n",cc);
                                    }
            }
        }
                                    // printf("%s\n",cc);
    }
    }



        if(yy==5)
    {
    for(i=0;i<r;i++)
    {
        cc[0]=abc[i];
        for(j=0;j<r;j++)
        {
            cc[1]=abc[j];
            for(n=0;n<r;n++)
            {
                cc[2]=abc[n];
                for(m=0;m<r;m++)
                {
                    cc[3]=abc[m];
                                    de = 0;
                                    cc[4]='\0';
                                    iii=crypt(cc, id);
                                    for(z=0;z<argvs;z++)
                                    {
                                        if(iii[z]!=pass[z])
                                        {
                                            de = 0;
                                            break;
                                        }
                                        else
                                        {
                                            de+=1;
                                            continue;
                                        }
                                    }
                                    if(de==argvs)
                                    {
                                        printf("%s\n",cc);
                                    }

                }
            }
        }
                                    // printf("%s\n",cc);
    }
    }



        if(yy==6)
    {
    for(i=0;i<r;i++)
    {
        cc[0]=abc[i];
        for(j=0;j<r;j++)
        {
            cc[1]=abc[j];
            for(n=0;n<r;n++)
            {
                cc[2]=abc[n];
                for(m=0;m<r;m++)
                {
                    cc[3]=abc[m];
                    for(k=0;k<r;k++)
                    {
                        cc[4]=abc[k];
                        for(l=0;l<r;l++)
                        {
                                    de = 0;
                                    cc[5]='\0';
                                    iii=crypt(cc, id);
                                    for(z=0;z<argvs;z++)
                                    {
                                        if(iii[z]!=pass[z])
                                        {
                                            de = 0;
                                            break;
                                        }
                                        else
                                        {
                                            de+=1;
                                            continue;
                                        }
                                    }
                                    if(de==argvs)
                                    {
                                        printf("%s\n",cc);
                                    }
                        }
                    }
                }
            }
        }
                                    // printf("%s\n",cc);
    }
    }




        if(yy==7)
    {
    for(i=0;i<r;i++)
    {
        cc[0]=abc[i];
        for(j=0;j<r;j++)
        {
            cc[1]=abc[j];
            for(n=0;n<r;n++)
            {
                cc[2]=abc[n];
                for(m=0;m<r;m++)
                {
                    cc[3]=abc[m];
                    for(k=0;k<r;k++)
                    {
                        cc[4]=abc[k];
                        for(l=0;l<r;l++)
                        {
                            cc[5]=abc[l];
                                    de = 0;
                                    cc[6]='\0';
                                    iii=crypt(cc, id);
                                    for(z=0;z<argvs;z++)
                                    {
                                        if(iii[z]!=pass[z])
                                        {
                                            de = 0;
                                            break;
                                        }
                                        else
                                        {
                                            de+=1;
                                            continue;
                                        }
                                    }
                                    if(de==argvs)
                                    {
                                        printf("%s\n",cc);
                                    }


                        }
                    }
                }
            }
        }
                                    // printf("%s\n",cc);
    }
    }



        if(yy==8)
    {
    for(i=0;i<r;i++)
    {
        cc[0]=abc[i];
        for(j=0;j<r;j++)
        {
            cc[1]=abc[j];
            for(n=0;n<r;n++)
            {
                cc[2]=abc[n];
                for(m=0;m<r;m++)
                {
                    cc[3]=abc[m];
                    for(k=0;k<r;k++)
                    {
                        cc[4]=abc[k];
                        for(l=0;l<r;l++)
                        {
                            cc[5]=abc[l];
                            for(y=0;y<r;y++)
                            {
                                cc[6]=abc[y];
                                    de = 0;

                                    cc[7]='\0';
                                    iii=crypt(cc, id);
                                    for(z=0;z<argvs;z++)
                                    {
                                        if(iii[z]!=pass[z])
                                        {
                                            de = 0;
                                            break;
                                        }
                                        else
                                        {
                                            de+=1;
                                            continue;
                                        }
                                    }
                                    if(de==argvs)
                                    {
                                        printf("%s\n",cc);
                                    }

                            }
                        }
                    }
                }
            }
        }
                                    // printf("%s\n",cc);
    }
    }



    if(yy==9)
    {
    for(i=0;i<r;i++)
    {
        cc[0]=abc[i];
        for(j=0;j<r;j++)
        {
            cc[1]=abc[j];
            for(n=0;n<r;n++)
            {
                cc[2]=abc[n];
                for(m=0;m<r;m++)
                {
                    cc[3]=abc[m];
                    for(k=0;k<r;k++)
                    {
                        cc[4]=abc[k];
                        for(l=0;l<r;l++)
                        {
                            cc[5]=abc[l];
                            for(y=0;y<r;y++)
                            {
                                cc[6]=abc[y];
                                for(x=0;x<r;x++)
                                {
                                    de = 0;
                                    cc[7]=abc[x];
                                    cc[8]='\0';
                                    iii=crypt(cc, id);
                                    for(z=0;z<argvs;z++)
                                    {
                                        if(iii[z]!=pass[z])
                                        {
                                            de = 0;
                                            break;
                                        }
                                        else
                                        {
                                            de+=1;
                                            continue;
                                        }
                                    }
                                    if(de==argvs)
                                    {
                                        printf("%s\n",cc);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
                                    // printf("%s\n",cc);
    }
    }


    // printf("crypt(\"%i\",\"%s\") = \"%s\"\n", i, id, crypt(&cc, id));



}
}











/* itoa:  конвертируем n в символы в s */
 void itoa(int n, char s[])
 {
     int i, sign;

     if ((sign = n) < 0)  /* записываем знак */
         n = -n;          /* делаем n положительным числом */
     i = 0;
     do {       /* генерируем цифры в обратном порядке */
         s[i++] = n % 10 + '0';   /* берем следующую цифру */
     } while ((n /= 10) > 0);     /* удаляем */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }

 /* reverse:  переворачиваем строку s на месте */
 void reverse(char s[])
 {
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }