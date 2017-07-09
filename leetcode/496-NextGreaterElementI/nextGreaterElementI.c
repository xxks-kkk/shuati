/*          
 * [Source] 
 *          
 * https://leetcode.com/problems/next-greater-element-i/#/description
 *          
 * [Problem Description]
 *          
 * You are given two arrays (without duplicates) nums1 and nums2 where nums1’s
 * elements are subset of nums2. Find all the next greater numbers for nums1's
 * elements in the corresponding values of nums2. 
 * 
 * The Next Greater Number of a number x in nums1 is the first greater number to
 * its right in nums2. If it does not exist, output -1 for this number.
 *
 * Example 1:
 * 
 * Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
 * Output: [-1,3,-1]
 * Explanation:
 * For number 4 in the first array, you cannot find the next greater number
 * for it in the second array, so output -1.
 * For number 1 in the first array, the next greater number for it in the
 * second array is 3.
 * (Let's say item "1" in nums1 has a corresponding value in nums2 which is 
 * item "1" (same value), and then we consider the next great value of item "1" 
 * in nums2, which is "3", because "3" is greater than "1" and "3" is at right 
 * side of "1".)
 * For number 2 in the first array, there is no next greater number for it in
 * the second array, so output -1.
 *
 * Example 2:
 * 
 * Input: nums1 = [2,4], nums2 = [1,2,3,4].
 * Output: [3,-1]
 * Explanation:
 * For number 2 in the first array, the next greater number for it in the
 * second array is 3.
 * For number 4 in the first array, there is no next greater number for it in
 * the second array, so output -1.
 * Note:
 * All elements in nums1 and nums2 are unique.
 * The length of both nums1 and nums2 would not exceed 1000.
 *          
 * [Comments]
 *          
 *          
 *          
 * [Companies]
 */          


// Solution 1: straightfoward solution. It can help to understand the question
// better.
// Runtime: O(MN), where M = findNumsSize; N = numsSize

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* findNums,
                        int findNumsSize,
                        int* nums,
                        int numsSize,
                        int* returnSize)
{
  *returnSize = findNumsSize;
  int* result = calloc(sizeof(int), *returnSize);
  int i, j, cand;
  for(i = 0; i < findNumsSize; i++)
  {
    result[i] = -1;
    cand = findNums[i];
    for(j = 0; j < numsSize; j++)
    {
      if (nums[j] == cand)
      {
        break;
      }
    }
    for(; j < numsSize; j++)
    {
      if(nums[j] > cand)
      {
        result[i] = nums[j];
        break;
      }
    }
  }
  return result;
}
