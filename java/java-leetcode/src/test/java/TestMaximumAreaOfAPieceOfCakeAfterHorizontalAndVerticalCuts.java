import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestMaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCuts
{
    private MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCuts maximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCuts;

    @BeforeAll
    public void setUp()
    {
        maximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCuts = new MaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCuts();
    }

    private static Object[][] testTestMaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCutsDataProvider()
    {
        return new Object[][] {
                {5, 4, new int[] {1, 2, 4}, new int[] {1, 3}, 4},
                {5, 4, new int[] {3, 1}, new int[] {1}, 6},
                {5, 4, new int[] {3}, new int[] {3}, 9},
                {1000000000, 1000000000, new int[]{2}, new int[]{2}, 81}
        };
    }

    @ParameterizedTest
    @MethodSource("testTestMaximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCutsDataProvider")
    public void testLeastNumberOfUniqueIntegersAfterKRemovals(int h, int w, int[] horizontalCuts, int[] verticalCuts, int expectation)
    {
        assertEquals(expectation, maximumAreaOfAPieceOfCakeAfterHorizontalAndVerticalCuts.maxArea(h, w, horizontalCuts, verticalCuts));
    }
}
