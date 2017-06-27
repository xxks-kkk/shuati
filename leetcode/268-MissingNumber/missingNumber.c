/*          
 * [Source] 
 *          
 * https://leetcode.com/problems/missing-number/#/description
 *          
 * [Problem Description]
 *          
 * 
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find
 * the one that is missing from the array.
 * For example,
 * Given nums = [0, 1, 3] return 2.
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it
 * using only constant extra space complexity?
 *          
 * [Comments]
 *          
 *          
 *          
 * [Companies]
 * 
 * Microsoft
 */          

int missingNumber(int* nums, int numsSize) {
  int i, sum;
  for (i = 0, sum = 0; i < numsSize; i++)
    sum += nums[i];
  return (numsSize) * (numsSize + 1) / 2 - sum;
}

