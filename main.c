#include "linkedlist.h"
#include <stdio.h>
#include <assert.h>

static void append_back_test(void) {
    struct List* list = create_list();
    assert(list != NULL);
    append_back(list, 5);
    append_back(list, 20);
    append_back(list, 3);
    append_back(list, 12);
    
    struct Node* current = list->head;
    assert(current->value == 5);
    current = current->next;
    assert(current->value == 20);
    current = current->next;    
    assert(current->value == 3);
    current = current->next;
    assert(current->value == 12);
    assert(current == list->tail);
    current = current->next;
    assert(current == NULL);
    
    free_list(list);
}

static void append_front_test(void) {
    struct List* list = create_list();
    append_front(list, 28);
    append_front(list, 99);
    append_front(list, 268);
    
    struct Node* current = list->head;
    assert(current->value == 268);
    current = current->next;
    assert(current->value == 99);
    current = current->next;
    assert(current->value == 28);
    assert(current == list->tail);
    current = current->next;
    assert(current == NULL);
    
    free_list(list);
}

static void duplicate_test(void) {
    struct List* list = create_list();
    append_front(list, 28);
    append_front(list, 99);
    append_front(list, 268);

    struct List* dup_list = duplicate_list(list);
    struct Node* current = dup_list->head;
    assert(current->value == 268);
    current = current->next;
    assert(current->value == 99);
    current = current->next;
    assert(current->value == 28);
    assert(current == dup_list->tail);
    current = current->next;
    assert(current == NULL);

    free_list(dup_list);
    free_list(list);
}

static void duplicate_emptylist_test(void) {
    struct List* list = create_list();
    struct List* dup_list = duplicate_list(list);
    append_front(dup_list, 12);
    struct Node* current = dup_list->head;
    assert(current->value == 12);

    free_list(dup_list);
    free_list(list);
}

int main(void) {
    append_back_test();
    append_front_test();
    duplicate_test();
    duplicate_emptylist_test();
}
