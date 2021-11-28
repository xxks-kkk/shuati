// LC-53
public class MaximumSubarray
{
    public int maxSubArray(int[] nums)
    {
        int maxEndingHere = nums[0];
        int globalMax = nums[0];
        for (int i = 1; i < nums.length; ++i) {
            maxEndingHere = Math.max(maxEndingHere + nums[i], nums[i]);
            globalMax = Math.max(globalMax, maxEndingHere);
        }
        return globalMax;
    }
}
