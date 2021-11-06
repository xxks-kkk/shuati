import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestStringSimilarity
{
    private StringSimilarity stringSimilarity;

    @BeforeAll
    public void setUp()
    {
        stringSimilarity = new StringSimilarity();
    }

    private static Object[][] testStringSimilarityDataProvider()
    {
        return new Object[][] {
                {"ababaa", 11},
                {"aa", 3},
                {"edbbaacdcaacacbababaabadeeeaaddecaaeceeecbdcdaeacaccccaddeaaddecdcdcdccadcacceeecdcbceecebde", 110}
        };
    }

    @ParameterizedTest
    @MethodSource("testStringSimilarityDataProvider")
    public void testStringSimilarity(String s, int expectation)
    {
        assertEquals(expectation, stringSimilarity.stringSimilarity(s));
    }
}
