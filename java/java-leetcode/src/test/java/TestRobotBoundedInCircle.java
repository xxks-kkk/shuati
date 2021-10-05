import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestRobotBoundedInCircle
{
    private RobotBoundedInCircle robotBoundedInCircle;

    @BeforeAll
    public void setUp()
    {
        robotBoundedInCircle = new RobotBoundedInCircle();
    }

    private static Object[][] testMaximumAverageSubtreeDataProvider()
    {
        return new Object[][] {
                {"RRGRRGLLLRLGGLGLLGRLRLGLRLRRGLGGLLRRRLRLRLLGRGLGRRRGRLG", false},
                {"GGR", true}
        };
    }

    @ParameterizedTest
    @MethodSource("testMaximumAverageSubtreeDataProvider")
    public void testMaximumAverageSubtree(String instructions, boolean expectation)
    {
        assertEquals(expectation, robotBoundedInCircle.isRobotBounded(instructions));
    }
}
