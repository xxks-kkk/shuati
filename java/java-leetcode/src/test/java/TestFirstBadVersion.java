import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class TestFirstBadVersion
{
    private FirstBadVersion firstBadVersion;

    private static Object[][] testFirstBadVersionDataProvider()
    {
        return new Object[][] {
                {5, 4},
                {1, 1}
        };
    }

    @ParameterizedTest
    @MethodSource("testFirstBadVersionDataProvider")
    public void testFirstBadVersion(int n, int expectation)
    {
        firstBadVersion = new FirstBadVersion(expectation);
        assertEquals(expectation, firstBadVersion.firstBadVersion(n));
    }
}
