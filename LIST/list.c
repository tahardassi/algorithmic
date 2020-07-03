/*!\file list.c
 *
 * \linked list to store a list of integers
 * \author Tahar issad issad.tahar@icloud.com
 * \date october 28, 2019
 * */



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"
/**/
extern node_t ** ll_addnew(int v, node_t ** pll)
{
	node_t *new = malloc(sizeof(*new));
	assert(new);
	new->value = v;
	new->next = *pll;
	*pll = new;
	return &(new->next);
}
/**/
extern void ll_print(node_t *ll)
{
	while(ll)
	{
		printf("%d ", ll->value);
		ll = ll->next;
	}
	printf("\n");
}
/**/
extern void ll_free(node_t ** pll)
{
	node_t *ll = *pll, *tmp;
	while(ll)
	{
		tmp = ll->next;
		free(ll);
		ll = tmp;
	}
	*pll = NULL;
}

/**/

#ifdef TEST

int main()
{
	node_t *q = NULL, **fin = &q;
	fin = ll_addnew(1, fin);
	/*printf("%p\n", *fin);*/
	fin = ll_addnew(2, fin);
	/*printf("%p\n", *fin);*/
	fin = ll_addnew(3, &q);
	/*printf("%p\n", *fin);*/
	ll_print(q);
	ll_free(&q);
	ll_print(q);
	return 0;
}

#endif
