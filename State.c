#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "State.h"
#include "List.h"

struct _state {
    char value;
    int special;
    List connected;
    int terminal; // 1 if start state, 2 if end state and 0 otherwise
};

static int numStatesAlloced = 0;
static State statesAlloced[1000] = {0};

State newState() {
    State n = malloc(sizeof(struct _state));
    n->value = n->special = n->terminal = 0;
    n->connected = newList();
    statesAlloced[numStatesAlloced++] = n;
    return n;
}

State createStateChain(char *pattern) {
    State sc = newState();
    sc->terminal = 1;
    State curr = sc;
    int i, j;
    for (i = 0; pattern[i] != '\0'; i++) {
        if (pattern[i] != '[' && pattern[i] != ']') {
            State n = newState();
            n->value = pattern[i];
            if (pattern[i] == '.')
                n->special = 1;
            if (pattern[i+1] == '*') {
                ListAppend(n->connected, n);
            }
            ListAppend(curr->connected, n);
            curr = n;
        } else if (pattern[i] == '[') {
            for (j = i+1; pattern[j] != ']'; j++) {
                State n = newState();
                n->value = pattern[j];
                if (pattern[j] == '.')
                    n->special = 1;
                ListAppend(curr->connected, n);
            }
            i = j;
            if (pattern[i+1] != '\0') {
                State after = createStateChain(&(pattern[i+1]));
                for (j = 0; j < ListSize(curr->connected); j++) {
                    State temp = ListGet(curr->connected, j);
                    ListAppend(temp->connected, after);
                }
                break;
            }
        }
    }
    return sc;
}

int isStart(State s) {
    return s->terminal == 1;
}

char getValue(State s) {
    return s->value;
}

int isSpecial(State s) {
    return s->special;
}

List getConnected(State s) {
    return s->connected;
}

void dropState(State s) {
/*    if (s != NULL) {
        dropList(s->connected);
        free(s);
    }*/
    int i;
    for (i = 0; i < numStatesAlloced; i++) {
        free(statesAlloced[i]);
        statesAlloced[i] = 0;
    }
    numStatesAlloced = 0;
}
