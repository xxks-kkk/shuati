import java.util.Comparator;
import java.util.List;
import java.util.Objects;

public class Utils
{
    private Utils() {}

    public static boolean arrayEquals(int[] nums1, int[] nums2)
    {
        if (nums1.length != nums2.length) {
            return false;
        }
        for (int i = 0; i < nums1.length; ++i) {
            if (nums1[i] != nums2[i]) {
                return false;
            }
        }
        return true;
    }

    public static boolean checkListOfList(List<List<Integer>> ret, List<List<Integer>> expectation)
    {
        if (expectation.size() != ret.size()) {
            return false;
        }

        for (int i = 0; i < ret.size(); ++i) {
            ret.get(i).sort(Comparator.comparingInt(a -> a));
            expectation.get(i).sort(Comparator.comparingInt(a -> a));
        }
        ret.sort((a, b) -> {
            if (!Objects.equals(a.get(0), b.get(0))) {
                return a.get(0) - b.get(0);
            }
            else if (!Objects.equals(a.get(1), b.get(1))) {
                return a.get(1) - b.get(1);
            }
            else {
                return a.get(2) - b.get(2);
            }
        });
        expectation.sort((a, b) -> {
            if (!Objects.equals(a.get(0), b.get(0))) {
                return a.get(0) - b.get(0);
            }
            else if (!Objects.equals(a.get(1), b.get(1))) {
                return a.get(1) - b.get(1);
            }
            else {
                return a.get(2) - b.get(2);
            }
        });
        for (int i = 0; i < ret.size(); ++i) {
            if (expectation.get(i).size() != ret.get(i).size()) {
                return false;
            }
            for (int j = 0; j < ret.get(i).size(); ++j) {
                if (!Objects.equals(expectation.get(i).get(j), ret.get(i).get(j))) {
                    return false;
                }
            }
        }
        return true;
    }
}
