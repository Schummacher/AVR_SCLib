/*
 * List.c
 *
 * Created: 2017/7/28 下午 1:19:27
 *  Author: schummacher
 */ 

#include "List.h"

void List_Insert(ElementType data, list *L)
{
	list *tmp_cell = malloc(sizeof(list));
	tmp_cell->num = data;
	tmp_cell->next = L->next;
	L->next = tmp_cell;
}

_Bool List_if_Empty(list *L)
{
	return L->next == NULL;
}

list *List_Find(ElementType data, list *L)
{
	list *P;
	P = L->next;
	while(P->num != data)
		P = P->next;
	return P;
}

void
List_Delete(ElementType data, list *L)
{
	list *P, *TmpCell;

	P = List_Find(data, L);
	TmpCell = P->next;
	P->next = TmpCell->next;  /* Bypass deleted cell */
	free( TmpCell );
}