/* An example program to show how static variables work */

#include <stdio.h>

void example( )
{
   int a        = 10;
   static int b = 0;

   a++;
   b++;
   printf( "a = %d, b = %d\n", a, b );
}

int main()
{
    int i = 0;

    for (i = 0; i < 5; i++) {
        example();
    }
}
