import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.stream.Stream;

import static java.util.Arrays.sort;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/amazon-group-students
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class GroupStudents
{
    public int groupStudents(int[] levels, int maxSpread)
    {
        sort(levels);
        int numGroups = 1;
        int currMin = levels[0];
        for (int level : levels) {
            if (level - currMin > maxSpread) {
                numGroups += 1;
                currMin = level;
            }
        }
        return numGroups;
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(Arguments.of(new int[]{1, 4, 7, 3, 4}, 2, 3));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(int[] levels, int maxSpread, int expected)
    {
        Assertions.assertEquals(expected, groupStudents(levels, maxSpread));
    }
}
