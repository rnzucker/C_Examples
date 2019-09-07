#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node t_node;

typedef struct node 
   {
      int     key;
      t_node *left;
      t_node *right;
   } t_node;


void print_tree( elem )
    t_node *elem;
{
    if (elem != NULL) {
        print_tree( elem->left );
	printf( "%d\n", elem->key );
	print_tree( elem->right );
    }
}

_Bool tree_print( elem, depth )
    t_node *elem;
    int    depth;
{
    if (elem == NULL) {
        return false;
    } else if (depth == 0) { /* At desired depth */
        printf( "%d ", elem->key );
	return true;
    } else {
       _Bool retval_left, retval_right;
       /* Need to make sure that there is nothing on either branch. Hence, the booleans */
       retval_left  = tree_print( elem->left, depth-1 );
       retval_right = tree_print( elem->right, depth-1 ); /* Need to watch out for short circuit evaluation */
       return retval_left || retval_right;
    }
}

void tree_format_print( par_root )
    t_node* par_root;
{
    int depth = 0;
    printf( "  Printing in tree format\n" ); /* printing all nodes at same depth on the same line */
    while (tree_print( par_root, depth)) {
	/* Start printing at depth zero, then each depth down, breadth first. */
        depth++;
	printf( "\n" );
    }
}

void insert_tree( par_root, key )
   t_node** par_root;
   int key;
{
   t_node *current = *par_root;

   if (*par_root == NULL) { /* Tree is empty */
       *par_root = malloc(sizeof(t_node));
       (*par_root)->key   = key;
       (*par_root)->left  = NULL;
       (*par_root)->right = NULL;
       return;
   } else if ((*par_root)->key == key) { /* Duplicate */
       printf( "%d is already in the tree\n\n", key );
       return;
   } else if (key < (*par_root)->key) {
       insert_tree( &((*par_root)->left), key );
   } else { /* Must be greater than key; go to the right */
       insert_tree( &((*par_root)->right), key );
   }
}

int main()
{
    t_node *root = NULL;
    
    insert_tree( &root, 39 );
    print_tree( root );
    printf( "\n" );

    insert_tree( &root, 99 );
    print_tree( root );
    printf( "\n" );

    insert_tree( &root, 25 );
    print_tree( root );
    printf( "\n" );

    insert_tree( &root, 13 );
    print_tree( root );
    printf( "\n" );

    insert_tree( &root, -1 );
    print_tree( root );
    printf( "\n" );

    insert_tree( &root, 25 );
    print_tree( root );
    printf( "\n" );

    insert_tree( &root, 17 );
    print_tree( root );
    printf( "\n" );

    tree_format_print( root );
 
}