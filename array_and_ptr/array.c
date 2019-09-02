#include <stdio.h>

/* Shows how arrays and pointers can be treated the same */

void print_array( a, len )
    int* a;
    int  len;
{
    int i;
    for (i = 0; i < len; i++) {
	if (i < (len-1)) {
            printf( "a [%d] = %d, ", i, a [i]);
	} else {
	    printf( "a [%d] = %d\n", i, a [i]);
	}
    }
}

int main()
{
    int arr [5] = {10, 11, 12, 13, 14};
    int* p_arr;
    int  i;
    
    print_array( arr, 5 );
    p_arr = arr;
    for (i = 0; i < 5; i++) {
        printf( "   *(p + %d) = %d\n", i, *(p_arr + i) );
    }
}