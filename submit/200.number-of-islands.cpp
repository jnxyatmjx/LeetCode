/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        std::size_t r = grid.size();
        for(std::size_t i=0;i<r;i++)
            for(std::size_t j=0; j< grid[i].size();j++)
            if(grid[i][j] == '1'){
                dfs(grid,i,j);
                res++;
            }
        return res;
    }

    void dfs(vector<vector<char>>& grid,std::size_t r,std::size_t c)
    {
        //out of bounds
        if(r < 0 || r >= grid.size() || c <0 || c>= grid[r].size())
            return;
        
        if(grid[r][c] == '0')
            return ;

        //flood fill [r,c]
        grid[r][c] = '0';

        dfs(grid,r,c-1);
        dfs(grid,r,c+1);
        dfs(grid,r-1,c);
        dfs(grid,r+1,c);
    }
};
// @lc code=end

