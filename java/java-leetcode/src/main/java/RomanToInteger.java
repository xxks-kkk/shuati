import java.util.HashMap;

//LC-13
public class RomanToInteger
{
    public int romanToInt(String s)
    {
        int res = 0;
        HashMap<Character, Integer> lookUp = new HashMap<>();
        lookUp.put('I', 1);
        lookUp.put('V', 5);
        lookUp.put('X', 10);
        lookUp.put('L', 50);
        lookUp.put('C', 100);
        lookUp.put('D', 500);
        lookUp.put('M', 1000);
        for (int i = 0; i < s.length(); ++i) {
            char cur = s.charAt(i);
            char ahead = (i < s.length() - 1) ? s.charAt(i + 1) : ' ';
            if ((cur == 'I' && ahead == 'V') ||
                    (cur == 'I' && ahead == 'X') ||
                    (cur == 'X' && ahead == 'L') ||
                    (cur == 'X' && ahead == 'C') ||
                    (cur == 'C' && ahead == 'D') ||
                    (cur == 'C' && ahead == 'M')) {
                res += (lookUp.get(ahead) - lookUp.get(cur));
                i++;
            }
            else {
                res += lookUp.get(cur);
            }
        }
        return res;
    }
}
