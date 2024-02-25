import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

import static java.util.Arrays.sort;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/amz-get-score-difference
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class GetScoreDifference
{
    public long getScoreDifference(int n, int[] points)
    {
        sort(points);
        long player1 = 0;
        long player2 = 0;
        for (int i = points.length - 1; i >= 0; i--) {
            if (i % 2 == 0) {
                player1 += points[i];
            }
            else {
                player2 += points[i];
            }
        }
        return Math.abs(player1 - player2);
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of(4, new int[]{4, 1, 2, 3}, 2),
                Arguments.of(4, new int[]{4, 1, 1, 4}, 0));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(int n, int[] points, long expected)
    {
        Assertions.assertEquals(expected, getScoreDifference(n, points));
    }
}
