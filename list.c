#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list_t* list_alloc() {
    list_t* l = (list_t*)malloc(sizeof(list_t));
    l->head = NULL;
    return l;
}

void list_free(list_t* l) {
    node_t* curr = l->head;
    while (curr) {
        node_t* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    free(l);
}

void list_print(list_t* l) {
    node_t* curr = l->head;
    while (curr) {
        printf("%d - ", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Add node at index
void list_add_at_index(list_t* l, int index, int value) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->value = value;
    new_node->next = NULL;
    if (index == 0) {
        new_node->next = l->head;
        l->head = new_node;
        return;
    }
    node_t* curr = l->head;
    int i;
    for (i = 0; curr && i < index - 1; i++)
        curr = curr->next;
    if (!curr) {
        free(new_node);
        return;
    }
    new_node->next = curr->next;
    curr->next = new_node;
}

// Remove node at index
int list_remove_at_index(list_t* l, int index) {
    if (!l || !l->head) return -1;
    node_t* curr = l->head;
    if (index == 0) {
        l->head = curr->next;
        free(curr);
        return 0;
    }
    int i;
    for (i = 0; curr && i < index - 1; i++)
        curr = curr->next;
    if (!curr || !curr->next)
        return -1;
    node_t* tmp = curr->next;
    curr->next = tmp->next;
    free(tmp);
    return 0;
}

// Get element at index
int list_get_element_at_index(list_t* l, int index) {
    node_t* curr = l->head;
    int i;
    for (i = 0; curr && i < index; i++)
        curr = curr->next;
    if (!curr)
        return -1;
    return curr->value;
}

// Get index of value
int list_get_index_of_element(list_t* l, int value) {
    node_t* curr = l->head;
    int idx = 0;
    while (curr) {
        if (curr->value == value)
            return idx;
        curr = curr->next;
        idx++;
    }
    return -1;
}
