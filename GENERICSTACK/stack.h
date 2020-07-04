/*!\file stack.h
 *\stack coded according to the concept of genericity in C
 *\author Tahar ISSAD issad.tahar@icloud.com
 *\date November 8, 2019 
 */

#include <stdlib.h>

extern void push(void *data, size_t s);
extern void *pop(void);
extern int emptyPile(void);
