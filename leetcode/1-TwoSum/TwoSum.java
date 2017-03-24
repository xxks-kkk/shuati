/*
 * [Source]
 * 
 * https://leetcode.com/problems/two-sum/
 *
 * [Problem Description]
 *
 * Given an array of integers, return indices of the two numbers such that 
 * they add up to a specific target.
 * You may assume that each input would have exactly one solution, 
 * and you may not use the same element twice.
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 * [Companies]
 */

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class TwoSum
{
  // We use a dictionary ADT (hash map) that contains <idx, value> pairs
  // to reduce the look up time of a value to O(1).
  public static int[] twoSum(int[] numbers, int target)
  {
    Map<Integer, Integer> dict = new HashMap<>();
    for (int i = 0; i < numbers.length; i++)
    {
      int x = numbers[i];
      if (dict.containsKey(target - x))
      {
        return new int[] {dict.get(target - x), i};
      }
      dict.put(x, i);
    }
    throw new IllegalArgumentException("No two sum solution");
  }

  public static void main(String[] args)
  {
    int[] num = {2,7,11,15};
    int target = 9;
    System.out.println(Arrays.toString(twoSum(num, target)));
  }
}
