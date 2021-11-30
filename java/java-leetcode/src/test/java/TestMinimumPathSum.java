import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestMinimumPathSum
{
    private MinimumPathSum minimumPathSum;

    @BeforeAll
    public void setUp()
    {
        minimumPathSum = new MinimumPathSum();
    }

    private static Object[][] testMinimumPathSumDataProvider()
    {
        return new Object[][] {
                {new int[][] {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 7},
                {new int[][] {{1, 2, 3}, {4, 5, 6}}, 12},
        };
    }

    @ParameterizedTest
    @MethodSource("testMinimumPathSumDataProvider")
    public void testMinimumPathSum(int[][] grid, int expectation)
    {
        Assertions.assertEquals(expectation, minimumPathSum.minPathSum(grid));
    }
}
