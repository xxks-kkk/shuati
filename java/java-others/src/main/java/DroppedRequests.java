import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.List;
import java.util.stream.Stream;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/amazon-dropped-requests
 * Ref: https://hackmd.io/@mizugakun/H1mA50BZY
 * Ref: https://leetcode.com/discuss/interview-question/518083/citrix-oa-2020-evaluating-circuit-expressions-throttling-gateway-computing-cluster-quality
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class DroppedRequests
{
    public int droppedRequests(List<Integer> requestTime)
    {
        int cnt = 0;
        for (int i = 0; i < requestTime.size(); i++) {
            // The number of transactions in any given second cannot exceed 3
            if (i > 2 && requestTime.get(i).equals(requestTime.get(i - 3))) {
                cnt++;
            }
            // 20 requests limit within 10 seconds
            else if (i > 19 && requestTime.get(i) - requestTime.get(i - 20) < 10) {
                cnt++;
            }
            // 60 requests limit within 60 seconds
            else if (i > 59 && requestTime.get(i) - requestTime.get(i - 60) < 60) {
                cnt++;
            }
        }
        return cnt;
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of(List.of(1, 1, 1, 1, 2), 1),
                Arguments.of(List.of(1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7), 2),
                // I think it's should be 5 instead of 7
                Arguments.of(List.of(1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 7, 7, 7, 7, 11, 11, 11, 11), 5),
                Arguments.of(List.of(1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 11, 11, 11), 1));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(List<Integer> requestTime, int expected)
    {
        Assertions.assertEquals(expected, droppedRequests(requestTime));
    }
}
