import org.junit.Ignore;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.stream.Stream;

/**
 * Amazon Intern 24' (actual)
 * cannot pass all the test cases.
 */
@Ignore
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class FindMinClicks
{
    public int findMinClicks(String letters)
    {
        int count = 0;
        int numCharactersProcessed = 0;
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < letters.length(); i++) {
            map.putIfAbsent(letters.charAt(i), 0);
            map.put(letters.charAt(i), map.get(letters.charAt(i)) + 1);
        }
        LinkedHashMap<Character, Integer> sortedMap = new LinkedHashMap<>();
        map.entrySet().stream().sorted((k1, k2) -> -k1.getValue().compareTo(k2.getValue())).forEach(k -> sortedMap.put(k.getKey(), k.getValue()));
        for (Character s : sortedMap.keySet()) {
            if (numCharactersProcessed < 9) {
                count += sortedMap.get(s);
                numCharactersProcessed++;
            }
            else {
                numCharactersProcessed++;
                count += (sortedMap.get(s) * (1 + numCharactersProcessed / 9));
            }
        }
        return count;
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of("aaaaaa", 6),
                Arguments.of("abcghdiefjoba", 15),
                Arguments.of("aabbccddeeffgghhiijj", 22),
                Arguments.of("abcdefghijlmnopqrstuvwxyz", 48));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(String letters, int expected)
    {
        Assertions.assertEquals(expected, findMinClicks(letters));
    }
}
