import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;

public class TestTwoSum
{
    private static Object[][] testTwoSumDataProvider() {
        return new Object[][] {
                {new int[] {2,7,11,15}, 9, new int[] {0,1}}
        };
    }

    @ParameterizedTest
    @MethodSource("testTwoSumDataProvider")
    public void testTwoSum(int[] num, int target, int[] expectation) {
        assertArrayEquals(expectation, TwoSum.twoSum(num, target));
    }
}
