#include <stdlib.h>
#include <stdio.h>
#include "binary_tree.h"

void btree_insert_value_(btree** proot, int value, btree* parent){
    if(NULL == *proot){
        *proot = (btree *) malloc(sizeof(btree));
        (*proot)->parent = parent;
        (*proot)->left = NULL;
        (*proot)->right = NULL;
        (*proot)->value = value;
        return;
    }

    if(value == ((*proot)->value)){
        return;
    }else if(value < (*proot)->value){
        btree_insert_value_(&((*proot)->left), value, *proot);
    }else{
        btree_insert_value_(&((*proot)->right), value, *proot);
    }
}
void btree_insert_value(btree** proot, int value){
    btree_insert_value_(proot, value, NULL);
}

void btree_insert_tree_(btree** proot, btree* root, btree* parent){
    if(NULL == *proot){
        *proot = root;
        (*proot)->parent = parent;
        return;
    }

    if(root == NULL){
        return;
    }

    /* Replace this node by the new root */
    if((*proot)->value == root->value){
        btree_insert_tree_(&((*proot)->left), root->left, *proot);
        btree_insert_tree_(&((*proot)->right), root->right, *proot);
        free(root);
    }else if(root->value < (*proot)->value){
        btree_insert_tree_(proot, root->right, parent);
        root->right = NULL;
        btree_insert_tree_(&((*proot)->left), root, *proot);
    }else{
        btree_insert_tree_(proot, root->left, parent);
        root->left = NULL;
        btree_insert_tree_(&((*proot)->right), root, *proot);
    }
}

void btree_insert_tree(btree** proot, btree* root){
    btree_insert_tree_(proot, root, NULL);
}

btree * btree_find_value(btree * root, int value){
    if(root == NULL){
        return NULL;
    }
    if(root->value == value){
        return root;
    }else if(value < root->value){
        return btree_find_value(root->left, value);
    }else{
        return btree_find_value(root->right, value);
    }
}


void btree_delete_node(btree** proot, btree* node){
    if(node == *proot){
        btree* parent = (*proot)->parent;
        btree* right = (*proot)->right;
        *proot = node->left;
        btree_insert_tree(proot, right);
        (*proot)->parent = parent;
    }else if(node->value < (*proot)->value){
        btree_delete_node(&((*proot)->left), node);
    }else{
        btree_delete_node(&((*proot)->right), node);
    }
}

/**Return the minimal valued node
 */ 
btree* btree_min_val(btree* root){
    if(root == NULL){
        return root; 
    }    
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

/**Return the maximum valued node
 */
btree* btree_max_val(btree* root){
    if(root == NULL){
        return root; 
    }    
    while(root->right != NULL){
        root = root->right;
    }   
    return root; 
}

/**Return the number of nodes in the tree;
 * using DFS 
*/
void btree_num_nodes_(btree* root, int* num){
    if(root == NULL){
        return;
    }else{
        (*num) ++; 
        btree_num_nodes_(root->left, num);
        btree_num_nodes_(root->right, num);
    }
}
int btree_num_nodes(btree* root){
    int num = 0;
    btree_num_nodes_(root, &num);
    return num;
}

/**Return the list by min to max order
 */
void btree_inorder_traverse_(btree* root, int** array){
    if(root == NULL){
        return;
    }else{
        btree_inorder_traverse_(root->left, array);
        *(*array) = root->value;
        (*array) ++;
        btree_inorder_traverse_(root->right, array);
    }            
}

void btree_inorder_traverse(btree* root, int* array){
    int** parray = &(array);
    btree_inorder_traverse_(root, parray);
}

void delete_btree(btree* root){
    if(root == NULL){
        return;
    }   
    if(root->left != NULL){
        delete_btree(root->left);
        root->left = NULL;
    }   
    if(root->right != NULL){
        delete_btree(root->right);
        root->right = NULL;
    }   
    free(root);
};
