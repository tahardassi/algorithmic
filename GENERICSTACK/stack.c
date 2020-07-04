/*!\file stack.c
 *\stack coded according to the concept of genericity in C
 *\author Tahar ISSAD issad.tahar@icloud.com
 *\date November 8, 2019 
 */
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "stack.h"

#define CAPACITE 255

/*tableau de pointeur void*/
static void ** Pile= NULL;
/*variables globales statiques*/
static int Haut = -1, Taille = 0;

static void quitPile(void)
{
	if(Pile)
	{
		for(int i = 0; i < Haut; ++i)
			free(Pile[i]);
		free(Pile);
		Pile = NULL;
	}
	Haut = -1;
	Taille = 0;
}

extern void push(void * data, size_t size)
{
	char * dest = (char *)malloc((size_t) size);
	memcpy(dest, (char*)data, size);
	if(!Taille)
	{
		Pile = malloc((Taille = CAPACITE) * sizeof(**Pile));
		assert(Pile);
		atexit(quitPile);
	}
	else if(Haut == Taille - 1)
	{
		void **tmp = realloc(Pile, (Taille *= 2) *sizeof (**tmp));
		if(!tmp)
		{
			quitPile();
			assert(Pile);
			exit(1);
		}
		Pile = tmp;
	}
	Pile[++Haut] = dest;
}


extern void * pop(void)
{
	void *data = Pile[Haut];
	free(Pile[Haut]);
	Pile[Haut] = NULL;
	Haut--;
	return data;
}

extern int emptyPile(void)
{
	return (Haut < 0);
}
