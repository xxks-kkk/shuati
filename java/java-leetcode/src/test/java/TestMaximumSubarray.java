import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestMaximumSubarray
{
    private MaximumSubarray maximumSubarray;

    @BeforeAll
    public void setUp()
    {
        maximumSubarray = new MaximumSubarray();
    }

    private static Object[][] testMaximumSubarrayDataProvider()
    {
        return new Object[][] {
                {new int[] {-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6},
                {new int[] {1}, 1},
                {new int[] {5, 4, -1, 7, 8}, 23}
        };
    }

    @ParameterizedTest
    @MethodSource("testMaximumSubarrayDataProvider")
    public void testMaximumAverageSubtree(int[] nums, int expectation)
    {
        assertEquals(expectation, maximumSubarray.maxSubArray(nums));
    }
}
