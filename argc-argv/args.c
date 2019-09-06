#include <stdio.h>
#include <stdlib.h>

int main( argc, argv )
    int argc;
    char** argv;
{
    int i;

    printf( "%d arguments, argv [0] is %s\n", argc, argv [0] );
    for (i = 1; i < argc; i++) {
       printf( "arg [%d] is %s (as string), %d (as int)\n", i, argv [i], atoi( argv [i] ) );
    }
}
