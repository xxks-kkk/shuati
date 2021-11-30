// LC-238
public class ProductOfArrayExceptSelf
{
    public int[] productExceptSelf(int[] nums)
    {
        int n = nums.length;
        int[] res = new int[n];
        // res is almost same as productFromLeft but we "push"
        // the whole array to right for one position. For example, for
        // [1,2,3,4], productFromLeft = [1,2,6,24]. We push
        // [1,2,6,24] right for one position, which is [1,1,2,6], which
        // is our res.
        for (int i = 0; i < nums.length; ++i) {
            if (i == 0) {
                res[i] = 1;
            }
            else {
                res[i] = res[i - 1] * nums[i - 1];
            }
        }
        // we don't need a whole array for productFromRight;
        // just accumulate product from right into one int is enough.
        int productFromRight = nums[n - 1];
        for (int j = n - 1; j >= 0; j--) {
            if (j == n - 1) {
                res[j] = res[j];
            }
            else {
                res[j] *= productFromRight;
                productFromRight *= nums[j];
            }
        }
        return res;
    }

    // For the intuition of solving problem. Not
    // constant space as productExceptSelf but
    // this is a good start point for interview.
    public int[] productExceptSelf2(int[] nums)
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
