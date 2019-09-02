#include <stdio.h>
#include <stdlib.h>

typedef struct elem t_elem;

typedef struct elem 
   {
      int     key;
      t_elem *next;
   } t_elem;


void print_list( e )
    t_elem *e;
{
    t_elem *traverse = e;
    int i = 1;

    while (traverse != NULL) {
        printf( "Key value #%d is %d\n", i, traverse->key );
	i++;
	traverse = traverse->next;
    }
    printf( "\n" );
}

void insert_list( par_head, key )
   t_elem** par_head;
   int key;
{
   t_elem *current = *par_head;
   t_elem *prev    = NULL;
   t_elem *tmp;

   if ((*par_head == NULL) || (key <= current->key)) { /* New head element needed or nothing on list */
       *par_head = malloc(sizeof(t_elem));
       (*par_head)->key  = key;
       (*par_head)->next = current;
       return;
   } else {
       prev    = current;
       current = current->next;
       while (current != NULL) {
           if (key <= current->key) {
	       tmp = malloc(sizeof(t_elem));
	       tmp->key   = key;
	       tmp->next  = current;
	       prev->next = tmp;
	       return;
	   } else {
               prev    = current;
               current = current->next;
	   }
       }
       /* Must be bigger than any number in list */
       tmp = malloc(sizeof(t_elem));
       tmp->key   = key;
       tmp->next  = NULL;
       prev->next = tmp;
   }
}

int main()
{
    t_elem *head = NULL;
    
    insert_list( &head, 39 );
    print_list( head );
    insert_list( &head, 25 );
    print_list( head );
    insert_list( &head, 13 );
    print_list( head );
    insert_list( &head, -1 );
    print_list( head );
    insert_list( &head, 17 );
    print_list( head );
    insert_list( &head, 99 );
    print_list( head );
 
}