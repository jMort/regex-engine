//#ifndef LIST_H
//#define LIST_H

#include "Item.h"

typedef struct _list *List;

List newList();

void ListAppend(List l, Item n);

Item ListGet(List l, int index);

int ListSize(List l);

void dropList(List l);

//#endif
