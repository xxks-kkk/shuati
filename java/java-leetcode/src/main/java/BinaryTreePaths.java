import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

// LC-257
public class BinaryTreePaths
{
    public List<String> binaryTreePaths(TreeNode root)
    {
        List<List<String>> tmpRes = new ArrayList<>();
        traverse(root, new ArrayList<>(), tmpRes);
        return tmpRes.stream().map(u -> String.join("->", u)).collect(Collectors.toList());
    }

    private void traverse(TreeNode node, List<String> tmp, List<List<String>> tmpRes)
    {
        tmp.add(node.val + "");
        if (node.left == null && node.right == null) {
            tmpRes.add(new ArrayList<>(tmp));
            return;
        }
        if (node.left != null) {
            traverse(node.left, tmp, tmpRes);
            tmp.remove(tmp.size() - 1);
        }
        if (node.right != null) {
            traverse(node.right, tmp, tmpRes);
            tmp.remove(tmp.size() - 1);
        }
    }
}
