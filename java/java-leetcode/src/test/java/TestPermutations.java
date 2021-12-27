import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertTrue;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestPermutations
{
    private Permutations permutations;

    @BeforeAll
    public void setUp()
    {
        permutations = new Permutations();
    }

    private static Object[][] testPermutationsDataProvider()
    {
        return new Object[][] {
                {new int[] {1, 2, 3}, Arrays.asList(Arrays.asList(1, 2, 3),
                        Arrays.asList(1, 3, 2),
                        Arrays.asList(2, 1, 3),
                        Arrays.asList(2, 3, 1),
                        Arrays.asList(3, 1, 2),
                        Arrays.asList(3, 2, 1))},
                {new int[] {0, 1}, Arrays.asList(
                        Arrays.asList(0, 1),
                        Arrays.asList(1, 0)
                )},
                {new int[] {1}, Arrays.asList(
                        Arrays.asList(1)
                )}
        };
    }

    @ParameterizedTest
    @MethodSource("testPermutationsDataProvider")
    public void testPermutations(int[] num, List<List<Integer>> expectation)
    {
        List<List<Integer>> ret = permutations.permute(num);
        assertTrue(Utils.checkListOfList(ret, expectation));
    }
}
