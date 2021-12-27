import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertTrue;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestCombinations
{
    private Combinations combinations;

    @BeforeAll
    public void setUp()
    {
        combinations = new Combinations();
    }

    private static Object[][] testCombinationsDataProvider()
    {
        return new Object[][] {
                {4, 2, Arrays.asList(Arrays.asList(2, 4),
                        Arrays.asList(3, 4),
                        Arrays.asList(2, 3),
                        Arrays.asList(1, 2),
                        Arrays.asList(1, 3),
                        Arrays.asList(1, 4))},
                {1, 1, Arrays.asList(
                        Arrays.asList(1)
                )},
        };
    }

    @ParameterizedTest
    @MethodSource("testCombinationsDataProvider")
    public void testCombine(int n, int k, List<List<Integer>> expectation)
    {
        List<List<Integer>> ret = combinations.combine(n, k);
        assertTrue(Utils.checkListOfList(ret, expectation));
    }
}
