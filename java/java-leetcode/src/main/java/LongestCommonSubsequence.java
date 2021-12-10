public class LongestCommonSubsequence
{
    /**
     * Solution that initialize DP table with dimension text1.length() * text2.length(),
     * which can be messy when we need to handle the base case: i = 0 or j = 0.
     */
    public int longestCommonSubsequence(String text1, String text2)
    {
        int[][] n = new int[text1.length()][text2.length()];
        n[0][0] = (text1.charAt(0) == text2.charAt(0)) ? 1 : 0;
        for (int j = 1; j < text2.length(); ++j) {
            // Remember, the max value for those entries is 1 and min value is 0.
            // Two test cases handled:
            // - {"aaa", "aaaa", 3},
            // - {"aba", "b", 1},
            n[0][j] = (n[0][j - 1] == 0) ? (text1.charAt(0) == text2.charAt(j)) ? 1 : 0 : 1;
        }
        for (int i = 1; i < text1.length(); ++i) {
            n[i][0] = (n[i - 1][0] == 0) ? (text1.charAt(i) == text2.charAt(0)) ? 1 : 0 : 1;
        }
        for (int i = 1; i < text1.length(); ++i) {
            for (int j = 1; j < text2.length(); ++j) {
                if (text1.charAt(i) == text2.charAt(j)) {
                    n[i][j] = n[i - 1][j - 1] + 1;
                }
                else {
                    n[i][j] = Math.max(n[i - 1][j], n[i][j - 1]);
                }
            }
        }
        return n[text1.length() - 1][text2.length() - 1];
    }

    /**
     * Solution that initialize DP table with dimension (text1.length()+1) * (text2.length()+1)
     * to avoid the hurdle of handling the base case: i = 0 or j = 0.
     */
    public int longestCommonSubsequence2(String text1, String text2)
    {
        int[][] n = new int[text1.length() + 1][text2.length() + 1];
        for (int i = 1; i < text1.length() + 1; ++i) {
            for (int j = 1; j < text2.length() + 1; ++j) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    n[i][j] = n[i - 1][j - 1] + 1;
                }
                else {
                    n[i][j] = Math.max(n[i - 1][j], n[i][j - 1]);
                }
            }
        }
        return n[text1.length()][text2.length()];
    }

    /**
     * Space optimized version which we only keep dp table
     * with dimension 2 * (text2.length()+1). The space can
     * even be reduced more. See:
     * - https://leetcode.com/problems/longest-common-subsequence/discuss/351689/JavaPython-3-Two-DP-codes-of-O(mn)-and-O(min(m-n))-spaces-w-picture-and-analysis
     */
    public int longestCommonSubsequence3(String text1, String text2)
    {
        int[][] n = new int[2][text2.length() + 1];
        for (int i = 1; i < text1.length() + 1; ++i) {
            for (int j = 1; j < text2.length() + 1; ++j) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    n[i % 2][j] = n[(i - 1) % 2][j - 1] + 1;
                }
                else {
                    n[i % 2][j] = Math.max(n[(i - 1) % 2][j], n[i % 2][j - 1]);
                }
            }
        }
        return n[text1.length() % 2][text2.length()];
    }
}
