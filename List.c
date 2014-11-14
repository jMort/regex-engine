#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Item.h"
#include "List.h"

typedef struct _node {
    Item value;
    struct _node *next;
} *Node;

struct _list {
    Node first;
    int size;
};

List newList() {
    List l = malloc(sizeof(struct _list));
    l->first = NULL;
    l->size = 0;
    return l;
}

void ListAppend(List l, Item n) {
    assert(l != NULL);
    Node new = malloc(sizeof(struct _node));
    new->value = n;
    new->next = NULL;
    if (l->first == NULL) {
        l->first = new;
    } else {
        Node temp = l->first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }
    l->size++;
}

Item ListGet(List l, int index) {
    assert(l != NULL && index < l->size);
    Node n = l->first;
    int i;
    for (i = 0; i < index; i++) { 
        if (n == NULL)
            return NULL;
        n = n->next;
    }
    return n->value;
}

int ListSize(List l) {
    assert(l != NULL);
    return l->size;
}

void dropList(List l) {
    assert(l != NULL);
    Node curr = l->first;
    Node temp;
    while (curr != NULL) {
        temp = curr->next;
        freeItem(curr->value);
        free(curr);
        curr = temp;
    }
    free(l);
}
