#include <stdio.h>

struct s {
   double f;  // 8 bytes
   int i;     // 4 bytes
   char c[3]; // 3 bytes + 1 byte
   void *p;   // 4 bytes
   int x[0];  // 4 bytes
};


int main( int argc, char ** argv ) {
    /* How big is a float? */
    // Ans: 4 bytes

    /* write a program to tell me how big a float is */
    printf("float size: %lu\n", sizeof(float));

    /* can you use gdb to show me how big a float is? */
    // Ans: p sizeof(float)

    /* How many bytes will structure s take? */
    // Ans: 24 bytes

    /* Write a quick program to tell me the size of structure s */
    /* Does this match what you expected? */
    // Ans: yes (24 bytes)
    printf("struct size: %lu\n", sizeof(struct s));

}


/* What does this do?
#define ABC(x) aaa ## x

ABC(b)
*/
// Ans: gives aaab
// '##' preprocessing operator performs token pasting. When a macro is expanded, the two tokens on either side of
// each '##' operator are combined into a single token, which then replaces the '##' and the two original tokens in the macro
// expansion
// Ref:
// - https://gcc.gnu.org/onlinedocs/cpp/Concatenation.html
// - https://stackoverflow.com/questions/21891784/what-does-mean-in-c









/* How are 1d arrays laid out in C ? */
/* What does the compiler do when you have a statement a[ 5 ] */
/* How do you create dynamically allocated arrays in C and how does the complier generate the memory access for a[ 5 ] */
/* How are 2d arrays laid out in C */
/* How do you create a dynamically allocated 2d array in C such that something like: 

int **a = get2dArray( 5, 6)
a[ 2 ][ 3] = 5;

would work properly.*/
/* How would you extend it to create an N dimensional array. Something like:
getNdArray( int n, int * dim)

where n = the number of dimensions, and dim is the actual dimensions.

so you could create a 3d array of size 3,4,5 as
int dim[] = [ 3, 4, 5 ];
int ***a = getNdArray( 3, dim );
*/

