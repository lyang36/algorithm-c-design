/************************************
 * Defines the Heap structure to sort
 * The dominate element is defined to
 * be smaller than the children.
 * Author: Lin Yang
 * Date: Oct 21, 2014
 * **********************************/

#ifndef __LY__HEAP__
#define __LY__HEAP__

/* The integer heap */
typedef struct heapi{
    int* p_array;
    int n;
} heapi;

/* Build heap*/
heapi* make_heapi(int* array, int n);

/* Delete the heap*/
void del_heapi(heapi* hp);

/* Bubble down an element at n*/
void bubble_down(heapi* hp, int n);

/* Pop up the min element */
void pop_min(heapi* hp);
#endif
