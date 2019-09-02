#include <stdio.h>

void example( a, b )
    int a;  int* b;
{
   a  = 10;
   *b = 20;
}

int main()
{
    int i, j;
    int* p_i;

    i = -7;
    j = -7;
    printf( "i = %d, j = %d\n", i, j );
    p_i = &i;
    *p_i = 5;
    printf( "i = %d, j = %d\n", i, j );
    example( i, &j );
    printf( "i = %d, j = %d\n", i, j );
}