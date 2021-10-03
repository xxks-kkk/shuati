import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

// LC-1120: https://leetcode.ca/all/1120.html
public class MaximumAverageSubtree
{
    private double maximum = 0.0;

    public double maximumAverageSubtree(TreeNode root) {
        maximumAverageSubtreeHelper(root);
        return maximum;
    }

    private Pair maximumAverageSubtreeHelper(TreeNode root) {
        if (root == null) {
            return new Pair(0, 1);
        }
        else if (root.left == null && root.right == null) {
            if ((double) root.val > maximum) {
                maximum = root.val;
            }
            return new Pair(1, root.val);
        }
        else {
            int sum = root.val;
            int numNodes = 1;
            if (root.left != null) {
                Pair pair = maximumAverageSubtreeHelper(root.left);
                sum += pair.value;
                numNodes += pair.key;
            }
            if (root.right != null) {
                Pair pair = maximumAverageSubtreeHelper(root.right);
                sum += pair.value;
                numNodes += pair.key;
            }
            double average = sum / (double) numNodes;
            if (average > maximum) {
                maximum = average;
            }
            return new Pair(numNodes, sum);
        }
    }
}
