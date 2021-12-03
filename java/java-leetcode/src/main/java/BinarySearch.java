// LC-704
public class BinarySearch
{
    public int search(int[] nums, int target)
    {
        int leftptr = 0;
        int rightptr = nums.length;
        // invariant: target \in [leftptr, rightptr)
        while (leftptr < rightptr) {
            int mid = leftptr + (rightptr - leftptr) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                leftptr = mid + 1;
            }
            else {
                rightptr = mid;
            }
        }
        return -1;
    }
}
