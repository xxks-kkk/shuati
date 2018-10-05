/*
 * [Source]
 * 
 * https://leetcode.com/problems/fizz-buzz/
 *
 * [Problem Description]
 *
 * Write a program that outputs the string representation of numbers from 1 to n.
 * But for multiples of three it should output “Fizz” instead of the number 
 * and for the multiples of five output “Buzz”. 
 * For numbers which are multiples of both three and five output “FizzBuzz”.
 * 
 * [Comments]
 *
 * This problem answers some fundamental usage in C:
 *
 * 1. How to initialize an array of strings in C?
 * 2. How to store int as string in C?
 *
 * http://stackoverflow.com/questions/21023605/initialize-array-of-strings
 *
 * [Companies]
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **
fizzBuzz(int n, int *returnSize)
{
    char **returnArray = malloc(sizeof(char *) * n);
    *returnSize = n;
    for (int i = 1; i < n + 1; ++i)
    {
        if (i % 3 == 0 && i % 5 == 0)
            returnArray[i - 1] = "FizzBuzz";
        else if (i % 3 == 0)
            returnArray[i - 1] = "Fizz";
        else if (i % 5 == 0)
            returnArray[i - 1] = "Buzz";
        else
        {
            // C: how we convert int to string (i.e. char*)
            int length = snprintf(NULL, 0, "%d", i) + 1;
            char *str = malloc(length);
            snprintf(str, length, "%d", i);
            returnArray[i - 1] = str;
        }
    }
    return returnArray;
}

int
main()
{
    // TODO: Add assertions test
    int returnSize = 0;
    char **array = fizzBuzz(15, &returnSize);
    int i;
    for (i = 0; i < returnSize; i++)
    {
        printf("Line #%d(length: %lu): %s\n", i, strlen(array[i]), array[i]);
    }
    return 0;
}
