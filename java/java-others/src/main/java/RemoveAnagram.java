import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.stream.Stream;

import static java.util.Collections.sort;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/amazon-remove-anagram
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class RemoveAnagram
{
    public String[] removeAnagram(String[] textList)
    {
        List<String> candidates = new ArrayList<>();
        for (String text : textList) {
            boolean notFound = true;
            for (String candidate : candidates) {
                if (checkIfPermutation(text, candidate)) {
                    notFound = false;
                    break;
                }
            }
            if (notFound) {
                candidates.add(text);
            }
        }
        sort(candidates);
        return candidates.toArray(String[]::new);
    }

    private boolean checkIfPermutation(String name1, String name2)
    {
        if (name1.length() != name2.length()) {
            return false;
        }
        HashMap<Character, Integer> char2Count = new HashMap<>();
        for (int i = 0; i < name1.length(); ++i) {
            char2Count.putIfAbsent(name1.charAt(i), 0);
            char2Count.put(name1.charAt(i), char2Count.get(name1.charAt(i)) + 1);
        }
        HashMap<Character, Integer> char2Count2 = new HashMap<>();
        for (int i = 0; i < name2.length(); ++i) {
            char2Count2.putIfAbsent(name2.charAt(i), 0);
            char2Count2.put(name2.charAt(i), char2Count2.get(name2.charAt(i)) + 1);
        }
        return char2Count.equals(char2Count2);
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of(new String[]{"code", "doce", "ecod", "framer", "frame"}, new String[]{"code", "frame", "framer"}));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(String[] textList, String[] expected)
    {
        Assertions.assertArrayEquals(expected, removeAnagram(textList));
    }
}
