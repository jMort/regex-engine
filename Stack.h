//#ifndef STACK_H
//#define STACK_H

#include "StackItem.h"

typedef struct _stack *Stack;

Stack newStack();

void StackPush(Stack s, StackItem i);

StackItem StackPop(Stack s);

int StackSize(Stack s);

void dropStack(Stack s);

//#endif
