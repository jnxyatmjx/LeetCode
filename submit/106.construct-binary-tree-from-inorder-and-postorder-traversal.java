/*
 * @lc app=leetcode id=106 lang=java
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
  if (inorder == null || postorder == null) return null;
  return buildTree(inorder, postorder, 0, inorder.length - 1, 0, postorder.length - 1);
}

public TreeNode buildTree(int[] inorder, int[] postorder, int is, int ie, int ps, int pe) {
  if (ps > pe) return null;
  TreeNode root = new TreeNode(postorder[pe]);
  int pos = is;
  for (; pos <= ie; pos++) {
    if (inorder[pos] == root.val) break;
  }
  // Note how to calcuclate the start and end indices for post array
  root.left  = buildTree(inorder, postorder, is, pos - 1, ps, ps - is - 1 + pos);
  root.right = buildTree(inorder, postorder, pos + 1, ie, pe - ie + pos, pe - 1);
  return root;
}
}
// @lc code=end

