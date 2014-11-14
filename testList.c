#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"
#include "Item.h"
#include "State.h"

void runTests();

int main(int argc, char *argv[]) {
    printf("Testing List.c\n");
    runTests();
    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}

void runTests() {
    List l = newList();
    printf("Testing size of an empty list ... ");
    assert(l != NULL && ListSize(l) == 0);
    printf("passed\n");

    State n = newState();
    ListAppend(l, n);
    printf("Testing appending to a list ... ");
    assert(ListSize(l) == 1);
    ListAppend(l, n);
    assert(ListSize(l) == 2);
    printf("passed\n");

    dropList(l);
}
