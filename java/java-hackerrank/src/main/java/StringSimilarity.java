// https://www.hackerrank.com/challenges/string-similarity/problem
public class StringSimilarity
{
    public int stringSimilarity(String s)
    {
        int sum = s.length();
        for (int i = 1; i < s.length(); ++i) {
            String subS = s.substring(i);
            if (subS.charAt(0) == s.charAt(0)) {
                for (int j = 0; j < subS.length(); ++j) {
                    if (subS.charAt(j) == s.charAt(j)) {
                        sum++;
                    }
                    else {
                        break;
                    }
                }
            }
        }
        return sum;
    }
}
