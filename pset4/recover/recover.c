#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        //Если количество аргументов не равно двум, выводим сообщением об этом с примером верного ввода аргументов
        printf("Enter two arguments: 'recover.c [name file]'");
        //Возвращаем ошибку
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if(!file)
    {
        //Если не открылся, выводим на печать ошибку
        printf("File not open file\n");
        //Возвращаем ошибку
        return 2;
    }

    fseek(file, 0, SEEK_END);
    int lSize = ftell(file);
    rewind (file);

    // выделить память для хранения содержимого файла
    unsigned char * buffer = (unsigned char*) malloc(sizeof(unsigned char) * lSize);
    if (buffer == NULL)
    {
        fputs("Ошибка памяти", stderr);
        return 3;
    }
    int count = 0;
    char * filename = ( char*) malloc(sizeof( char) * lSize);
    sprintf(filename, "%03i.jpg", count);
    FILE* img= fopen(filename, "w");
    while (fread(buffer, 512, 1, file) != 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            fclose(img);
            count++;
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
        }

        fwrite(buffer, 512, 1, img);


    }
    printf("count = %i", count);
    fclose(file);
    free(buffer);
}
