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

#define TEST_NUM 100

void swap_int(int* a, int* b){
    int v = *a;
    *a = *b;
    *b = v;
}

/* Insert to the first for item a
 * l: the pointer to the pointer of the first item
 */
void insert_first(linklist** l, int a){
    linklist *p = (linklist *) malloc(sizeof(linklist));
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
        (*l)->next = NULL;
        (*l)->x = a;
        return;
    }

    while(p->next != NULL){
        p=p->next;
    }
    p->next = (struct linklist* ) malloc(sizeof(linklist));
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

/*main*/
int main(){
    linklist* l = NULL;
    linklist* p = NULL;

    //srand(time(NULL));
    
    printf("Insert First: ");
    for(int i = 0; i < TEST_NUM; i++){
        int n = i; //rand() % 100;
        printf(" %d", n);
        insert_first(&l, n);
    }
    printf("\n");
    
    printf("Insert Last: \n");
    for(int i = 0; i < TEST_NUM; i++){
        int n = i;//rand() % 100;
        printf(" %d", n);
        insert_last(&l, n);
    }
    printf("\n");

    printf("Output list: \n");
    
    p = l;
    while(p != NULL){
        printf("%d ", p->x);
        p = p->next;
    }
    printf("\n");

    printf("Test Find/Delete: \n");
    for(int i = 0; i < 100; i+=2){
        int n = i;//rand() % 100;
        if(find_item(l, n)){
            printf("Item %d found.\n", n);
            delete_item(&l, n);
        }

    }

    printf("Final List:\n");
    p = l;
    while(p != NULL){
        printf("%d ", p->x);
        p = p->next;
    }
    printf("\n");
    delete_list(l);
    
}
