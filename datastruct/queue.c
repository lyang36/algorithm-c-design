#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void enqueue(queue* q, int* array, int n){
    int pa = 0;
    if(n == 0){
        return;
    }

    if(q->first == NULL){
        insert_first(&(q->first), array[pa]);
        pa ++;
        q->last = q->first;
    }
    while(pa < n){
        insert_last(&(q->last), array[pa]);        
        pa ++;
    }
}


int dequeue(queue* q, int* res){
    if(q->first != NULL){
        *res = (q->first)->x;
        linklist* a = q->first;
        q->first = (q->first)->next;
        free(a);
        if(NULL == q->first){
            q->last = NULL;
        }
        return 1;
    }
   
    return 0;
    
}

void delete_queue(queue* q){
    delete_list(q->first);
    free(q);
}
