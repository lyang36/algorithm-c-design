/*****************************************
 * This file contains the merge_sort code
 * Author: Lin Yang
 * Date: Oct/21/2014
 *****************************************/

#include <limits.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "queue.h"


#define TEST_NUM 30000

void merge(int* array, int low, int middle, int high){
    queue* q1 = (queue*) malloc(sizeof(queue));
    queue* q2 = (queue*) malloc(sizeof(queue));
    if((q1 == NULL) || (q2 == NULL)){
        fprintf(stderr, "Memory error!\n");
        exit(1);
    }
    q1->first = NULL;
    q1->last = NULL;
    q2->first = NULL;
    q2->last = NULL;
    
    enqueue(q1, array + low, middle - low);
    enqueue(q2, array + middle, high - middle);
    

    int i = low;
    int res1, res2;
    int j1 = dequeue(q1, &res1);
    int j2 = dequeue(q2, &res2);
    
    while(i < high){
        if(j1 > 0 && j2 >0){
            if(res1 < res2){
                array[i] = res1;
                i ++;
                j1 = dequeue(q1, &res1);
            }else{
                array[i] = res2;
                i ++;
                j2 = dequeue(q2, &res2);
            }
        }else if(j1 > 0){
            array[i] = res1;
            i ++;
            j1 = dequeue(q1, &res1);
        }else if(j2 > 0){
            array[i] = res2;
            i ++;
            j2 = dequeue(q2, &res2);
        }

    }
    
    delete_queue(q1);
    delete_queue(q2);
}

void merge_sort(int* array, int n){
    int low = 0;
    int middle = n / 2;
    int high = n;
    if(n <= 1){
        return;
    }
    merge_sort(array, middle);
    merge_sort(array + middle, high - middle);
    merge(array, low, middle, high);
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

    merge_sort(n, TEST_NUM);

    for(int i = 0; i < TEST_NUM; i++){
        printf(" %d", n[i]);
    }
    printf("\nDone!\n");
}

