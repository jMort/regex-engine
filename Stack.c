#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "StackItem.h"
#include "Stack.h"

typedef struct _node {
    StackItem value;
    struct _node *next;
} *Node;

struct _stack {
    Node top;
    int size;
};

Stack newStack() {
    Stack s = malloc(sizeof(struct _stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

void StackPush(Stack s, StackItem i) {
    assert(s != NULL);
    Node n = malloc(sizeof(struct _node));
    n->value = i;
    n->next = NULL;
    if (s->top != NULL)
        n->next = s->top;
    s->top = n;
    s->size++;
}

StackItem StackPop(Stack s) {
    assert(s != NULL && s->top != NULL);
    Node temp = s->top;
    s->top = s->top->next;
    s->size--;
    StackItem i = temp->value;
    free(temp);
    return i;
}

int StackSize(Stack s) {
    assert(s != NULL);
    return s->size;
}

void dropStack(Stack s) {
    assert(s != NULL);
    while (StackSize(s) > 0) {
        StackPop(s);
    }
    free(s);
}
