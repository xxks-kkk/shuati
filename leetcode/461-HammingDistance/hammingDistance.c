/*          
 * [Source] 
 *          
 * https://leetcode.com/problems/hamming-distance
 *          
 * [Problem Description]
 *          
 * The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 * Given two integers x and y, calculate the Hamming distance.
 *
 * Note:
 * 0 ≤ x, y < 231.
 *
 * Example:
 * 
 * Input: x = 1, y = 4
 * 
 * Output: 2
 * 
 * Explanation:
 * 1   (0 0 0 1)
 * 4   (0 1 0 0)
 *        ↑   ↑
 * 
 * The above arrows point to positions where the corresponding bits are different.
 *
 * [Comments]
 *
 * The code use Brian Kernighan's way, which is best described here:
 *
 * - http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan
 * - http://www.geeksforgeeks.org/count-set-bits-in-an-integer/
 *          
 * [Companies]
 */          

int hammingDistance(int x, int y) {
  unsigned int v;
  unsigned int c; // accumulates the total bits set in v
  v = x ^ y;
  for(c = 0; v; c++)
  {
    v &= v - 1; // clear the leastsignificant bit set
  }
  return c;
}
