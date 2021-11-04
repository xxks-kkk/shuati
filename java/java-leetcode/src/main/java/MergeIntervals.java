import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

// LC-56
public class MergeIntervals
{
    public int[][] merge(int[][] intervals)
    {
        ArrayList<List<Integer>> res = new ArrayList<>();
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        int intervalLowerBound = intervals[0][0];
        int intervalUpperBound = intervals[0][1];
        for (int i = 0; i < intervals.length - 1; ++i) {
            if (intervalUpperBound < intervals[i + 1][0]) {
                res.add(Arrays.asList(intervalLowerBound, intervalUpperBound));
                intervalUpperBound = intervals[i + 1][1];
                intervalLowerBound = intervals[i + 1][0];
            }
            else {
                intervalUpperBound = Math.max(intervalUpperBound, intervals[i + 1][1]);
            }
        }
        res.add(Arrays.asList(intervalLowerBound, intervalUpperBound));
        return res.stream().map(u -> u.stream().mapToInt(i -> i).toArray()).toArray(int[][]::new);
    }
}
