/*          
 * [Source] 
 *          
 * https://leetcode.com/problems/find-the-duplicate-number/#/description
 *          
 * [Problem Description]
 *          
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
 * Note:
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated more than once.
 *          
 * [Comments]
 *          
 * The algorithm used is called [Floyd's Tortoise and Hare](https://en.wikipedia.org/wiki/Cycle_detection#Floyd.27s_Tortoise_and_Hare)
 * Same as 141.
 *          
 * [Companies]
 */          

int findDuplicate(int* nums, int numsSize) {
  int tortoise;
  int hare;
  tortoise = nums[0];
  hare = nums[nums[0]];
  while (tortoise != hare)
  {
    tortoise = nums[tortoise];
    hare = nums[nums[hare]];
  }
  hare = 0;
  while (tortoise != hare)
  {
    tortoise = nums[tortoise];
    hare = nums[hare];
  }
  return hare;
}

