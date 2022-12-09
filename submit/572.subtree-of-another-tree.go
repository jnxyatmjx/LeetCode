/*
 * @lc app=leetcode id=572 lang=golang
 *
 * [572] Subtree of Another Tree
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
func same(r1,r2 *TreeNode) bool {
	
	if r1==nil && r2==nil {
		return true
	}

	if r1==nil || r2==nil || r1.Val != r2.Val {
		return false
	}
	
	return same(r1.Left,r2.Left) && same(r1.Right,r2.Right)
}

func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
    if root==nil {
		return false
	}

	if(same(root,subRoot)) {
		return true
	}

	return isSubtree(root.Left,subRoot) || isSubtree(root.Right,subRoot)
}
// @lc code=end

