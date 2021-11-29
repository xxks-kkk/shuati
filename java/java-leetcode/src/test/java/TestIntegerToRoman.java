import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestIntegerToRoman
{
    private IntegerToRoman integerToRoman;

    @BeforeAll
    public void setUp()
    {
        integerToRoman = new IntegerToRoman();
    }

    private static Object[][] testIntegerToRomanDataProvider() {
        return new Object[][] {
                {3, "III"},
                {4, "IV"},
                {9, "IX"},
                {58, "LVIII"}
        };
    }

    @ParameterizedTest
    @MethodSource("testIntegerToRomanDataProvider")
    public void testIntegerToRoman(int num, String expectation) {
        assertEquals(integerToRoman.intToRoman(num), expectation);
    }
}
