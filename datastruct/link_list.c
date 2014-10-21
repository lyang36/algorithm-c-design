/*****************************************
 * Author: Lin Yang
 * Study the practical algorithm designs
 * This file contains the datastructure of 
 * linked list.
*/

#include <limits.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "link_list.h"


void swap_int(int* a, int* b){
    int v = *a;
    *a = *b;
    *b = v;
}

/* Insert to the first for item a
 * l: the pointer to the pointer of the first item
 */
void insert_first(linklist** l, int a){
    linklist* p = (linklist *) malloc(sizeof(linklist));
    if( NULL == p){
        fprintf(stderr, "Memory Error!\n"); 
        exit(1);
    }
    p->x = a;
    p->next = *l;
    *l = p;
}


/* Insert item a to the last of the list
 * l: the pointer to the pointer of the first item
 */
void insert_last(linklist** l, int a){
    linklist *p;
    p = *l;
    
    if(p == NULL){
        *l = (struct linklist* ) malloc(sizeof(linklist));
        if( NULL == *l){
            fprintf(stderr, "Memory Error!\n");
            exit(1);
        }
        (*l)->next = NULL;
        (*l)->x = a;
        return;
    }

    while(p->next != NULL){
        p=p->next;
    }
    p->next = (struct linklist* ) malloc(sizeof(linklist));
    
    if( NULL == p->next){
        fprintf(stderr, "Memory Error!\n");
        exit(1);
    }
    p->next->next = NULL;
    p->next->x = a;
}


/**
 * Test whether item a is inside the list.
 * If in, return the first occured pointer;
 * if not, return NULL;
 */
linklist* find_item(linklist* l, int a){
    if(l == NULL){
        return NULL;
    }
    do{
        if(l->x == a){
            return l;
        }
        l = l->next;
    }while(l != NULL);
    
    return NULL;
}

/**
 * Delete first appear item from the list.
 *
 */
void delete_item(struct linklist** l, int a){
    struct linklist* p = *l;
    if(l == NULL || (*l) == NULL){
        return;
    }
   
    if(p->x == a){
        *l = p->next;
        free(p);
        return;
    }
    do{
       if(p->next != NULL && p->next->x == a){
            linklist* p1 = p->next->next;
            free(p->next);
            p->next = p1;
            return;
       }
       p = p->next;
    }while(p->next != NULL);
}

/**
 * Delete the whole list.
 */
void delete_list(linklist* l){
   while(l != NULL){
        struct linklist* p = l->next;
        free(l);
        l = p;
   }
}

