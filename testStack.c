#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack.h"
#include "StackItem.h"
#include "State.h"

void runTests();

int main(int argc, char *argv[]) {
    printf("Testing Stack.c\n");
    runTests();
    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}

void runTests() {
    Stack s = newStack();
    State n = newState();
    StackItem i = {n, 1};
    StackPush(s, i);
    printf("Testing pushing to a stack ... ");
    assert(StackSize(s) == 1);
    StackItem j = {n, 5};
    StackPush(s, j);
    assert(StackSize(s) == 2);
    printf("passed\n");

    StackItem k = StackPop(s);
    printf("Testing popping from a stack ... ");
    assert(StackSize(s) == 1);
    assert(k.charIndex == 5);
    k = StackPop(s);
    assert(StackSize(s) == 0);
    assert(k.charIndex == 1);
    printf("passed\n");

    dropStack(s);
}
