import java.util.ArrayList;
import java.util.List;

// LC-77
public class Combinations
{
    public List<List<Integer>> combine(int n, int k)
    {
        // cannot use TT style because number of variables (i.e., states) aren't known beforehand.
        List<List<Integer>> res = new ArrayList<>();
        combineHelper(n, k, res, new ArrayList<>());
        return res;
    }

    public void combineHelper(int n, int k, List<List<Integer>> res, List<Integer> element)
    {
        if (k == 0) {
            res.add(new ArrayList<>(element));
            return;
        }
        for (int i = n; i >= 1; i--) {
            element.add(i);
            combineHelper(i - 1, k - 1, res, element);
            element.remove(element.size() - 1);
        }
    }
}
