import java.util.ArrayList;
import java.util.List;

//LC-46
public class Permutations
{
    public List<List<Integer>> permute(int[] nums)
    {
        int[] used = new int[nums.length];
        List<List<Integer>> result = new ArrayList<>();
        permuteHelper(nums, nums.length, used, new ArrayList<>(), result);
        return result;
    }

    private void permuteHelper(int[] nums, int k, int[] used, List<Integer> tmp, List<List<Integer>> result)
    {
        if (k == 0) {
            result.add(new ArrayList<>(tmp));
            return;
        }
        for (int i = 0; i < nums.length; ++i) {
            if (used[i] != 1) {
                used[i] = 1;
                tmp.add(nums[i]);
                permuteHelper(nums, k - 1, used, tmp, result);
                used[i] = 0;
                tmp.remove(tmp.size() - 1);
            }
        }
    }
}
