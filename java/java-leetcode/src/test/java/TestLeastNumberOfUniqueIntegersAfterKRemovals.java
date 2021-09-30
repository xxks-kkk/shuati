import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestLeastNumberOfUniqueIntegersAfterKRemovals
{
    private LeastNumberOfUniqueIntegersAfterKRemovals leastNumberOfUniqueIntegersAfterKRemovals;

    @BeforeAll
    public void setUp()
    {
        leastNumberOfUniqueIntegersAfterKRemovals = new LeastNumberOfUniqueIntegersAfterKRemovals();
    }

    private static Object[][] testLeastNumberOfUniqueIntegersAfterKRemovalsDataProvider() {
        return new Object[][] {
                {new int[] {5,5,4}, 1, 1},
                {new int[] {4,3,1,1,3,3,2}, 3, 2},
                {new int[] {2,1,1,3,3,3}, 3, 1},
                {new int[] {1}, 1, 0}
        };
    }

    @ParameterizedTest
    @MethodSource("testLeastNumberOfUniqueIntegersAfterKRemovalsDataProvider")
    public void testLeastNumberOfUniqueIntegersAfterKRemovals(int[] arr, int k, int expectation) {
        assertEquals(expectation, leastNumberOfUniqueIntegersAfterKRemovals.findLeastNumOfUniqueInts(arr, k));
    }
}
