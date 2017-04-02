/*
 * [Source]
 * 
 * https://leetcode.com/problems/reverse-string
 *
 * [Problem Description]
 *
 * Write a function that takes a string as input and returns the string reversed.
 *
 * Ex: Given s = "hello", return "olleh". 
 * 
 * [Comments]
 *
 * Creating a new char* and then walking backward from the origin char* and put the 
 * value in the new char* doesn't work in leetcode for some reason.
 *
 * [Companies]
 */


char*
reverseString(char* s)
{
  int i, j;
  char temp;
  for(i = 0, j = strlen(s)-1; i < j; i++, j--)
  {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
  return s;
}
