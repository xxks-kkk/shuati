import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/find-minimum-inefficiency
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class FindMinimumInefficiency
{
    /**
     * There are 3 possible patterns: ??, 1?, 0? where 1,0 are possible numbers.
     * We greedily fill 1? and 0? pattern to be 11 and 00 to minimize inefficiency.
     * Then, we process the temporary result again to eliminate the rest ?.
     */
    public int findMinimumInefficiency(String serverType)
    {
        int efficiency = 0;
        String result = helper(serverType, false);
        // In the 2nd pass, we should only observe 1?, 0? patterns; the special case is ?? which cannot be handled
        // in the 1st pass. As a result, we set it to be 00.
        String finalResult = helper(result, true);
        for (int i = 1; i < finalResult.length(); ++i) {
            if (finalResult.charAt(i - 1) != finalResult.charAt(i)) {
                efficiency += 1;
            }
        }
        return efficiency;
    }

    private String helper(String serverType, boolean eliminateAllQuestionMarks)
    {
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < serverType.length() - 1; ++i) {
            if (serverType.charAt(i) != '?' && serverType.charAt(i + 1) != '?') {
                builder.append(serverType.charAt(i));
            }
            else if (serverType.charAt(i) != '?' && serverType.charAt(i + 1) == '?') {
                builder.append(serverType.charAt(i));
            }
            else if (serverType.charAt(i) == '?' && serverType.charAt(i + 1) != '?') {
                builder.append(serverType.charAt(i + 1));
            }
            else if (serverType.charAt(i) == '?' && serverType.charAt(i + 1) == '?') {
                if (eliminateAllQuestionMarks) {
                    builder.append("0");
                }
                else {
                    builder.append(serverType.charAt(i));
                }
            }
        }
        return builder.toString();
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of("??011??0", 2),
                Arguments.of("00?10??1?", 3),
                Arguments.of("??", 0),
                Arguments.of("???", 0));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(String serverType, int expected)
    {
        Assertions.assertEquals(expected, findMinimumInefficiency(serverType));
    }
}
