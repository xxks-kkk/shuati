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
 * [Companies]
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize)
{
  *returnSize = n;
  char** array = malloc(n * sizeof(char*));
  int i;
  for(i = 1; i <= n; i++)
  {
    if (i % 3 == 0 && i % 5 != 0)
    {
      array[i-1] = malloc(sizeof(char) * strlen("Fizz"));
      sprintf(array[i-1], "Fizz");
    }
    else if (i % 3 != 0 && i % 5 == 0)
    {
      array[i-1] = malloc(sizeof(char) * strlen("Buzz"));
      sprintf(array[i-1], "Buzz");
    }
    else if (i % 3 == 0 && i % 5 == 0)
    {
      array[i-1] = malloc(sizeof(char) * strlen("FizzBuzz"));
      sprintf(array[i-1], "FizzBuzz"); 
    }
    else
    {
      array[i-1] = malloc(sizeof(char));
      sprintf(array[i-1], "%d", i); // how we store int as string in C
    }
  }
  return array;
}

int
main()
{
  int returnSize = 0;
  char** array = fizzBuzz(15, &returnSize);
  int i;
  for(i = 0; i < returnSize; i++){
    printf("Line #%d(length: %lu): %s\n", i, strlen(array[i]),array[i]);
  } 
  return 0;
}
