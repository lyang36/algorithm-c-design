/*****************************************
 * Author: Lin Yang
 * Study the practical algorithm designs
 * This file contains the heap sort algorithm
 * Date: 10/21/2014 
 */

#include <limits.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "heap.h"


#define TEST_NUM 30000


/*Heap sort*/
void heap_sort(int * array, int n){
    heapi* hp = make_heapi(array, n);
    for(int i = 0; i < n; i++){
        array[i] = pop_min(hp);
    } 
    del_heapi(hp);
}



/*main*/
int main(){
    srand(time(NULL));
    int n[TEST_NUM];
    printf("Initial list: ");
    for(int i = 0; i < TEST_NUM; i++){
        n[i] = rand() % 1000;
        printf(" %d", n[i]);
    }
    printf("  \nOutputs are: ");
    
    heap_sort(n, TEST_NUM);

    for(int i = 0; i < TEST_NUM; i++){
        printf(" %d", n[i]);
    }
    printf("\nDone!\n");
}

