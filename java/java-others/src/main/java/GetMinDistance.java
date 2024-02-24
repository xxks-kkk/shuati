import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

import static java.util.Arrays.sort;

/*
 Amazon Intern 24'
 https://www.fastprep.io/problems/get-min-distance
 https://www.1point3acres.com/bbs/thread-1045986-1-1.html
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class GetMinDistance
{
    public long getMinDistance(int[] center, int[] destination)
    {
        sort(center);
        sort(destination);
        int distance = 0;
        for (int i = 0; i < center.length; i++) {
            distance += Math.abs(center[i] - destination[i]);
        }
        return distance;
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of(new int[]{1, 2, 2}, new int[]{5, 2, 4}, 6),
                Arguments.of(new int[]{3, 1, 6, 8, 9}, new int[]{2, 3, 1, 7, 9}, 5));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(int[] center, int[] destination, int expected)
    {
        Assertions.assertEquals(expected, getMinDistance(center, destination));
    }
}
