//
// Created by schummacher on 2017/9/22.
//

#include "static.h"


_Bool Stack_Is_Full(stack *sp)
{
    return sp->locate == sp->length;
}

_Bool Stack_Is_Empty(stack *sp)
{
    return sp->locate == 0;
}

void Push(stack *sp, uint8_t data)
{
    if(Stack_Is_Full(sp))
        printf("STACK IS FULL\n");
    else
    {
        *(sp->data + sp->locate) = data;
        sp->locate++;
    }
}

uint8_t Pop(stack *sp)
{
    if(Stack_Is_Empty(sp))
        printf("STACK IS EMPTY");
    else
        sp->locate--;
    return *(sp->data + sp->locate);
}

void Stack_Empty(stack *sp)
{
    sp->locate = 0;
}
