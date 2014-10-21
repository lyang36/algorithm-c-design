/****************************************
 * This file contains the struct of a 
 * integer queue. Implemented using
 * linked list;
 * Author: Lin Yang
 * Date: Oct/21/2014
 * **************************************/
#include "link_list.h"

typedef struct queue{
    linklist* first;
    linklist* last;
} queue;

void enqueue(queue* q, int* array, int n);

/* Return the result in res, 
 * if the queue is empty
 * return 0, else return 1*/
int dequeue(queue* q, int* res);

void delete_queue(queue* q);

