/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {

#define minl(a,b)\
({ __typeof__ (a) a_ = (a);\
__typeof__ (b) b_ = (b);\
    a_ < b_ ? a_ : b_;})

public:
    //dynamic programming
    int minPathSum(vector<vector<int>>& grid) {
        int res=0;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        
        int sum=0;
        //the most top row
        for(size_t i=0; i<grid[0].size(); i++)
        {
            sum += grid[0][i];
            dp[0][i] = sum;
        }

        //the most left column
        sum = 0;
        for(size_t i=0; i<grid.size(); i++)
        {
            sum += grid[i][0];
            dp[i][0] = sum;
        }

        for(size_t i=1; i<grid.size(); i++)
            for(size_t j=1; j<grid[0].size(); j++){
                dp[i][j] = minl(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }

        return dp[grid.size()-1][grid[0].size()-1];
    }
};
// @lc code=end

