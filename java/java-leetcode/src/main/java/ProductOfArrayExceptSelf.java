// LC-238
public class ProductOfArrayExceptSelf
{
    public int[] productExceptSelf(int[] nums)
    {
        int n = nums.length;
        int[] productFromLeft = new int[n];
        int[] productFromRight = new int[n];
        int[] res = new int[n];
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                productFromLeft[i] = nums[i];
            }
            else {
                productFromLeft[i] = nums[i] * productFromLeft[i - 1];
            }
        }
        for (int j = n - 1; j >= 0; --j) {
            if (j == n - 1) {
                productFromRight[j] = nums[j];
            }
            else {
                productFromRight[j] = nums[j] * productFromRight[j + 1];
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                res[i] = productFromRight[i + 1];
            }
            else if (i == n - 1) {
                res[i] = productFromLeft[i - 1];
            }
            else {
                res[i] = productFromLeft[i - 1] * productFromRight[i + 1];
            }
        }
        return res;
    }
}
