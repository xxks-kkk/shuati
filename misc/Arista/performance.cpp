#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <iostream>
#include <cstdio>
using namespace std;

// To compile this program as C, using the headers as follows (remove using namespace std;)
// #include <ctime>
// #include <sys/time.h>
// #include <stdio.h>
// #include <stdlib.h>


/* What does this do? */
// Ans: count # of 1s for i
int
a(unsigned int i)
{
    int c = 0;
    while (i)
    {
        if (i & 1)
        {
            c++;
        }
        i >>= 1;
    }
    return c;
}

/* What does this one do? */
// Ans: count # of 1s for i
int
b(unsigned int i)
{
    static unsigned char n[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
    int c = 0;
    while (i)
    {
        c += n[i & 15];
        i >>= 4;
    }
    return c;
}

/* Which one do you think would run faster? */

/* Write a small program that uses the gettimeofday function to
 * benchmark these functions. 
 *
 * int gettimeofday(struct timeval *tv, struct timezone *tz);
 *
 * struct timeval {
 *    time_t      tv_sec;     // seconds
 *    suseconds_t tv_usec;    // microseconds
 * };
 *
 * The tz argument can be NULL in this case.
 */
int
main(int argc, char **argv)
{
    struct timeval* t_before = (timeval *) malloc(sizeof(struct timeval));
    struct timeval* t_after = (timeval *) malloc(sizeof(struct timeval));
    int ret;
    ret = gettimeofday(t_before, NULL);
    for(int i = 0; i < 8000000; ++i)
    {
        a(i);
    }
    // 1 sec 9000 us 2 sec 10 us
    ret = gettimeofday(t_after, NULL);
    if (t_after->tv_usec < t_before->tv_usec)
    {
        t_after->tv_usec += 1000000;
        t_after->tv_sec -= 1;
    }
    printf("%ld\n", t_after->tv_sec - t_before->tv_sec);
    printf("%d\n", t_after->tv_usec - t_before->tv_usec);

    ret = gettimeofday(t_before, NULL);
    for(int i = 0; i < 8000000; ++i)
    {
        b(i);
    }
    ret = gettimeofday(t_after, NULL);
    if (t_after->tv_sec < t_before->tv_usec)
    {
        t_after->tv_usec += 1000000;
        t_after->tv_sec -= 1;
    }
    printf("%ld\n", t_after->tv_sec - t_before->tv_sec);
    printf("%d\n", t_after->tv_usec - t_before->tv_usec);
}
