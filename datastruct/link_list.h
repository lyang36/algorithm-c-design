#ifndef __LY__LINKLIST__
#define __LY__LINKLIST__

void swap_int(int* a, int* b);

typedef struct linklist{
    int x;
    struct linklist* next;
} linklist;


/* Insert to the first for item a
 * l: the pointer to the pointer of the first item
 */
void insert_first(linklist** l, int a);

/* Insert item a to the last of the list
 * l: the pointer to the pointer of the first item
 */
void insert_last(linklist** l, int a);

/**
 * Test whether item a is inside the list.
 * If in, return the first occured pointer;
 * if not, return NULL;
 */
linklist* find_item(linklist* l, int a);

/**
 * Delete first appear item from the list.
 *
 */
void delete_item(struct linklist** l, int a);

/**
 * Delete the whole list.
 */
void delete_list(linklist* l);

#endif
