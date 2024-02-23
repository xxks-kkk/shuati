import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/amazon-get-longest-match
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class GetLongestMatch
{
    public int getLongestMatch(String text, String regex)
    {
        String[] parts = regex.split("\\*");
        if (parts.length == 0) {
            return text.length();
        }
        List<Integer> startIdxes = getAllOccurences(parts[0], text);
        List<Integer> endIdxes = getAllOccurences(parts[1], text);
        int maxVal = -1;
        for (int startIdx : startIdxes) {
            for (int endIdx : endIdxes) {
                if (endIdx - startIdx + 1 > maxVal) {
                    maxVal = endIdx - startIdx + 1;
                }
            }
        }
        return maxVal;
    }

    private List<Integer> getAllOccurences(String pattern, String target)
    {
        List<Integer> ret = new ArrayList<>();
        int idx = target.indexOf(pattern);
        while (idx >= 0) {
            ret.add(idx);
            idx = target.indexOf(pattern, idx + 1);
        }
        return ret;
    }

    public int getLongestMatch2(String text, String regex)
    {
        String[] parts = regex.split("\\*");
        if (parts.length == 0) {
            return text.length();
        }
        int left = 0;
        int right = text.length();
        while (left + parts[0].length() <= right - parts[1].length()) {
            if (!text.substring(left, left + parts[0].length()).equals(parts[0])) {
                left += 1;
            }
            else if (!text.substring(right - parts[1].length(), right).equals(parts[1])) {
                right--;
            }
            else {
                return right - left;
            }
        }
        return -1;
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of("hackerrank", "ack*r", 6),
                Arguments.of("hackerrank", "*", 10),
                Arguments.of("ghabcghabbc", "gh*c", 11));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(String text, String regex, int expected)
    {
        Assertions.assertEquals(expected, getLongestMatch(text, regex));
        Assertions.assertEquals(expected, getLongestMatch2(text, regex));
    }
}
