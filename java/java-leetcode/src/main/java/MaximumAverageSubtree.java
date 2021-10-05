// LC-1120: https://leetcode.ca/all/1120.html
public class MaximumAverageSubtree
{
    private double maximum;

    public double maximumAverageSubtree(TreeNode root)
    {
        maximumAverageSubtreeHelper(root);
        return maximum;
    }

    /**
     * @return double[]: 1st element is number of nodes; 2nd element is subtree sum
     */
    private double[] maximumAverageSubtreeHelper(TreeNode root)
    {
        if (root == null) {
            return new double[] {0, 0};
        }
        double[] left = maximumAverageSubtreeHelper(root.left);
        double[] right = maximumAverageSubtreeHelper(root.right);
        double sum = root.val + left[1] + right[1];
        double numNodes = 1 + left[0] + right[0];
        double average = sum / numNodes;
        if (average > maximum) {
            maximum = average;
        }
        return new double[] {numNodes, sum};
    }
}
