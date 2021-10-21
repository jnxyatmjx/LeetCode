/*
 * @lc app=leetcode id=200 lang=c
 *
 * [200] Number of Islands
 */

// @lc code=start
/*
[["0","1","0","1","0"],["1","0","0","1","0"],["0","1","0","0","0"],["0","1","0","0","0"]]\n
*/
int numIslands(char** grid, int gridSize, int* gridColSize){

    int res = 0;
    for(int i=0; i<gridSize;i++)
        for (int j=0; j<gridColSize[i];j++)
            if(grid[i][j] == '1'){
                //res++;
                dfs(grid,i,j,gridSize,gridColSize[i]);
                res++;
            }
    
    return res;
}


//from [row,column] SET adjacent lands to Water
void dfs(char** gird,int row,int column,int row_bounds,int column_bounds)
{
    //out of bounds
    if( row < 0 || row >= row_bounds || column < 0 || column >=column_bounds)
        return ;
    
    if(gird[row][column] == '0')
        return ;

    //set water
    gird[row][column] = '0';

    //flood fill left ,right ,up, down lands
    dfs(gird,row,column-1,row_bounds,column_bounds);
    dfs(gird,row,column+1,row_bounds,column_bounds);
    dfs(gird,row-1,column,row_bounds,column_bounds);
    dfs(gird,row+1,column,row_bounds,column_bounds);
}
// @lc code=end

