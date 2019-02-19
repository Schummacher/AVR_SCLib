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

struct _list_i
{
    int dat;
    struct _list_i *next;
    struct _list_i *front;
};

typedef struct _list_i list_i;

struct _list
{
    list_i *first;
    list_i *last;
    int length;
};

typedef struct _list list;

void push(int dat, list *L);
int pop(list *L);
void creat(int dat, list *L);
void append(int dat, list *L);
int out(list *L);
void clear(list *L);
void insert(int dat, int times, list *L, int count);

#endif /* LIST_H_ */
