#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define N 7

struct computer { char *type; char *proc; int qty; };
void viewer (struct computer *);
void changer (struct computer *);
void create (struct computer *);

int main ()
{
	struct computer comps[N]=
    {
	{"Desktop", "earlier then P4", 10},
	{"Desktop", "P4", 30},
	{"Desktop", "Core", 20},
	{"Desktop", "AMD", 2},
	{"Notebook", "Core", 1}
	};

	viewer(comps);
	changer(comps);
	viewer(comps);
	create(comps);
	viewer(comps);
}

void viewer (struct computer *comp)
{
	int i;

	for (i=0; i < N; i++, comp++)
	{
		printf("%2d) %-8s - %-15s: %3d\n", i+1, comp->type, comp->proc, comp->qty);
	}
}

void changer (struct computer *comp)
{
	int i, differ;

	printf("Введите номер модели: ");
	scanf("%d", &i); i--;
	printf("На сколько уменьшить или увеличить: ");
	scanf("%d", &differ);
	(comp+i)->qty += differ;
}

void create (struct computer *comp)
{
	int i, differ;
	char *newproc=NULL, *newcomp=NULL;

	printf("Введите номер модели: ");
	scanf("%d", &i);
	printf("На сколько уменьшить или увеличить: ");
	scanf("%d", &differ);
	(comp+i)->qty += differ;
	printf("\nВведите название компа: ");
	fgets(newcomp, N, stdin);
	printf("\nВведите название проца: ");
	fgets(newproc, N, stdin);
	printf("%s-%s\n", newcomp, newproc);


}