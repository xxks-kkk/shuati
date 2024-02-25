import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Stream;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/get-success-value
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class GetSuccessValue
{
    public int[] getSuccessValue(int[] queries, int[] numViewers)
    {
        List<Integer> result = new ArrayList<>();
        Arrays.sort(numViewers);
        for (int query : queries) {
            int val = 0;
            for (int i = numViewers.length - 1; i >= numViewers.length - query; i--) {
                val += numViewers[i];
            }
            result.add(val);
        }
        return result.stream().mapToInt(i -> i).toArray();
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of(new int[]{2, 3, 5}, new int[]{2, 5, 6, 3, 5}, new int[]{11, 16, 21}),
                Arguments.of(new int[]{1, 4}, new int[]{7, 3, 5, 2}, new int[]{7, 17}),
                Arguments.of(new int[]{1, 2, 3}, new int[]{7, 5, 6}, new int[]{7, 13, 18}));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(int[] queries, int[] numViewers, int[] expected)
    {
        Assertions.assertArrayEquals(expected, getSuccessValue(queries, numViewers));
    }
}
