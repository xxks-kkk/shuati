/*          
 * [Source] 
 *          
 * https://leetcode.com/problems/single-number/#/description
 *          
 * [Problem Description]
 *          
 * Given an array of integers, every element appears twice except for one. Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 *
 * [Comments]
 *
 * XOR bitwise operation. For example, 121. 1&2 = 3; 3&1 = 2, which is the answer.
 *          
 * [Companies]
 */          

int singleNumber(int* nums, int numsSize) {
  int i, result;
  for(i = 0; i < numsSize; i++)
    result ^= nums[i];
  return result;
}
