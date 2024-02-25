import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

import static java.util.Arrays.sort;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/warehouse-distribution
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class WarehouseDistribution
{
    public long findMinimumOperations(int[] boxes)
    {
        int prevDiff = 0;
        int currDiff;
        int numOps = 0;
        while (true) {
            sort(boxes);
            currDiff = boxes[boxes.length - 1] - boxes[0];
            if (currDiff != 0 && currDiff != prevDiff) {
                boxes[boxes.length - 1] = boxes[boxes.length - 1] - 1;
                boxes[0] = boxes[0] + 1;
                prevDiff = currDiff;
                numOps++;
            }
            else {
                break;
            }
        }
        return Math.max(0, numOps - 1);
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of(new int[]{5, 5, 8, 7}, 2),
                Arguments.of(new int[]{2, 4, 1}, 1),
                Arguments.of(new int[]{4, 4, 4, 4, 4}, 0));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(int[] boxes, long expected)
    {
        Assertions.assertEquals(expected, findMinimumOperations(boxes));
    }
}
