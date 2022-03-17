#include <stdio.h>

#define TAB 8 		// число пробелов в табуляции

void space(char from[], char to[]);
/* перевод табов в пробелы */
int main()
{
	
	int len, c, k; 
	char line[1000], line_space[1000];
	for (k = 0; k < 1000; ++k)
		line[k] = 0;
	k = 0;
	while ((c = getchar()) != EOF)
	{
		line[k] = c;
		++k;
	}
	space(line,line_space);
	printf("%s\n", line_space);
	return 0;
}

void space(char from[], char to[])
{
	int i, j;
	i = j = 0;
	while (from[i] != 0)
	{
		to[j] = from[i];
		if (from[i] == '\t')
		{
			int x;
			x = (i) % TAB;
			for (int n = 0; n < TAB - x; ++n)
			{
				to[j] = '*';
				++j;
			}
		}
		++j;
		++i;
	}
}