import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/count-games-won-by-group1
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class CountGamesWonByGroup1
{
    public int countGamesWonByGroup1(int n, int[] group1, int[] group2)
    {
        int count = 0;
        for (int i = 0; i < group1.length; ++i) {
            for (int j = i + 1; j < group1.length; ++j) {
                if (group1[i] + group1[j] > group2[i] + group2[j]) {
                    count++;
                }
            }
        }
        return count % (10 ^ 9 + 7);
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of(3, new int[]{1, 2, 3}, new int[]{3, 2, 1}, 1));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(int n, int[] group1, int[] group2, int expected)
    {
        Assertions.assertEquals(expected, countGamesWonByGroup1(n, group1, group2));
    }
}
