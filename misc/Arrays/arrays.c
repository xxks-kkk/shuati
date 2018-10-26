#include <stdlib.h>
#include <stdio.h>

// Arista 2018

/* How are 1d arrays laid out in C?
 *   consider the following:
 *     int a[23];
 */

// Ans: According to K&R p.98, int a[23] gives a block of 23 consecutive objects named a[0], a[1], ... a[22]
// (An array is a contiguous chunk of memory to store multiple values)


/* What does the compiler do when you have the statement a[ 5 ] */

// Ans: it becomes *(a+5)


/* What about for a 2d array like the following:
 *     int b[6][7];
 */
/* What does the compiler do when you have the statement b[ 3 ][ 4 ] */

// Ans: According to K&R p.112, a 2D array is really a 1D array, each of whose elements is an array.


/* How do you create dynamically allocated arrays in C? */

// Ans: int* ip;
// ip = (int *) malloc(5*sizeof(int));
// ip = (int *) calloc(5, sizeof(int));

/* How do you create a dynamically allocated 2d array in C,
 *   such that the following would work properly?
 *     int **a = get2dArray( 5, 6 )
 *     a[ 2 ][ 3 ] = 5;
 */

int **
get2dArray(int row, int col)
{
    int **ptr;
    ptr = malloc(row * sizeof(int *));
    for (int i = 0; i < row; ++i)
    {
        ptr[i] = malloc(col * sizeof(int));
    }
    return ptr;
}

/* How would you extend it to create an N dimensional array in C,
 *   such that the following would work properly?
 *     int numDims = 3;
 *     int dimVals[] = [ 3, 4, 5 ];
 *     int ***a = ( int *** )getNdArray( numDims, dimVals );
 *     a[ 2 ][ 3 ][4] = 5;
 */

void *
getNdArray(int dims, int *dim)
{
    if (dims == 1)
    {
        return malloc(sizeof(int) * dim[dims - 1]);
    }
    else
    {
        void **ptr = malloc(sizeof(int *) * dim[0]);
        for (int i = 0; i < dim[0]; ++i)
        {
            ptr[i] = getNdArray(dims - 1, dim + 1);
        }
        return ptr;
    }
}

/* How would you go about freeing the memory? */

// Ref: https://www.eskimo.com/~scs/cclass/int/sx9b.html
// Valgrind cmd: valgrind --tool=memcheck --leak-check=full --leak-resolution=med  --track-origins=yes ./019
void
freeNdArray(void *array, int dims, int *dim)
{
    if (dims == 1)
    {
        free(array);
    }
    else
    {
        void** arr = array;
        for(int i = 0; i < dim[0]; ++i)
        {
            freeNdArray(arr[i], dims-1, dim+1);
        }
        free(arr);
    }
}