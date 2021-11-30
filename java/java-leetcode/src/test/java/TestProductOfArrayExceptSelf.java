import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestProductOfArrayExceptSelf
{
    private ProductOfArrayExceptSelf productOfArrayExceptSelf;

    private static Object[][] testProductOfArrayExceptSelfDataProvider()
    {
        return new Object[][] {
                {new int[] {1, 2, 3, 4}, new int[] {24, 12, 8, 6}},
                {new int[] {-1, 1, 0, -3, 3}, new int[] {0, 0, 9, 0, 0}},
        };
    }

    @BeforeAll
    public void setUp()
    {
        productOfArrayExceptSelf = new ProductOfArrayExceptSelf();
    }

    @ParameterizedTest
    @MethodSource("testProductOfArrayExceptSelfDataProvider")
    public void testProductOfArrayExceptSelf(int[] nums, int[] expectation)
    {
        int[] ret = productOfArrayExceptSelf.productExceptSelf(nums);
        Assertions.assertArrayEquals(expectation, ret);
    }
}
