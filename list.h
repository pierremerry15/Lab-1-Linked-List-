#ifndef LIST_H
#define LIST_H

typedef struct node {
    int value;
    struct node* next;
} node_t;

typedef struct {
    node_t* head;
} list_t;

list_t* list_alloc();
void list_free(list_t* l);
void list_print(list_t* l);
void list_add_at_index(list_t* l, int index, int value);
int list_remove_at_index(list_t* l, int index);
int list_get_element_at_index(list_t* l, int index);
int list_get_index_of_element(list_t* l, int value);

#endif
