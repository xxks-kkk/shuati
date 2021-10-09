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
}
