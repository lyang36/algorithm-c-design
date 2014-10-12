#ifndef LY_BINARY_TREE
#define LY_BINARY_TREE

typedef struct btree{
    int value;
    struct btree* parent;
    struct btree* left;
    struct btree* right;
} btree;

/**Insert a value to the tree,
 * by giving pointer of the root 
 * of the tree.
 */
void btree_insert_value(btree** proot, int value);

/**Insert a binary tree to the exist binary tree.
 */
void btree_insert_tree(btree** proot, btree* root);

/* Find whether the value is inside the 
 * tree. Given the root of the the tree.
 */
btree * btree_find_value(btree * root, int value);

/**Delete a node from the tree. Given
 * the point of the node to-be-deleted.  
 */
void btree_delete_node(btree** root, btree* node);

/**Return the minimal valued node
 */ 
btree* btree_min_val(btree* root);

/**Return the maximum valued node
 */
btree* btree_max_val(btree* root);

/**Return the number of nodes in the tree;
 */
int btree_num_nodes(btree* root);

/**Return the list by min to max order
 */
void btree_inorder_traverse(btree* root, int* array);

/**Delete the whole tree
 */
void delete_btree(btree* root);

#endif
