import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.Arrays;
import java.util.Comparator;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestKClosestPointsToOrigin
{
    private KClosestPointsToOrigin kClosestPointsToOrigin;

    @BeforeAll
    public void setUp()
    {
        kClosestPointsToOrigin = new KClosestPointsToOrigin();
    }

    private static Object[][] testKClosestPointsToOriginDataProvider() {
        return new Object[][] {
                {new int[][] {{1,3},{-2,2}}, 1, new int[][]{{-2,2}}},
                {new int[][] {{3,3},{5,-1},{-2,4}}, 2, new int[][]{{3,3},{-2,4}}}
        };
    }

    @ParameterizedTest
    @MethodSource("testKClosestPointsToOriginDataProvider")
    public void testLeastNumberOfUniqueIntegersAfterKRemovals(int[][] points, int k, int[][] expectation) {
        int[][] res = kClosestPointsToOrigin.kClosest(points, k);
        assertEquals(expectation.length, res.length);
        Arrays.sort(expectation, Comparator.comparingInt(a -> a[0]));
        Arrays.sort(res, Comparator.comparingInt(a -> a[0]));
        for (int i = 0; i < res.length; ++i) {
            assertEquals(expectation[i][0], res[i][0]);
            assertEquals(expectation[i][1], res[i][1]);
        }
    }
}
