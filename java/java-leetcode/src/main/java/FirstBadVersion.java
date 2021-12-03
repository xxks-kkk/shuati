// LC-278
public class FirstBadVersion
        extends VersionControl
{
    public FirstBadVersion(int bad)
    {
        super(bad);
    }

    public int firstBadVersion(int n)
    {
        int leftptr = 1;
        int rightptr = n;
        while (leftptr < rightptr) {
            int mid = leftptr + (rightptr - leftptr) / 2;
            if (isBadVersion(mid)) {
                rightptr = mid;
            }
            else {
                leftptr = mid + 1;
            }
        }
        return leftptr;
    }

    // This version is more intuitive as the first attempt
    public int firstBadVersion2(int n)
    {
        int leftptr = 1;
        int rightptr = n;
        while (leftptr < rightptr) {
            if (isBadVersion(leftptr)) { // redundant vs. firstBadVersion
                return leftptr;          // redundant vs. firstBadVersion
            }                            // redundant vs. firstBadVersion
            int mid = leftptr + (rightptr - leftptr) / 2;
            if (isBadVersion(mid)) {
                rightptr = mid;
                leftptr += 1;             // redundant vs. firstBadVersion
            }
            else {
                leftptr = mid + 1;
            }
        }
        return leftptr;
    }
}
