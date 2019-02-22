/*
 * List.c
 *
 * Created: 2017/7/28 下午 1:19:27
 *  Author: schummacher
 */ 

#include "List.h"

void push(int dat, list *L) {
	list_i *pl;
	pl = (list_i*)malloc(sizeof(list_i));
	pl->next = L->first;
	L->first->front = pl;
	pl->front = 0;
	pl->dat = dat;
	L->first = pl;
	L->length++;
}

int pop(list *L) {
	int dat;
	list_i *pl;
	dat = L->first->dat;
	pl = L->first;
	L->first = L->first->next;
	L->first->front = 0;
	L->length--;
	free(pl);
	return dat;
}

void creat(int dat, list *L) {
	list_i *pl;
	pl = (list_i*)malloc(sizeof(list_i));
	pl->dat = dat;
	pl->next = 0;
	pl->front = 0;
	L->first = pl;
	L->last = pl;
	L->length = 1;
}


void append(int dat, list *L) {
	list_i *pl;
	pl = (list_i*)malloc(sizeof(list_i));
	pl->front = L->last;
	pl->next = 0;
	pl->dat = dat;
	L->last = pl;
	L->length++;
}

int out(list *L) {
	int dat;
	list_i *pl;
	dat = L->last->dat;
	pl = L->last;
	L->last = L->last->front;
	L->last->next = 0;
	L->length--;
	free(pl);
	return dat;
}

void clear(list *L) {
	list_i *pl;
	while (L->length > 0) {
		pl = L->first;
		L->first = L->first->next;
		free(pl);
		L->length--;
	}
}

list *combian(list *A, list *B) {
	list *C;
	C = (list*)malloc(sizeof(list));
	A->last->next = B->first;
	B->first->front = A->last;
	C->first = A->first;
	C->last = B->last;
	C->length = A->length + B->length;
	free(A);
	free(B);
	return C;
}

void sweep(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}


int find(int count, list *L, int face) {
	list_i *pl;
	int ans;
	pl = (list_i*)malloc(sizeof(list_i));
	if (count >= L->length) {
		ans = 0;
	}
	else if (face == 0) {
		pl->next = L->first;
		if (count == 0) {
			ans = pl->next->dat;
		}
		else {
			for (int i = 0; i < count; i++) {
				pl->next = pl->next->next;
			}
			ans = pl->next->dat;
		}
	}
	else {
		pl->front = L->last;
		if (count == 0) {
			ans = pl->front->dat;
		}
		else {
			for (int i = 0; i < count; i++) {
				pl->front = pl->front->front;
			}
			ans = pl->front->dat;
		}
	}
	return ans;
}
