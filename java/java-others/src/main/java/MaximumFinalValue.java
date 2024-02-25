import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

import static java.util.Arrays.sort;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/amazon-maximum-final
 * https://www.1point3acres.com/bbs/thread-1047623-1-1.html
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class MaximumFinalValue
{
    public int maximumFinal(int[] arr)
    {
        sort(arr);
        for (int i = 0; i < arr.length; i++) {
            if (i == 0 && arr[i] != 1) {
                arr[i] = 1;
            }
            else if (i >= 1) {
                int diff = arr[i] - arr[i - 1];
                if (diff > 1) {
                    arr[i] = arr[i] - (diff - 1);
                }
            }
        }
        return arr[arr.length - 1];
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of(new int[]{3, 1, 3, 4}, 4),
                Arguments.of(new int[]{1, 3, 2, 2}, 3));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(int[] arr, int expected)
    {
        Assertions.assertEquals(expected, maximumFinal(arr));
    }
}
