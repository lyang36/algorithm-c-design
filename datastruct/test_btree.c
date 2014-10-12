#include <limits.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "binary_tree.h"

#define TEST_NUM 100

int main(){
    int sorted_list[TEST_NUM];

    srand(time(NULL));
    btree* tree = NULL;

    printf("Inserted random number list:\n");
    for(int i = 0; i < TEST_NUM; i++){
        int n = rand() % 100;
        btree_insert_value(&tree, n);
        printf("%d ", n);
    }
    printf("\n");

    printf("Sorted list (removed duplicates):\n");
    btree_inorder_traverse(tree, sorted_list);

    int size_tree = btree_num_nodes(tree);
    
    printf("Output: %d nodes\n", size_tree);
    for(int i = 0; i < size_tree; i++){
        printf("%d ", sorted_list[i]);
    } 
    printf("\n");

    delete_btree(tree);
}

