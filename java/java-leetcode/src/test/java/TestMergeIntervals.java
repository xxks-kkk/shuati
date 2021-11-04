import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.Arrays;
import java.util.Comparator;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestMergeIntervals
{
    private MergeIntervals mergeIntervals;

    @BeforeAll
    public void setUp()
    {
        mergeIntervals = new MergeIntervals();
    }

    private static Object[][] testMergeIntervalsDataProvider()
    {
        return new Object[][] {
                {new int[][] {{1, 3}, {2, 6}, {8, 10}, {15, 18}}, new int[][] {{1, 6}, {8, 10}, {15, 18}}},
                {new int[][] {{1, 3}, {2, 6}, {8, 10}, {9, 15}}, new int[][] {{1, 6}, {8, 15}}},
                {new int[][] {{1, 4}, {4, 5}}, new int[][] {{1, 5}}}
        };
    }

    @ParameterizedTest
    @MethodSource("testMergeIntervalsDataProvider")
    public void testMergeIntervals(int[][] intervals, int[][] expectation)
    {
        int[][] actual = mergeIntervals.merge(intervals);
        Arrays.sort(actual, Comparator.comparingInt(a -> a[0]));
        Arrays.sort(expectation, Comparator.comparingInt(a -> a[0]));
        for (int i = 0; i < expectation.length; ++i) {
            assertArrayEquals(expectation[i], actual[i]);
        }
    }
}
