#include "linkedlist.h"
#include <stdlib.h>
#include <stdbool.h>

struct List* create_list(void) {
    struct List* new_list = malloc(sizeof *new_list);
    new_list->head = new_list->tail = NULL;

    return new_list;
}

void free_list(struct List* list) {
    while (list->head != NULL) {
        struct Node* current = list->head;
        list->head = list->head->next;
        free(current);
    }
    
    free(list);
}

struct List* duplicate_list(const struct List* list) {
    struct List* new_list = create_list();
    struct Node* current = list->head;

    while(current != NULL) {
        append_back(new_list, current->value);
        current = current->next;
    }

    return new_list;
}

void append_back(struct List* list, int value) {
    struct Node* appended_node = malloc(sizeof *appended_node);
    *appended_node = (struct Node){value, NULL};
    
    if(list->tail == NULL) {
        list->head = list->tail = appended_node;
    } else {
        list->tail->next = appended_node;
        list->tail = list->tail->next;
    }
}

void append_front(struct List* list, int value) {
    struct Node* new_head = malloc(sizeof *new_head);
    *new_head = (struct Node){value, list->head};
    
    list->head = new_head;
    if(list->tail == NULL) {
        list->tail = list->head;
    }
    
}

struct Node* pop_front(struct List* list) {
    struct Node* popped_node = malloc(sizeof *popped_node);
    popped_node = list->head;
    list->head = list->head->next;

    return popped_node;
}

//p sure my index math is off
void insert(struct List* list, int value, int index) {
    int counter = 0;
    struct Node* current = list->head;
    struct Node* new_node = malloc(sizeof *new_node);

    while (current != NULL && counter != index) {
        current = current->next;
        counter++;
    }

    if (current != NULL) {
        *new_node = (struct Node){value, current->next};
        current->next = new_node;
    }
}


void remove_node(struct List* list, int index) {
    struct Node* previous;
    struct Node* current;
    previous = current = list->head;
    int counter = 0;

    while (current != NULL && counter != index) {
        previous = current;
        current = current->next;
        counter++;
    }

    if (current != NULL) {
        previous->next = current->next;
        free(current);
    }
}

//todo actually finish this
bool equals(struct List* list, int value) {
    struct Node* current = list->head;

    while (current->value != value && current != NULL) {
        current = current->next;
    }

    if (current != NULL) {
        return true;
    } else {
        return false;
    }
}

bool contains(const struct List* list, int value) {
    struct Node* current = list->head;
    while (current != NULL) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    
    return false;
}
