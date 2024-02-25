import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.Arrays;
import java.util.stream.Stream;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/get-max-reward-points
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class GetMaxRewardPoints
{
    public long getMaxRewardPoints(int[] reward)
    {
        int count = 0;
        int total = 0;
        Arrays.sort(reward);
        for (int i = reward.length - 1; i >= 0; i--) {
            if (reward[i] - count > 0) {
                total += reward[i] - count;
                count++;
            }
            else {
                break;
            }
        }
        return total;
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of(new int[]{5, 2, 2, 3, 1}, 7),
                Arguments.of(new int[]{5, 5, 5}, 12));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(int[] reward, long expected)
    {
        Assertions.assertEquals(expected, getMaxRewardPoints(reward));
    }
}
