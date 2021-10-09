import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

// Given a list of integers, partition it into two subsets S1 and S2 such that the sum of S1
// is greater than that of S2. And also the number of elements in S1 would be minimal.
// Return S1 in increasing order.
// Notice if more than one subset A exists, return the one with the maximal sum.
public class OptimizeBoxWeight
{
    public List<Integer> optimizeBoxWeight(int[] nums)
    {
        PriorityQueue<Integer> res = new PriorityQueue<>();
        int[] arrDesc = Arrays.stream(nums).boxed()
                .sorted(Collections.reverseOrder())
                .mapToInt(Integer::intValue)
                .toArray();
        int sum = Arrays.stream(nums).sum();
        double avg = sum / 2.0;
        int accumSum = 0;
        for (int j : arrDesc) {
            res.add(j);
            accumSum += j;
            if (accumSum > avg) {
                break;
            }
        }
        return new ArrayList<>(res);
    }
}
