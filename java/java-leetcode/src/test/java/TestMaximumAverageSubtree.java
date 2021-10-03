import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.Arrays;
import java.util.stream.Collectors;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestMaximumAverageSubtree
{
    private MaximumAverageSubtree maximumAverageSubtree;

    @BeforeAll
    public void setUp()
    {
        maximumAverageSubtree = new MaximumAverageSubtree();
    }

    private static Object[][] testMaximumAverageSubtreeDataProvider() {
        return new Object[][] {
                {new int[] {5,6,1}, 6.0},
                {new int[] {5,6,1,7,8}, 8.0}
        };
    }

    @ParameterizedTest
    @MethodSource("testMaximumAverageSubtreeDataProvider")
    public void testMaximumAverageSubtree(int[] nums, double expectation) {
        TreeNode root = TreeNode.list2Tree(Arrays.stream(nums).boxed().collect(Collectors.toList()));
        assertEquals(expectation, maximumAverageSubtree.maximumAverageSubtree(root));
    }
}
