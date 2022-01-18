import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class TreeNode
{
    int val;
    TreeNode left;
    TreeNode right;

    public TreeNode(int val)
    {
        this.val = val;
        this.left = null;
        this.right = null;
    }

    public TreeNode(int val, TreeNode left, TreeNode right)
    {
        this.val = val;
        this.left = left;
        this.right = right;
    }

    /**
     * Convert given list of numbers into a binary tree. The numbers
     * in the list are assumed to be ordered by level-order traversal.
     *
     * @return the root of the binary tree
     */
    public static TreeNode list2Tree(List<Integer> nums)
    {
        if (!nums.isEmpty()) {
            Queue<TreeNode> queue = new LinkedList<>();
            TreeNode root = new TreeNode(nums.get(0));
            queue.add(root);
            int i = 1;
            while (!queue.isEmpty() && i < nums.size()) {
                TreeNode node = queue.poll();
                if (node == null) {
                    continue;
                }
                TreeNode left = nums.get(i) == null ? null : new TreeNode(nums.get(i));
                queue.add(left);
                node.left = left;
                i++;
                if (i < nums.size()) {
                    TreeNode right = new TreeNode(nums.get(i));
                    queue.add(right);
                    node.right = right;
                }
                i++;
            }
            return root;
        }
        return null;
    }
}
