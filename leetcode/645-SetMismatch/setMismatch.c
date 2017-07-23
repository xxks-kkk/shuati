/*
 * [Source]
 * 
 * https://leetcode.com/contest/leetcode-weekly-contest-42/problems/set-mismatch/
 *
 * [Problem Description]
 *
 * The set S originally contains numbers from 1 to n. 
 * But unfortunately, due to the data error, one of the numbers in the set 
 * got duplicated to another number in the set, which results in 
 * repetition of one number and loss of another number.
 *
 * Given an array nums representing the data status of this set after 
 * the error. Your task is to firstly find the number occurs twice 
 * and then find the number that is missing. Return them in the form of an array.
 *
 * Example 1:
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 *
 * Note:
 * The given array size will in the range [2, 10000].
 * The given array's numbers won't have any order.
 *
 * [Companies]
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
  int sum = 0;
  int i;
  int *dict = calloc(sizeof(int), numsSize+1); // +1 to handle the case [1,2,2,4]
  for(i = 0; i < numsSize; i++)
  {
    sum += nums[i];
    dict[nums[i]]++; // if index is out of bound, leetcode will raise
                     // "munmap_chunk(): invalid pointer" when submit
  }
  int trueSum = (1+numsSize) * numsSize / 2;
  int diff = trueSum - sum;
  *returnSize = 2;
  int *result = malloc(sizeof(int) * (*returnSize));
  for(i = 0; i < numsSize + 1; i++) // also remember +1 here
  {
    if(dict[i] == 2)
    {
      result[0] = i;
      break;
    }
  }
  result[1] = result[0]+diff;
  free(dict);
  return result;
}
