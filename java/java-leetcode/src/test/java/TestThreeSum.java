import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Objects;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestThreeSum
{
    private ThreeSum threeSum;

    @BeforeAll
    public void setUp()
    {
        threeSum = new ThreeSum();
    }

    private static Object[][] testThreeSumDataProvider()
    {
        return new Object[][] {
                {new int[] {-1, 0, 1, 2, -1, -4}, Arrays.asList(Arrays.asList(-1, -1, 2), Arrays.asList(-1, 0, 1))},
                {new int[] {-2, 1, 1, 1}, Arrays.asList(Arrays.asList(-2, 1, 1))},
                {new int[] {-1,0,1,0}, Arrays.asList(Arrays.asList(-1,0,1))},
                {new int[] {-2,0,0,2,2}, Arrays.asList(Arrays.asList(-2,0,2))},
                {new int[] {}, Arrays.asList()},
                {new int[] {0}, Arrays.asList()}
        };
    }

    @ParameterizedTest
    @MethodSource("testThreeSumDataProvider")
    public void testThreeSum(int[] nums, List<List<Integer>> expectation)
    {
        List<List<Integer>> ret = threeSum.threeSum(nums);
        assertEquals(expectation.size(), ret.size());
        for (int i = 0; i < ret.size(); ++i) {
            ret.get(i).sort(Comparator.comparingInt(a -> a));
            expectation.get(i).sort(Comparator.comparingInt(a -> a));
        }
        ret.sort((a, b) -> {
            if (!Objects.equals(a.get(0), b.get(0))) {
                return a.get(0) - b.get(0);
            }
            else if (!Objects.equals(a.get(1), b.get(1))) {
                return a.get(1) - b.get(1);
            }
            else {
                return a.get(2) - b.get(2);
            }
        });
        expectation.sort((a, b) -> {
            if (!Objects.equals(a.get(0), b.get(0))) {
                return a.get(0) - b.get(0);
            }
            else if (!Objects.equals(a.get(1), b.get(1))) {
                return a.get(1) - b.get(1);
            }
            else {
                return a.get(2) - b.get(2);
            }
        });
        for (int i = 0; i < ret.size(); ++i) {
            assertEquals(expectation.get(i).size(), ret.get(i).size());
            for (int j = 0; j < ret.get(i).size(); ++j) {
                assertEquals(expectation.get(i).get(j), ret.get(i).get(j));
            }
        }
    }
}
