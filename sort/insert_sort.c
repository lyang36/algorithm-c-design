/*****************************************
 * Author: Lin Yang
 * Study the practical algorithm designs
 * This file contains the insertion sort algorithm
 * an algorithm that sort an integer list using 
 * O(n^2) time. 
 * Not a practical algorithm, but very easy to implement
 * Easier than the selection sort.
 */


#include <limits.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define TEST_NUM 1000

void swap_int(int* a, int* b){
    int v = *a;
    *a = *b;
    *b = v;
}


/*insertion sort*/
void insert_sort(int * list, int n_elements){
    for(int i = 0; i < n_elements; i++){
        int j = i;

        while(j > 0 && list[j] < list[j-1]){
            swap_int(list+j, list+j-1);
            j --;
        }
    }
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

    insert_sort(n, TEST_NUM);

    for(int i = 0; i < TEST_NUM; i++){
        printf(" %d", n[i]);
    }
    printf("\nDone!\n");
}
