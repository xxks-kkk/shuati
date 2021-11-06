import java.util.Arrays;
import java.util.Comparator;

// LC-253
// https://leetcode.ca/all/253.html
public class MeetingRoomsII
{
    public int meetingRoomsII(int[][] intervals)
    {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        int numMeetingRooms = 1;
        // tracks which meeting finishes first in the existing on-going meetings.
        int minEndTime = intervals[0][1];
        for (int i = 2; i < intervals.length; i++) {
            int[] interval = intervals[i];
            if (interval[0] < minEndTime) {
                // if the upcoming meeting happens earlier than the on-going meeting that ends earliest,
                // we're short of meeting rooms.
                numMeetingRooms++;
                minEndTime = Math.min(minEndTime, interval[1]);
            }
        }
        return numMeetingRooms;
    }
}
