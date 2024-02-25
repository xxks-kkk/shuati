import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.TestInstance;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.Arguments;
import org.junit.jupiter.params.provider.MethodSource;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

/**
 * Amazon Intern 24'
 * https://www.fastprep.io/problems/check-similar-passwords
 */
@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class CheckSimilarPasswords
{
    public String[] checkSimilarPasswords(String[] newPasswords, String[] oldPasswords)
    {
        List<String> candidates = new ArrayList<>();
        for (int i = 0; i < newPasswords.length; ++i) {
            if (compare(newPasswords[i], oldPasswords[i])) {
                candidates.add("YES");
            }
            else {
                candidates.add("NO");
            }
        }
        return candidates.toArray(new String[0]);
    }

    private boolean compare(String newPassword, String oldPassword)
    {
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < newPassword.length(); i++) {
            if (newPassword.charAt(i) != 'z') {
                builder.append((char) (newPassword.charAt(i) + 1));
            }
            else {
                builder.append('a');
            }
        }
        String newPassword2 = builder.toString();
        int oldPassWordCharIdx = 0;
        for (int i = 0; i < newPassword.length(); ++i) {
            if (newPassword.charAt(i) == oldPassword.charAt(oldPassWordCharIdx) ||
                    newPassword2.charAt(i) == oldPassword.charAt(oldPassWordCharIdx)) {
                oldPassWordCharIdx++;
                if (oldPassWordCharIdx == oldPassword.length()) {
                    break;
                }
            }
        }
        return oldPassWordCharIdx == oldPassword.length();
    }

    private Stream<Arguments> testDataProvider()
    {
        return Stream.of(
                Arguments.of(new String[]{"baacbab", "accdb", "baacba"}, new String[]{"abdbc", "ach", "abb"}, new String[]{"YES", "NO", "YES"}),
                Arguments.of(new String[]{"aaccbbee", "aab"}, new String[]{"bdbf", "aee"}, new String[]{"YES", "NO"}));
    }

    @ParameterizedTest
    @MethodSource("testDataProvider")
    public void test(String[] newPasswords, String[] oldPasswords, String[] expected)
    {
        Assertions.assertArrayEquals(expected, checkSimilarPasswords(newPasswords, oldPasswords));
    }
}
