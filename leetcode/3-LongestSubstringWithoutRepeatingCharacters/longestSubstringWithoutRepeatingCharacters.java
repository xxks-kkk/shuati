/*
 * [Source]
 * 
 * https://leetcode.com/problems/longest-substring-without-repeating-characters
 *
 * [Problem Description]
 *
 * Given a string, find the length of the longest substring without repeating characters.
 *
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. 
 * Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 * 
 * [Companies]
 *
 * [Analysis]
 * - Runtime: O(N)
 * - Space: O(1) // even though we are allocating an array, no matter how long 
 *               // the string is, the size of the array stays at the same at 256.
 */

import java.util.*;

public class longestSubstringWithoutRepeatingCharacters
{
  public static void main(String[] args)
  {
    String s = "dvdf";
    System.out.println(lengthOfLongestSubstring(s)); // should be 3
  }

  // How can we look up if a character exists in a substring instantaneously?
  // The answer is to use a simple table to store the characters that have
  // appeared (in fact, define a mapping of the characters to its index is best
  // suit here). Make sure you communicate with your interviewer if the string
  // can have characters other than ‘a’–‘z’. (ie, Digits? Upper case letter?
  // Does it contain ASCII characters only? Or even unicode character sets?)

  // The next question is to ask yourself what happens when you found a
  // repeated character? For example, if the string is “abcdcedf”,
  // what happens when you reach the second appearance of ‘c’?
  // When you have found a repeated character (let’s say at index j),
  // it means that the current substring (excluding the repeated character of
  // course) is a potential maximum, so update the maximum if necessary.
  // It also means that the repeated character must have appeared
  // before at an index i, where i is less than j.
  // Since you know that all substrings that start before or at index i
  // would be less than your current maximum, you can safely start to
  // look for the next substring with head which starts exactly at index i + 1.

  // Therefore, you would need two indices to record the head and the tail
  // of the current substring.

  // What if the character set could contain unicode characters that is
  // out of ascii’s range? We could modify the above solution to use a hash map
  // instead of a simple int array of size 256.
  public static int lengthOfLongestSubstring(String s)
  {
    int[] charMap = new int[256];
    Arrays.fill(charMap, -1);
    int i = 0, maxLen = 0;
    for (int j = 0; j < s.length(); j++) {
      if (charMap[s.charAt(j)] >= i) {
        i = charMap[s.charAt(j)] + 1;
      }
      charMap[s.charAt(j)] = j;
      maxLen = Math.max(j - i + 1, maxLen);
    }
    return maxLen;
  }
}
