#ifndef STATE_H
#define STATE_H

typedef struct _state *State;
typedef struct _list *List;

State newState();

State createStateChain(char *pattern);

int isStart(State s);

char getValue(State s);

int isSpecial(State s);

List getConnected(State s);

void dropState(State s);

#endif
