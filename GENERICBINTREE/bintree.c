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

