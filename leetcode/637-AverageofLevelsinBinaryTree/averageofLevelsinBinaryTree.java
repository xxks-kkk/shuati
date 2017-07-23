/*          
 * [Source] 
 *          
 * https://leetcode.com/problems/average-of-levels-in-binary-tree/#/description
 *          
 * [Problem Description]
 *          
 * Given a non-empty binary tree, return the average value of the nodes on each
 * level in the form of an array.
 * 
 * Example 1:
 * 
 * Input:
 *   3
 *  / \
 * 9  20
 *   /  \
 *  15   7
 * Output: [3, 14.5, 11]
 * Explanation:
 * The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2
 * is 11. Hence return [3, 14.5, 11].
 * Note:
 * The range of node's value is in the range of 32-bit signed integer.
 *          
 * [Comments]
 * 
 * We use level-order traversal (BFS) in the solution.
 *
 * Time Complexity: O(n). The whole tree is traversed at most once. Here, n refers
 *                  to the number of nodes in the given binary tree.
 * Space Complexity: $O(m). The size of queue can grow upto atmost the maximum
 *                   number of nodes at any level in the given binary tree. Here,
 *                   m refers to the maximum number of nodes at any level in the 
 *                   input tree.         
 *
 * [Companies]
 */          

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
  public List<Double> averageOfLevels(TreeNode root)
  {
    List<Double> result = new ArrayList<>();
    Queue<TreeNode> q = new LinkedList<>();

    if (root == null) return result;
    q.add(root);
    while(!q.isEmpty())
    {
      int n = q.size(); // use of n is clear
      double sum = 0.0;
      for(int i = 0; i < n; i++)
      {
        TreeNode node = q.poll();
        sum+= node.val;
        if(node.left != null) q.offer(node.left);
        if(node.right != null) q.offer(node.right);
      }
      result.add(sum / n);
    }
    return result;
  } 
}
