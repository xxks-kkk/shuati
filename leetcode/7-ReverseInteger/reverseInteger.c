/*
 * [Source]
 * 
 * https://leetcode.com/problems/reverse-integer/
 *
 * [Problem Description]
 *
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * [Companies]
 */


int reverse(int x)
{
  long long ret = 0;
  while(x)
  {
    ret = ret*10 + x%10;
    x = x/10;
  }
  return (ret<INT_MIN || ret>INT_MAX) ? 0 : ret;
}
