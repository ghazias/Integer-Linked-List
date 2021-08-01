#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdbool.h>

struct Node {
    int value;
    struct Node* next;
};

struct List {
    struct Node* head;
    struct Node* tail;
};

struct List* create_list(void);

void free_list(struct List* list);

struct List* duplicate_list(const struct List* list);

void append_front(struct List* list, int value);

void append_back(struct List* list, int value);

struct Node* pop_front(struct List* list);

struct Node* pop_back(struct List* list); // only if double linked list

void insert(struct List* list, int value, int index);

void remove_node(struct List* list, int index);

bool equals(struct List* list, int value);

bool contains(const struct List* list, int value);

// map/filter/reduce

#endif
