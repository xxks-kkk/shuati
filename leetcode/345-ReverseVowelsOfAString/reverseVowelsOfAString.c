/*
 * [Source]
 * 
 * https://leetcode.com/problems/reverse-vowels-of-a-string/
 *
 * [Problem Description]
 *
 * Write a function that takes a string as input and 
 * reverse only the vowels of a string.
 *
 * Ex1: Given s = "hello", return "holle". 
 * Ex2: Given s = "leetcode", return "leotcede".
 *
 * [Comments]
 *
 * The code can be changed:
 *
 * for(i = 0, j = strlen(s)-1; i < j;) 
 * {                                                                            
 *    while(!isVowel(s[i]) && i < j) i++; 
 *    while(!isVowel(s[j]) && i < j) j--;                                           
 *    ... [snip] ...
 *    i++; j--;
 * }                  
 *
 * This looks much more sense to me. However, the code may be optimized
 * to the actual code below. Note that, if we write something like this 
 * is NOT working:
 *
 * for(i = 0, j = strlen(s)-1; i < j;) 
 * {                                                                            
 *    while(!isVowel(s[i++]) && i < j);
 *    while(!isVowel(s[j--]) && i < j);
 *    ... [snip] ...
 * }                  
 * 
 * [Companies]
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int
isVowel(char c)
{
  c = tolower(c);
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char*
reverseVowels(char* s)
{
  int i, j;
  char temp;
  for(i = -1, j = strlen(s); i < j;) // i = -1, j = strlen(s) is critical
  {
    while(!isVowel(s[++i]) && i < j); // here  ++i is critical
    while(!isVowel(s[--j]) && i < j);
    if (i >= j) break;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
  return s;
}

int
main()
{
  char s[] = "leetcode";
  char *a = reverseVowels(s);
  printf("%s\n", a);
  return 0;
}
