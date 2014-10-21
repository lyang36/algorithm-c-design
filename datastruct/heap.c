#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

heapi* make_heapi(int* array, int n){
    heapi* hp = (heapi*) malloc(sizeof(heapi));
    if(hp == NULL){
        fprintf(stderr, "Memory Error!\n");
        exit(1);
    }
    hp->p_array = (int*) malloc(sizeof(int) * n);
    if(hp->p_array == NULL){
        fprintf(stderr, "Memory Error!\n");
        exit(1);
    }
    hp->n = n;

    for(int i = n; i > 0; i--){
        hp->p_array[i - 1] = array[i - 1];
        bubble_down(hp, i);
    }

    return hp;
}

void del_heapi(heapi* hp){
    free(hp->p_array);
    free(hp);
}

void swap_int(int* a, int* b){
    int c;
    c = *b;
    *b = *a;
    *a = c;
}

/* bubble down elenment at n-1 of the heap array*/
void bubble_down(heapi* hp, int n){
    if(n * 2 > hp->n){
        return;
    }

    // only bubble to the first child
    if(n * 2 + 1 > hp->n){
        if(hp->p_array[n - 1] > hp->p_array[n * 2 - 1]){
            swap_int(hp->p_array + n - 1, hp->p_array + n * 2 - 1);
        }
        return;
    }

    if((hp->p_array[n - 1] <= hp->p_array[n * 2 - 1]) && 
       (hp->p_array[n - 1] <= hp->p_array[n * 2])){
        return;
    }
    // bubble to both children
    if(hp->p_array[n - 1] > hp->p_array[n * 2 - 1] && 
       hp->p_array[n - 1] > hp->p_array[n * 2]){
        if(hp->p_array[n * 2 - 1] <= hp->p_array[n * 2]){
            swap_int(hp->p_array + n - 1, hp->p_array + n * 2 - 1);
            bubble_down(hp, n * 2);
        }else{
            swap_int(hp->p_array + n - 1, hp->p_array + n * 2);
            bubble_down(hp, n * 2 + 1);
        }
        // bubble_down(hp, n * 2);
        // bubble_down(hp, n);
    }else{
        if(hp->p_array[n - 1] > hp->p_array[n * 2 - 1]){
            swap_int(hp->p_array + n - 1, hp->p_array + n * 2 - 1); 
            bubble_down(hp, n * 2);
        }else{
            swap_int(hp->p_array + n - 1, hp->p_array + n * 2);
            bubble_down(hp, n * 2 + 1);
        }
        //bubble_down(hp, n);
    }
}


int pop_min(heapi* hp){
    int min = hp->p_array[0];
    hp->p_array[0] = hp->p_array[hp->n - 1]; 
    hp->n --;
    bubble_down(hp, 1);
    return min;
}

