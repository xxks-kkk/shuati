import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.Arrays;
import java.util.stream.Stream;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/get-min-cost-data
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class MinimalCostDataInterpolation
{
    public String getMinCostData(String data)
    {
        StringBuilder builder = new StringBuilder();
        int[] charAppearanceIndx = new int[26];
        for (int i = 0; i < data.length(); ++i) {
            char ch = data.charAt(i);
            if (ch != '?') {
                charAppearanceIndx[ch - 'a'] = 1;
                builder.append(ch);
            }
            else {
                if (Arrays.stream(charAppearanceIndx).sum() == 26) {
                    charAppearanceIndx = new int[26];
                }
                for (int j = 0; j < charAppearanceIndx.length; ++j) {
                    if (charAppearanceIndx[j] == 0) {
                        builder.append((char) ('a' + j));
                        charAppearanceIndx[j] = 1;
                        break;
                    }
                }
            }
        }
        return builder.toString();
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(Arguments.of("aaaa?aaaa", "aaaabaaaa"),
                Arguments.of("??????", "abcdef"),
                Arguments.of("abcd?", "abcde"),
                Arguments.of("abcdefghijklmnopqrstuvwxyz?", "abcdefghijklmnopqrstuvwxyza"));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(String data, String expected)
    {
        Assertions.assertEquals(expected, getMinCostData(data));
    }
}
