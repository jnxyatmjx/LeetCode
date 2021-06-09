/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n]; //数组中每个格子存储 从上一个格子 到 当前格子的 所有不同走法之和
        
        for(int row=0; row<m; row++)
            for(int colum=0; colum<n; colum++)
            {
                if(row>0 && colum>0)        //internal element
                    dp[row][colum] = dp[row-1][colum] + dp[row][colum-1];
                else if(row==0 || colum==0) //top row OR the most left column MUST 1
                    dp[row][colum] = 1;
                else
                    continue;
            }
    
        return  dp[m-1][n-1];
    }
};
// @lc code=end

