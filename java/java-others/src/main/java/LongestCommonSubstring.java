// Dremio 2021 Intern
public class LongestCommonSubstring
{
    public int longestCommonSubstring(String text1, String text2)
    {
        int[][] n = new int[text1.length() + 1][text2.length() + 1];
        int max = 0;
        for (int i = 1; i < text1.length() + 1; ++i) {
            for (int j = 1; j < text2.length() + 1; ++j) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    n[i][j] = n[i - 1][j - 1] + 1;
                    max = Math.max(max, n[i][j]);
                }
                else {
                    n[i][j] = 0;
                }
            }
        }
        return max;
    }
}
