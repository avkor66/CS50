#include <stdio.h>

int main(void)
{
   int n = 50;
   int *p = &n;
   printf("%p\n", &n);
   printf("%i\n", n);
   printf("%p\n", p);
   printf("%p\n", &p);
   printf("%i\n", *p);

   char *s = "swappertyuireerty";
   printf("%s\n", s);
   printf("%p\n", &s);
   printf("%p\n", &s[0]);
   printf("%p\n", &s[1]);
   printf("%p\n", &s[2]);
   printf("%p\n", &s[3]);
   printf("%p\n", &s[4]);
   printf("%p\n", &s[5]);
   printf("%p\n", &s[6]);
   printf("%p\n", &s[7]);
   printf("%p\n", &s[8]);
   printf("%p\n", &s[9]);
   printf("%p\n", &s[10]);
   printf("%p\n", &s[11]);
   printf("%p\n", &s[12]);
   printf("%p\n", &s[13]);
   printf("%p\n", &s[14]);
   printf("%p\n", &s[15]);
   printf("%p\n", &s[16]);
   printf("%p\n", &s[17]);

   char **d = &s;
   printf("%p\n", d);
   printf("%p\n", &d);
   printf("%s\n", *d);
}