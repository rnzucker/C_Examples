#include <stdio.h>

struct date 
   {
      int day;
      int month;
      int year;
   };

typedef struct date t_date;

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
    struct date today;
    t_date tomorrow;

    today.day   = 20;
    today.month = 10;
    today.year  = 1997;

    tomorrow = today;
    tomorrow.day++;
    
    printf( "Date is day %d of month %d, year %d\n", today.day, today.month, today.year );
    printf( "Tomorrow is day %d of month %d, year %d\n", tomorrow.day, tomorrow.month, tomorrow.year );
    
}