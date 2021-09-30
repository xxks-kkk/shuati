import java.util.HashMap;
import java.util.Map;

// LC-1
public class TwoSum
{
    private TwoSum() {}

    // We use a dictionary ADT (hash map) that contains <idx, value> pairs
    // to reduce the look up time of a value to O(1).
    public static int[] twoSum(int[] numbers, int target)
    {
        Map<Integer, Integer> dict = new HashMap<>();
        for (int i = 0; i < numbers.length; i++) {
            int x = numbers[i];
            if (dict.containsKey(target - x)) {
                return new int[] {dict.get(target - x), i};
            }
            dict.put(x, i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
