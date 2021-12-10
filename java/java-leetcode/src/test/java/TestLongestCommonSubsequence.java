import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestLongestCommonSubsequence
{
    private LongestCommonSubsequence longestCommonSubsequence;

    @BeforeAll
    public void setUp()
    {
        longestCommonSubsequence = new LongestCommonSubsequence();
    }

    private static Object[][] testLongestCommonSubsequenceDataProvider()
    {
        return new Object[][] {
                {"abcde", "ace", 3},
                {"abc", "abc", 3},
                {"abc", "def", 0},
                {"aaa", "aaaa", 3},
                {"aba", "b", 1},
        };
    }

    @ParameterizedTest
    @MethodSource("testLongestCommonSubsequenceDataProvider")
    public void testLongestCommonSubsequence(String text1, String text2, int expectation)
    {
        assertEquals(expectation, longestCommonSubsequence.longestCommonSubsequence(text1, text2));
    }

    @ParameterizedTest
    @MethodSource("testLongestCommonSubsequenceDataProvider")
    public void testLongestCommonSubsequence2(String text1, String text2, int expectation)
    {
        assertEquals(expectation, longestCommonSubsequence.longestCommonSubsequence2(text1, text2));
    }

    @ParameterizedTest
    @MethodSource("testLongestCommonSubsequenceDataProvider")
    public void testLongestCommonSubsequence3(String text1, String text2, int expectation)
    {
        assertEquals(expectation, longestCommonSubsequence.longestCommonSubsequence3(text1, text2));
    }
}
