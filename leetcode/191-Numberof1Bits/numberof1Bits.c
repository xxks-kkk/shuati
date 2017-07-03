/*          
 * [Source] 
 *          
 * https://leetcode.com/problems/number-of-1-bits/#/description
 *          
 * [Problem Description]
 *          
 * Write a function that takes an unsigned integer and returns the number of ’1'
 * bits it has (also known as the Hamming weight).
 * For example, the 32-bit integer ’11' has binary representation
 * 00000000000000000000000000001011, so the function should return 3.
 *          
 * [Comments]
 *          
 * Same as 461
 *          
 * [Companies]
 */          


int hammingWeight(uint32_t n)
{
  int cnt = 0;
  while(n != 0)
  {
    n &= (n-1);
    cnt++;
  }
  return cnt;
}
