/* An example program to show how static variables, conditions,
   and switch statements work */

#include <stdio.h>

void static_example( )
{
   int a        = 10;
   static int b = 0;

   a++;
   b++;
   printf( "a = %d, b = %d\n", a, b );
}

void char_switch( c )
    char c;
{
    switch (c)
      {
        case 'a':
	    printf( "It's an A!\n" );
	    break;
        case 'b':
	    printf( "It's a B!\n" );
	    break;
        case 'c':
	    printf( "It's a C!\n" );
	    break;
	default:
	    printf( "It's not an A, B, nor C\n" );
	    break;
      }
}

int main()
{
    int i, j = 0;

    printf( "STATIC\n" );
    for (i = 0; i < 5; i++) {
        static_example();
    }
    printf( "\n" );

    i = -123;
    j = (i < 0) ? -i : i;
    printf( "CONDITIONAL: i = %d, j = %d\n\n", i, j );

    printf( "SWITCH\n" );
    char_switch( 'b' );
    char_switch( 'c' );
    char_switch( 'x' );
    char_switch( 'a' );
    
}
