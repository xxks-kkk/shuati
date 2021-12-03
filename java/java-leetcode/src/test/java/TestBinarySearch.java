import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestBinarySearch
{
    private BinarySearch binarySearch;

    @BeforeAll
    public void setUp()
    {
        binarySearch = new BinarySearch();
    }

    private static Object[][] testBinarySearchDataProvider()
    {
        return new Object[][] {
                {new int[] {-1, 0, 3, 5, 9, 12}, 9, 4},
                {new int[] {-1, 0, 3, 5, 9, 12}, 2, -1}
        };
    }

    @ParameterizedTest
    @MethodSource("testBinarySearchDataProvider")
    public void testBinarySearch(int[] nums, int num, int expectation)
    {
        assertEquals(expectation, binarySearch.search(nums, num));
    }
}
