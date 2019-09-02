#include <stdio.h>
#include <stdlib.h>

/*
 This program implements a hash table. If there is a collision, it adds an element to a linked list.
 A -1 indicates that that entry is empty.
*/

typedef struct elem t_elem;

typedef struct elem 
   {
      int     key;
      int     street_num;
      t_elem *next;
   } t_elem;

#define NOT_OCCUPIED -1
#define HASH_SIZE 11

t_elem hash_table [HASH_SIZE];

void print_hash_entry( e )
    t_elem e;
{
    if (e.key == NOT_OCCUPIED) {
        return;
    }
    t_elem *traverse = &e;

    while (traverse != NULL) {
        printf( "Key value is %d, ", traverse->key );
	traverse = traverse->next;
    }
    printf( "\n" );
}

void insert_hash( hash_elem, val, address )
   t_elem* hash_elem;
   int val;
   int address;
{
   t_elem *tmp;

   if (hash_elem->key == NOT_OCCUPIED) { /* Nothing is stored at this location. Just use location from array */
       hash_elem->key        = val;
       hash_elem->next       = NULL;
       hash_elem->street_num = address;
       return;
   } else { /* There is a collision. Need to create a new element */
       tmp = malloc(sizeof(t_elem));
       tmp->key  = val;              /* Put new value in new element */
       tmp->street_num = address;
       tmp->next = hash_elem-> next; /* Point to wherever first location points */
       hash_elem->next = tmp;        /* Putting new element at front of list */
       printf("Added %d after first element\n", val );
   }

}

int main()
{
    int i;
    int values [8] = {5, 22, 3, 17, 15, 103, 13, 500 };

    for (i = 0; i < HASH_SIZE; i++) {
        hash_table [i].key  = NOT_OCCUPIED;
	hash_table [i].next = NULL;
    }
    
    for (i = 0; i < (sizeof(values) / sizeof(values [0])); i++) {
       insert_hash( &(hash_table[ (values [i] % HASH_SIZE) ]), values [i] );
       print_hash_entry( hash_table[ (values [i] % HASH_SIZE) ] );
    }
}