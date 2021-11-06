import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.MethodSource;

import static org.junit.jupiter.api.Assertions.assertEquals;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestMeetingRoomsII
{
    private MeetingRoomsII meetingRoomsII;

    @BeforeAll
    public void setUp()
    {
        meetingRoomsII = new MeetingRoomsII();
    }

    private static Object[][] testMeetingRoomsIIDataProvider()
    {
        return new Object[][] {
                {new int[][] {{0, 30}, {5, 10}, {15, 20}}, 2},
                {new int[][] {{7, 10}, {2, 4}}, 1}
        };
    }

    @ParameterizedTest
    @MethodSource("testMeetingRoomsIIDataProvider")
    public void testMeetingRoomsII(int[][] intervals, int expectation)
    {
        assertEquals(expectation, meetingRoomsII.meetingRoomsII(intervals));
    }
}
