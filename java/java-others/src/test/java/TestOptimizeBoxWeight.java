import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import static org.junit.jupiter.api.Assertions.assertEquals;


@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestOptimizeBoxWeight
{
    private OptimizeBoxWeight optimizeBoxWeight;

    @BeforeAll
    public void setUp()
    {
        optimizeBoxWeight = new OptimizeBoxWeight();
    }

    private static Object[][] testOptimizeBoxWeightDataProvider()
    {
        return new Object[][] {
                {new int[]{4,5,2,3,1,2}, new int[] {4, 5}},
                {new int[]{10,5,3,1,20}, new int[] {20}},
                {new int[]{1,2,3,5,8}, new int[]{5,8}}
        };
    }

    @ParameterizedTest
    @MethodSource("testOptimizeBoxWeightDataProvider")
    public void testOptimizeBoxWeight(int[] nums, int[] expectation)
    {
        List<Integer> ret = optimizeBoxWeight.optimizeBoxWeight(nums);
        assertEquals(expectation.length, ret.size());
        for (int i = 0; i < ret.size(); ++i) {
            assertEquals(expectation[i], ret.get(i));
        }
    }
}
