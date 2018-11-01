## Solution explanation

The `O(n)` solution is the optimized version of the brute force
solution shown below:

```java
class Solution {
    private boolean arrayContains(int[] arr, int num) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == num) {
                return true;
            }
        }

        return false;
    }
    public int longestConsecutive(int[] nums) {
        int longestStreak = 0;

        for (int num : nums) {
            int currentNum = num;
            int currentStreak = 1;

            while (arrayContains(nums, currentNum + 1)) {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = Math.max(longestStreak, currentStreak);
        }

        return longestStreak;
    }
}
```

- Runtime: O(n)

Although the time complexity appears to be quadratic due to the 
while loop nested within the for loop, closer inspection reveals it to be linear. Because the while loop is reached 
only when `curNum` marks the beginning of a sequence (i.e. `curNum-1` is not present in `nums`), 
the while loop can only run for `n` iterations throughout the entire runtime of the algorithm. 
This means that despite looking like `O(n⋅n)` complexity, the nested loops actually run in 
`O(n+n) = O(n)` time. All other computations occur in constant time, so the overall runtime is linear.

- Space: O(n)

## Reference

- https://leetcode.com/articles/longest-consecutive-sequence/