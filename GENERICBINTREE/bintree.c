/*!\file bintree.c
 *\binary search tree coded according to the concept of genericity in C
 *\author Tahar ISSAD issad.tahar@icloud.com
 *\date November 8, 2019 
 */
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "bintree.h"

extern void bt_add_value(node_t ** bt, void * data, size_t s, int (* compar)(const void *, const void *))
{
	char *d = malloc(1* s * sizeof * d);
	assert(d);
	memcpy(d, (char*)data, s);
	while(*bt)
	{
		if(compar(d, (*bt)->data) < 0)
			bt = &((*bt)->lc);
		else
			bt = &((*bt)->rc);
	}
	*bt = malloc(1 * sizeof ** bt);
	assert(*bt);
	(*bt)->data = d;
	(*bt)->lc = NULL;
	(*bt)->rc = NULL;
}

extern void bt_print(node_t * bt, void(*print)(const void *))
{
	if(!bt)
		return;
	bt_print(bt->lc, print);
		print(bt->data);
	bt_print(bt->rc, print);
}

extern void bt_free(node_t ** bt)
{
	node_t * mbt = *bt;
	if(mbt->lc)
		bt_free(&(mbt->lc));
	if(mbt->rc)
		bt_free(&(mbt->rc));
	free(mbt->data);
	free(mbt);
	*bt = NULL;
}

#ifdef TEST
struct fiche
{
	char nom[20];
	char prenom[20];
	int age;
};
typedef struct fiche fiche;

static int compar_age(void const *a, void const *b)
{
	fiche const *pa = a;
	fiche const *pb = b;
	return(pa->age - pb->age);
}

static int compar_prenom(void const * a, void const *b)
{
	fiche const *pa = a;
	fiche const *pb = b;
	return(strcmp(pa->prenom, pb->prenom));
}

static void  print(void const * n)
{
	fiche const * p = n;
	printf("%s %s %d\n", p->nom, p->prenom, p->age);
}

int main(void)
{
	fiche tab[] =
	{
		{"Simpson", "Homer", 36},
		{"Bouvier", "Marge", 34},
		{"Simpson", "Bart", 10},
		{"Simpson", "Lisa", 8},
		{"Simpson", "Maggie", 2},
	};


	node_t * bt = NULL;
	int i;

	for(i = 0; i < (sizeof tab / sizeof *tab); i++)
	{
		bt_add_value(&bt, &tab[i], sizeof tab[i], compar_age);
	}

	printf("affichage de BST comme un tas trié selon l'age\n");
	bt_print(bt, print);

	bt_free(&bt);

	for(i = 0; i < (sizeof tab / sizeof *tab); i++)
	{
		bt_add_value(&bt, &tab[i], sizeof tab[i], compar_prenom);
	}

	printf("affichage de BST commme un tas trié selon prenom\n");
	bt_print(bt, print);

	bt_free(&bt);

	return 0;
}
#endif
