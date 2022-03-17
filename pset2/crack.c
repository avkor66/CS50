#include <stdio.h>
#include <ctype.h>
#include <crypt.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define _XOPEN_SOURCE

int search_hash(char *hash, char *hashing);
char brute_force(char *abc, char *id, int index, int length_abc, char *password, char *hash);



int main(int argc, char *argv[])
{
    // Проверяем правильное количество аргументов
    if (argc != 2)
    {
        printf("программа должна принимать два значения.\n");
        return 1;
    }

    char *hash = argv[1];

    char *abc = "qwertyuiopasdfghjklzxcvbnm";
    int length_abc = strlen(abc);
    int length_hash = strlen(hash);
    char id[3];
    id[0] = hash[0];
    id[1] = hash[1];
    id[2] = '\0';

    char jjj[9];
    jjj[0] = '\0';
    jjj[1] = '\0';
    jjj[2] = '\0';
    jjj[3] = '\0';
    jjj[4] = '\0';
    jjj[5] = '\0';
    jjj[6] = '\0';
    jjj[7] = '\0';
    jjj[8] = '\0';
    brute_force(abc, id, 1, length_abc,jjj,hash);

}

char brute_force(char *abc, char *id, int index, int length_abc, char *password, char *hash)
{

    if(index>8)
    {
        return 1;
    }
    for(int i = 0; i < length_abc; i ++)
    {
        password[index] = '\0';
        password[index-1] = abc[i];
        // printf("%s......",password);
        // printf("%s\n",crypt(password, id));
        if(search_hash(hash, crypt(password, id))==1)
            {
            printf("%s\n",password);
            exit(1);
            }
        if (index == 1)
            printf("%s\n",password);
        brute_force(abc, id, index+1, length_abc, password,hash);
    }
    return 0;
}

int search_hash(char *hash, char *hashing)
{
    for ( int i = 0; i<strlen(hash); i++)
    {
        if(hash[i] != hashing[i])
            return -1;
    }
    return 1;

}
// ./crack HALRCq0IBXEPM
// ./crack 50zPJlUFIYY0o
// ./crack 50MxVjGD7EfY6
// ./crack 50z2Htq2DN2qs
// ./crack 50CMVwEqJXRUY
// ./crack 50TGdEyijNDNY
// ./crack 50QykIulIPuKI
// ./crack 50q.zrL5e0Sak
// ./crack 50Bpa7n/23iug
// ./crack HAYRs6vZAb4wo
