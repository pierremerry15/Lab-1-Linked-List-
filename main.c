// main.c
#include <stdio.h>
#include "list.h"

int main() {
    list_t* l = list_alloc();
    list_add_at_index(l, 0, 3);
    list_add_at_index(l, 1, 5);
    list_add_at_index(l, 2, 7);
    list_add_at_index(l, 1, 12);
    list_print(l);

    printf("Index of 7: %d\n", list_get_index_of_element(l, 7));
    printf("Value at index 2: %d\n", list_get_element_at_index(l, 2));

    list_remove_at_index(l, 1);
    list_print(l);

    list_remove_at_index(l, 0);
    list_print(l);

    list_free(l);
    return 0;
}
