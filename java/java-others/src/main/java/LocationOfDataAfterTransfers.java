import com.google.common.primitives.Ints;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.stream.Stream;

import static java.util.Arrays.sort;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/location-of-data-after-transfers
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class LocationOfDataAfterTransfers
{
    public int[] locationOfDataAfterTransfers(int[] locations, int[] movedFrom, int[] movedTo)
    {
        List<Integer> candidates = new ArrayList<>();
        HashMap<Integer, Integer> from2To = new HashMap<>();
        for (int i = 0; i < movedFrom.length; ++i) {
            from2To.put(movedFrom[i], movedTo[i]);
        }
        // As shown in the second test case where movedFrom [1,4,5,7]; Once 5 move to 1, we cannot ``traverse back" by
        // moving from 1 to 4 again. Thus, directly following from2To map without additional index check won't work.
        HashMap<Integer, Integer> from2Idx = new HashMap<>();
        for (int i = 0; i < movedFrom.length; ++i) {
            from2Idx.put(movedFrom[i], i);
        }
        for (int i = 0; i < locations.length; ++i) {
            int loc = locations[i];
            while (from2To.containsKey(loc)) {
                loc = from2To.get(loc);
                if (!from2Idx.containsKey(loc) || from2Idx.get(loc) < i) {
                    break;
                }
            }
            candidates.add(loc);
        }
        int[] ret = Ints.toArray(candidates);
        sort(ret);
        return ret;
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of(new int[]{1, 7, 6, 8}, new int[]{1, 7, 2}, new int[]{2, 9, 5}, new int[]{5, 6, 8, 9}),
                Arguments.of(new int[]{1, 5, 2, 6}, new int[]{1, 4, 5, 7}, new int[]{4, 7, 1, 3}, new int[]{1, 2, 3, 6}),
                Arguments.of(new int[]{1, 2, 3}, new int[]{1, 2}, new int[]{5, 6}, new int[]{3, 5, 6}));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(int[] locations, int[] movedFrom, int[] movedTo, int[] expected)
    {
        Assertions.assertArrayEquals(expected, locationOfDataAfterTransfers(locations, movedFrom, movedTo));
    }
}
