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
 * https://www.fastprep.io/problems/amazon-find-recurring-names
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class FindRecurringNames
{
    public String[] findRecurringNames(String[] realNames, String[] allNames)
    {
        HashMap<String, Integer> realName2Count = new HashMap<>();
        for (String realName : realNames) {
            for (String name : allNames) {
                realName2Count.putIfAbsent(realName, 0);
                if (checkIfPermutation(realName, name)) {
                    realName2Count.put(realName, realName2Count.get(realName) + 1);
                }
            }
        }
        List<String> candidates = new ArrayList<>();
        for (String realName : realName2Count.keySet()) {
            if (realName2Count.get(realName) >= 2) {
                candidates.add(realName);
            }
        }
        if (candidates.isEmpty()) {
            return new String[]{"None"};
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
        return Stream.of(Arguments.of(new String[]{"rohn", "henry", "daisy"},
                        new String[]{"ryhen", "aisyd", "henry"},
                        new String[]{"henry"}),
                Arguments.of(new String[]{"tom", "jerry"},
                        new String[]{"reyjr", "mot", "tom", "jerry", "mto"},
                        new String[]{"jerry", "tom"}));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(String[] realNames, String[] allNames, String[] expected)
    {
        Assertions.assertArrayEquals(expected, findRecurringNames(realNames, allNames));
    }
}
