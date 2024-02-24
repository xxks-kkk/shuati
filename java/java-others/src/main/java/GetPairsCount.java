import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/amazon-get-pairs-count
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class GetPairsCount
{
    public long getPairsCount(int[] process, int k)
    {
        int numPairs = 0;
        for (int i = 0; i < process.length; i++) {
            for (int j = i + 1; j < process.length; j++) {
                if (Math.abs(process[i] - process[j]) <= k) {
                    numPairs++;
                }
            }
        }
        return numPairs;
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(Arguments.of(new int[]{100, 200, 300, 400}, 250, 5),
                Arguments.of(new int[]{10, 12, 11}, 0, 0),
                Arguments.of(new int[]{7, 10, 13, 11}, 3, 4));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(int[] process, int k, long expected)
    {
        Assertions.assertEquals(expected, getPairsCount(process, k));
    }
}
