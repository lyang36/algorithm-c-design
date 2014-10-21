/*****************************************
 * Author: Lin Yang
 * Study the practical algorithm designs
 * This file contains the selection sort algorithm
 * an algorithm that sort an integer list using 
 * O(n^2) time. 
 * Not a practical algorithm, but very easy to implement
 */


#include <limits.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define TEST_NUM 30000

/*find the min of a integer list, returns the argmin and min*/
void findmin(int * list, int n_elements, int * argmin, int * vmin){
    int v_min = INT_MAX;
    int a_min = 0;
    for(int i = 0; i < n_elements; i++){
        if(v_min > list[i]){
            v_min = list[i];
            a_min = i;
        }
    }
    *argmin = a_min;
    *vmin = v_min;
}

/*insertion sort*/
void select_sort(int * list, int n_elements){
    for(int i = 0; i < n_elements; i++){
        int argmin;
        int vmin;
        findmin(list+i, n_elements - i, &argmin, &vmin);
        //printf("%d %d %d %d\n", i, argmin, list[i], list[argmin]);
        list[argmin + i] = list[i];
        list[i] = vmin;
        //printf("%d %d\n", list[i], list[argmin]);
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

    select_sort(n, TEST_NUM);

    for(int i = 0; i < TEST_NUM; i++){
        printf(" %d", n[i]);
    }
    printf("\nDone!\n");
}
