import com.google.common.collect.Lists;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Stream;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/get-minimum-fruits
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class GetMinimumFruits
{
    public int getMinimumFruits(int n, int[] fruits)
    {
        Map<Integer, Integer> uniqueVal2Count = new HashMap<>();
        for (int fruit : fruits) {
            uniqueVal2Count.putIfAbsent(fruit, 0);
            uniqueVal2Count.put(fruit, uniqueVal2Count.get(fruit) + 1);
        }
        List<Integer> vals = new ArrayList<>(uniqueVal2Count.values());
        // this step is critical
        vals = Lists.reverse(vals);
        int ret = 0;
        for (Integer val : vals) {
            if (ret <= 0) {
                ret += val;
            }
            else {
                ret -= val;
            }
        }
        return Math.abs(ret);
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of(5, new int[]{1, 2, 2, 2, 2}, 3),
                Arguments.of(5, new int[]{3, 3, 1, 1, 2}, 1),
                Arguments.of(4, new int[]{1, 2, 5, 6}, 0),
                Arguments.of(8, new int[]{3, 3, 3, 3, 1, 1, 1, 2}, 0),
                Arguments.of(4, new int[]{1, 1, 1, 1}, 4));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(int n, int[] fruits, int expected)
    {
        Assertions.assertEquals(expected, getMinimumFruits(n, fruits));
    }
}
