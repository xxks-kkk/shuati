import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestRomanToInteger
{
    private RomanToInteger romanToInteger;

    @BeforeAll
    public void setUp()
    {
        romanToInteger = new RomanToInteger();
    }

    private static Object[][] testRomanToIntegerDataProvider()
    {
        return new Object[][] {
                {"III", 3},
                {"IV", 4},
                {"IX", 9},
                {"LVIII", 58},
                {"MCMXCIV", 1994}
        };
    }

    @ParameterizedTest
    @MethodSource("testRomanToIntegerDataProvider")
    public void testRomanToInteger(String s, int expectation)
    {
        assertEquals(expectation, romanToInteger.romanToInt(s));
    }
}
