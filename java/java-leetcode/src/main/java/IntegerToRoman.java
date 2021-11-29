import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;

// LC-12
public class IntegerToRoman
{
    public String intToRoman(int num)
    {
        StringBuffer res = new StringBuffer();
        LinkedHashMap<Integer, String> lookUp = new LinkedHashMap<>();
        lookUp.put(1000, "M");
        lookUp.put(900, "CM");
        lookUp.put(500, "D");
        lookUp.put(400, "CD");
        lookUp.put(100, "C");
        lookUp.put(90, "XC");
        lookUp.put(50, "L");
        lookUp.put(40, "XL");
        lookUp.put(10, "X");
        lookUp.put(9, "IX");
        lookUp.put(5, "V");
        lookUp.put(4, "IV");
        lookUp.put(1, "I");
        List<Integer> keys = new ArrayList<>(lookUp.keySet());
        for (Integer key : keys) {
            for (int i = 0; i < num / key; i++) {
                res.append(lookUp.get(key));
            }
            num = num % key;
            if (num == 0) {
                break;
            }
        }
        return res.toString();
    }
}
