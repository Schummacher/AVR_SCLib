//
// Created by schummacher on 2017/9/22.
//

#ifndef STATIC_STATIC_H
#define STATIC_STATIC_H

#include <stdint-gcc.h>
#include <stdio.h>

typedef struct
{
    uint8_t length;
    uint8_t locate;
    uint8_t *data;
} stack;

_Bool Stack_Is_Full(stack *sp);
_Bool Stack_Is_Empty(stack *sp);

void Stack_Empty(stack *sp);
void Push(stack *sp, uint8_t data);
uint8_t Pop(stack *sp);

#endif //STATIC_STATIC_H
