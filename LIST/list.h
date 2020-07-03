/*!\list.h
 *\author Tahar ISSAD issad.tahar@icloud.com
 *\date October 28, 2019
 * */


typedef struct node_t node_t;
struct node_t{
	int value;
	struct node_t * next;
};

extern node_t ** ll_addnew(int v, node_t ** pll);
extern void ll_print(node_t *ll);
extern void ll_free(node_t ** pll);
