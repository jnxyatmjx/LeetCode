/*
 * @lc app=leetcode id=101 lang=golang
 *
 * [101] Symmetric Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func help(lft *TreeNode,rgt *TreeNode) bool {
	if (lft==nil) && (rgt==nil){
		return true
	}
	if (lft==nil || rgt==nil) || (lft.Val != rgt.Val){
		return false;
	}
	return help(lft.Left,rgt.Right) && help(lft.Right,rgt.Left)
}
func isSymmetric(root *TreeNode) bool {
    
	if root==nil {
		return true;
	}

	return help(root,root)
}
// @lc code=end

