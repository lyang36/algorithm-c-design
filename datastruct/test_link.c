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
