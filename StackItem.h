#ifndef STACKITEM_H
#define STACKITEM_H

#include "State.h"

typedef struct _stackItem {
    State state;
    int charIndex;
} StackItem;

#endif
