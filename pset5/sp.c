#include <stdio.h>

int main(void)
{
   char buffer[200];
   int i =0, j=0;
   double fp=0.0;
   char *s = "computer";
   char c = '\0';

   /*  форматирует и печатает различные данные */

   sprintf(buffer, "%s\n", s);
   printf("%d\n", j);
   printf("%s\n", s);
   printf("%s\n", buffer);
   j = sprintf(buffer, "%d\n", i);
   printf("%d\n", j);
   printf("%i\n", i);
   j = sprintf(buffer, "%f\n", fp);
   printf("%d\n", j);
   printf("%f\n", fp);
   j = sprintf(buffer, "%c\n", c);
   printf("%d\n", j);
   printf("%c\n", c);
}