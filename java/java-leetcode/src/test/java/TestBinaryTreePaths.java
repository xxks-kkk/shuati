import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestBinaryTreePaths
{
    private BinaryTreePaths binaryTreePaths;

    @BeforeAll
    public void setUp()
    {
        binaryTreePaths = new BinaryTreePaths();
    }

    private static Object[][] testBinaryTreePathsDataProvider() {
        return new Object[][] {
                {Arrays.asList(1,2,3,null,5), Arrays.asList("1->2->5", "1->3")},
                {Arrays.asList(1), Arrays.asList("1")}
        };
    }

    @ParameterizedTest
    @MethodSource("testBinaryTreePathsDataProvider")
    public void testBinaryTreePaths(List<Integer> nums, List<String> expectation) {
        TreeNode root = TreeNode.list2Tree(nums);
        expectation.sort(Comparator.naturalOrder());
        List<String> ret = binaryTreePaths.binaryTreePaths(root);
        ret.sort(Comparator.naturalOrder());
        assertEquals(expectation, ret);
    }
}
