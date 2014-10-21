/********************************************
 * Quick sort.
 * Running in expected O(nlogn) time. The 
 * This is the fast one, since no memory 
 * operations.
 *
 * Lin Yang
 * Dec 21, 2014
 * ******************************************/


#include <stdio.h>
#include <stdlib.h>

#include <limits.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define TEST_NUM 30000

void swap_int(int* x, int* y){
    int z = *y;
    *y = *x;
    *x = z;
}

/*partition an array by a random median*/
int partition(int * array, int n){
    int l = 0;
    int h = n - 1;

    // the partition point
    int q = n - 1;
    int partid = rand() % n;
    swap_int(array + partid, array + q);
    
    // to record the partition position
    int firsthigh = 0;    
    
    for(int i = l; i <= h; i++){
        if(array[i] < array[q]){
            swap_int(array + i, array + firsthigh);
            firsthigh ++;
        }
    } 
    swap_int(array + q, array + firsthigh);

    return firsthigh;
}


void quick_sort(int* array, int n){
    if(n < 2){
        return;
    }
    
    int q = partition(array, n);
    quick_sort(array, q);
    quick_sort(array + q + 1, n - q - 1);
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

    quick_sort(n, TEST_NUM);

    for(int i = 0; i < TEST_NUM; i++){
        printf(" %d", n[i]);
    }   
    printf("\nDone!\n");
}

