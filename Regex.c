/*  Regex.c
    Description: Implementation of Regex.h
    Author:      Joshua Morton
    Date:        11/11/14
*/

#include <stdio.h>
#include <stdlib.h>
#include "Regex.h"
#include "List.h"
#include "State.h"
#include "Stack.h"
#include "StackItem.h"

/* Returns 1 if string matches the pattern and 0 otherwise */
int match(char *pattern, char *string) {
    State sc = createStateChain(pattern);
    int i, j, foundMatch = 0;
    for (i = 0; string[i] != '\0'; i++) {
        Stack st = newStack();
        StackItem it = {sc, i};
        StackPush(st, it);
        while (StackSize(st) > 0) {
            it = StackPop(st);
            State state = it.state;
            char curr = string[it.charIndex];
            if (isStart(state)) {
                for (j = 0; j < ListSize(getConnected(state)); j++) {
                    StackItem adj = {ListGet(getConnected(state), j), it.charIndex};
                    StackPush(st, adj);
                }
            } else if (curr == getValue(state) ||
                    (getValue(state) == '.' && isSpecial(state))) {
                if (ListSize(getConnected(state)) == 0) {
                    foundMatch = 1;
                    break;
                }
                for (j = 0; j < ListSize(getConnected(state)); j++) {
                    StackItem adj = {ListGet(getConnected(state), j), it.charIndex+1};
                    StackPush(st, adj);
                }
            }
        }
        if (foundMatch)
            break;
    }
    dropState(sc);
    return foundMatch;
}

/* Returns the first match in string or a NULL pointer if no match */
char *search(char *pattern, char *string) {
    // TODO: Implement this
    return NULL;
}

/* Returns an array of all matches in string and stores the number of matches in n */
char **findall(char *pattern, char *string, int *n) {
    // TODO: Implement this
    *n = 0;
    return NULL;
}
