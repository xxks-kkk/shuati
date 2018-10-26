/* What's wrong with this program? */

#include <stdio.h>


int
main( int argc, char const * argv ) {
   for( int i = 0; i < argc; ++i ) {
      printf("%s\n", argv[i] );
   }
}


/* Can you tell me what the program will do when I run it like this:
 * <prog> 1 2 3 4
 */


/*
Describe what two of these do, and how they're useful for debugging:

perf
oprofile
gprof
strace
gcov
printf
syslog
*/
