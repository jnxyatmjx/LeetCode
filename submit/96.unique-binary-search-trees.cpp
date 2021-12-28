/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:

     int numTrees(int n) {

        vector<vector<int>> // value from 1 to n ,so we need n+1 vector size
            dp(n+1,vector<int>(n+1,0));//dynamic programming

        //it is arranged in order from 1 to n, which ensure a BST can be constructed
        return nums(1,n,dp);
    }

    int nums(int lft, int rgt,vector<vector<int>>& dp)
    {
        if(lft > rgt) return 1;//1 for multiply

        if(dp[lft][rgt] != 0) return dp[lft][rgt];

        int res=0;
        for(int i=lft; i<=rgt; i++)
        {
            //i as root for psuedo-subtree
            int left = nums(lft,i-1,dp);
            int right = nums(i+1,rgt,dp);
            res += left * right;      //calculate them separately and add them
        }
        dp[lft][rgt] = res; //like post traversal tree

        return res;
    }
};
// @lc code=end

