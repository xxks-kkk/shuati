import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestGroupDivision
{
    private GroupDivision groupDivision;

    @BeforeAll
    public void setUp()
    {
        groupDivision = new GroupDivision();
    }

    private static Object[][] testGroupDivisionDataProvider()
    {
        return new Object[][] {
                {new int[] {1, 4, 7, 3, 4}, 2, 3},
                {new int[] {4, 8, 1, 7}, 3, 2},
                {new int[] {4, 1, 2, 5, 3}, 0, 5}
        };
    }

    @ParameterizedTest
    @MethodSource("testGroupDivisionDataProvider")
    public void testGroupDivision(int[] levels, int maxSpread, int expected)
    {
        assertEquals(expected, groupDivision.groupDivision(levels, maxSpread));
    }
}
