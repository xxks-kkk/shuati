import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestLongestCommonSubstring
{
    private LongestCommonSubstring longestCommonSubstring;

    @BeforeAll
    public void setUp()
    {
        longestCommonSubstring = new LongestCommonSubstring();
    }

    private static Object[][] testLongestCommonSubstringDataProvider()
    {
        return new Object[][] {
                {"abcde", "ace", 1},
                {"abc", "abc", 3},
                {"abc", "def", 0},
                {"aaa", "aaaa", 3},
                {"aba", "b", 1},
                {"abcd", "abeabcf", 3},
                {"abed", "abcd", 2},
                {"abed", "bbed", 3}
        };
    }

    @ParameterizedTest
    @MethodSource("testLongestCommonSubstringDataProvider")
    public void testLongestCommonSubstring(String text1, String text2, int expectation)
    {
        assertEquals(expectation, longestCommonSubstring.longestCommonSubstring(text1, text2));
    }
}
