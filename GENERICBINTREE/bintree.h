/*!\file bintree.c
 *\binary search tree coded according to the concept of genericity in C
 *\author Tahar ISSAD issad.tahar@icloud.com
 *\date November 8, 2019 
 */
#include <stdlib.h>
typedef struct node_t node_t;
struct node_t{
	void * data;
	struct node_t * lc, * rc;
};

extern void bt_add_value(node_t ** bt, void * data, size_t s, int (* compar)(const void *, const void *));
extern void bt_print(node_t * bt, void(*print)(const void *));
extern void bt_free(node_t ** bt);
