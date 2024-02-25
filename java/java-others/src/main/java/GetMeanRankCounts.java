import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.HashMap;
import java.util.Map;
import java.util.stream.Stream;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/get-mean-rank-count
 * Ref:
 * - https://www.1point3acres.com/bbs/thread-1001645-1-1.html
 * - https://www.geeksforgeeks.org/count-of-subarrays-with-average-k/
 * - my github doc
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class GetMeanRankCounts
{
    // efficient solution (github and geeksforgeeks methods)
    public int[] getMeanRankCount(int[] rank)
    {
        int[] result = new int[rank.length];
        for (int i = 1; i <= rank.length; ++i) {
            result[i - 1] = countSubarraysWithAverageK(rank, i);
        }
        return result;
    }

    private int countSubarraysWithAverageK(int[] rank, int k)
    {
        int prefixSum = 0;
        int count = 0;
        Map<Integer, Integer> prefixSum2Count = new HashMap<>();
        for (int r : rank) {
            prefixSum += (r - k);
            // first situation where the sum is explicitly 0.
            if (prefixSum == 0) {
                count++;
            }
            // second situation where the sum shows up before.
            if (prefixSum2Count.containsKey(prefixSum)) {
                count += prefixSum2Count.get(prefixSum);
            }
            prefixSum2Count.putIfAbsent(prefixSum, 0);
            prefixSum2Count.put(prefixSum, prefixSum2Count.get(prefixSum) + 1);
        }
        return count;
    }

    // naive solution
    public int[] getMeanRankCount2(int[] rank)
    {
        int[] result = new int[rank.length];
        for (int i = 1; i <= rank.length; ++i) {
            result[i - 1] = countSubarraysWithAverageK(rank, i);
        }
        return result;
    }

    private int getMeanRankCount2Helper(int[] rank, int k)
    {
        int count = 0;
        for (int i = 0; i < rank.length; i++) {
            for (int j = i + 1; j < rank.length; ++j) {
                int sum = 0;
                for (int l = i; l <= j; l++) {
                    sum += rank[l];
                }
                if (sum / (j - i + 1) == k) {
                    count++;
                }
            }
        }
        return count;
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of(new int[]{1, 2, 3, 4, 5}, new int[]{1, 2, 3, 2, 1}),
                Arguments.of(new int[]{4, 3, 2, 1}, new int[]{1, 2, 2, 1}),
                Arguments.of(new int[]{4, 7, 3, 6, 5, 2, 1}, new int[]{1, 1, 1, 4, 4, 1, 1}));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(int[] rank, int[] expected)
    {
        Assertions.assertArrayEquals(expected, getMeanRankCount(rank));
        Assertions.assertArrayEquals(expected, getMeanRankCount2(rank));
    }
}
