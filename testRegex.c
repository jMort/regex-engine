#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Regex.h"

void runTests();

int main(int argc, char *argv[]) {
    // Don't buffer stdout so that printf's get displayed right away
    setbuf(stdout, NULL);

    printf("Testing Regex.c\n");
    runTests();
    printf("All tests passed!\n");
    return EXIT_SUCCESS;
}

void runTests() {
    printf("Testing match('abc', 'helloabc') ... ");
    assert(match("abc", "helloabc") == 1);
    printf("passed\n");

    printf("Testing match('abc', 'blahabchello') ... ");
    assert(match("abc", "blahabchello") == 1);
    printf("passed\n");

    printf("Testing match('a.c', 'adc') ... ");
    assert(match("a.c", "adc") == 1);
    printf("passed\n");

    printf("Testing no match('a.c', 'cab') ... ");
    assert(match("a.c", "cab") == 0);
    printf("passed\n");
}
