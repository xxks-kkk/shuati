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
            int len = Math.min(a.size(), b.size());
            for (int i = 0; i < len; ++i) {
                if (!Objects.equals(a.get(0), b.get(0))) {
                    return a.get(i) - b.get(i);
                }
            }
            return a.get(len - 1) - b.get(len - 1);
        });
        expectation.sort((a, b) -> {
            int len = Math.min(a.size(), b.size());
            for (int i = 0; i < len; ++i) {
                if (!Objects.equals(a.get(0), b.get(0))) {
                    return a.get(i) - b.get(i);
                }
            }
            return a.get(len - 1) - b.get(len - 1);
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
