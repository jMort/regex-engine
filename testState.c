#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "StackItem.h"
#include "Stack.h"
#include "Item.h"
#include "List.h"
#include "State.h"

void runTests();

int main(int argc, char *argv[]) {
    printf("Testing State.c\n");
    runTests();
    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}

void runTests() {
    printf("Testing a basic pattern ... ");
    State sc = createStateChain("abc");
    State curr = sc;
    assert(isStart(curr) == 1);
    assert(ListSize(getConnected(curr)) == 1);

    curr = ListGet(getConnected(curr), 0);
    assert(isStart(curr) == 0);
    assert(getValue(curr) == 'a');
    assert(ListSize(getConnected(curr)) == 1);

    curr = ListGet(getConnected(ListGet(getConnected(curr), 0)), 0);
    assert(getValue(curr) == 'c');
    assert(ListSize(getConnected(curr)) == 0);
    printf("passed\n");

    dropState(sc);
}
