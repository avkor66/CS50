#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <crypt.h>
#include <string.h>

int main(void)
{
char *aaa = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ./012345678950";
for(int i = 0; i < strlen(aaa)-1; i ++)
{
    char st[2];
    st[0]= aaa[i];
    st[1]= aaa[i+1];
    // printf("%s\n",st);
    // printf("%c%c\n",aaa[i],aaa[i+1]);
    printf("crypt(\"12345\",\"%c%c\") = \"%s\"\n", aaa[i],aaa[i+1], crypt("12345", st));

}


// printf("crypt(\"12345\",\"aba\") = \"%s\"\n", crypt("12345", "aba"));
// printf("crypt(\"12345\",\"bc\") = \"%s\"\n", crypt("12345", "bc"));
// printf("crypt(\"12345\",\"bca\") = \"%s\"\n", crypt("12345", "bca"));
// printf("crypt(\"12345\",\"abc\") = \"%s\"\n", crypt("12345", "abc"));

 }