#include <stdio.h>
#include <stdlib.h>
#include <cstddef>
#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    int numDistinctlands(std::vector<std::vector<char>>& grid) {
        int res = 0;
        std::size_t r = grid.size();
	
	std::vector<std::string> subs;

        for(std::size_t i=0;i<r;i++)
            for(std::size_t j=0; j< grid[i].size();j++)
            if(grid[i][j] == '1'){

		std::string sbs;
                dfs(grid,i,j,sbs);
                res++;
		std::cout << sbs << std::endl;
            }
        return res;
    }

    void dfs(std::vector<std::vector<char>>& grid,std::size_t r,std::size_t c,std::string& sb)
    {
        //out of bounds
        if(r < 0 || r >= grid.size() || c <0 | c>= grid[r].size())
            return;
        
        if(grid[r][c] == '0')
            return ;

        //flood fill [r,c]
        grid[r][c] = '0';
	
	sb.append("12,");

        dfs(grid,r,c-1,sb);
        dfs(grid,r,c+1,sb);
        dfs(grid,r-1,c,sb);
        dfs(grid,r+1,c,sb);

	sb.append("-12,");
    }
};

int main(int argc,char * argv[])
{
	(void)argc;
	(void)argv;
	
	std::vector<std::vector<char>> ex { {'1','0','1'},{'1','0','1'},{'1','0','0'}};
	Solution abc;
	int res = abc.numDistinctlands(ex);
	std::cout << res << std::endl;
	return 1;
}
