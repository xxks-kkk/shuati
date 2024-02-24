import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.HashMap;
import java.util.Map;
import java.util.stream.Stream;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/amazon-find-min-trips
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class FindMinimumTrips
{
    public int findMinTrips(int[] packageweight)
    {
        Map<Integer, Integer> uniqueVals2Count = new HashMap<>();
        for (int weight : packageweight) {
            uniqueVals2Count.putIfAbsent(weight, 0);
            uniqueVals2Count.put(weight, uniqueVals2Count.get(weight) + 1);
        }
        int numTrips = 0;
        for (int val : uniqueVals2Count.values()) {
            if (val % 3 == 0) {
                numTrips += (val / 3);
            }
            else if (val % 2 == 0) {
                numTrips += (val / 2);
            }
            else {
                return -1;
            }
        }
        return numTrips;
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of(new int[]{1, 8, 5, 8, 5, 1, 1}, 3),
                Arguments.of(new int[]{3, 4, 4, 3, 1}, -1),
                Arguments.of(new int[]{2, 4, 6, 6, 4, 2, 4}, 3));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(int[] packageweight, int expected)
    {
        Assertions.assertEquals(expected, findMinTrips(packageweight));
    }
}
