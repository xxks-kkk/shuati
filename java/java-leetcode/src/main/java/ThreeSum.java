import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

// LC-15
public class ThreeSum
{
    public List<List<Integer>> threeSum(int[] nums)
    {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; ++i) {
            if (i == 0 || (nums[i] != nums[i - 1])) {
                int key = nums[i];
                // find all pairs of two sums without duplicates given array has been sorted
                int leftptr = i + 1;
                int rightptr = nums.length - 1;
                while (leftptr < rightptr) {
                    int sum = key + nums[leftptr] + nums[rightptr];
                    if (sum > 0) {
                        rightptr -= 1;
                    }
                    else if (sum < 0) {
                        leftptr += 1;
                    }
                    else {
                        result.add(Arrays.asList(key, nums[leftptr], nums[rightptr]));
                        leftptr += 1;
                        while (nums[leftptr] == nums[leftptr - 1] && leftptr < rightptr) {
                            leftptr += 1;
                        }
                    }
                }
            }
        }
        return result;
    }

    // Same idea as threeSum but to illustrate the idea behind implementation.
    public List<List<Integer>> threeSum2(int[] nums)
    {
        List<List<Integer>> result = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; ++i) {
            if (i == 0 || (nums[i] != nums[i - 1])) {
                int key = nums[i];
                int[] input = Arrays.stream(nums, i + 1, nums.length).toArray();
                List<List<Integer>> tmp = findAllTwoSums(input, -key);
                result.addAll(tmp.stream().map(a -> {
                    ArrayList<Integer> b = new ArrayList<>(a);
                    b.add(key);
                    return b;
                }).collect(Collectors.toList()));
            }
        }
        return result;
    }

    private List<List<Integer>> findAllTwoSums(int[] nums, int target)
    {
        List<List<Integer>> res = new ArrayList<>();
        int leftptr = 0;
        int rightptr = nums.length - 1;
        while (leftptr < rightptr) {
            int sum = nums[leftptr] + nums[rightptr];
            if (sum > target) {
                rightptr -= 1;
            }
            else if (sum < target) {
                leftptr += 1;
            }
            else {
                res.add(Arrays.asList(nums[leftptr], nums[rightptr]));
                leftptr += 1;
                while (nums[leftptr] == nums[leftptr - 1] && leftptr < rightptr) {
                    leftptr += 1;
                }
            }
        }
        return res;
    }
}
