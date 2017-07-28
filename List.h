/*
 * List.h
 *
 * Created: 2017/7/28 下午 1:19:41
 *  Author: schummacher
 */ 


#ifndef LIST_H_
#define LIST_H_

#include <stdint-gcc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _list list;
typedef uint8_t ElementType;

struct _list
{
	ElementType num;
	struct _list *next;
};


void List_Insert(ElementType data, list *L);	
_Bool List_if_Empty(list *L);
list *List_Find(ElementType data, list *L);
void List_Delete(ElementType data, list *L);


#endif /* LIST_H_ */