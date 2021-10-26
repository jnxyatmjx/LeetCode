/*
 * @lc app=leetcode id=1020 lang=c
 *
 * [1020] Number of Enclaves
 */

// @lc code=start

/*
    Find the number of land cells
*/
int numEnclaves(int** grid, int gridSize, int* gridColSize){

    //left ,right bounds set to water
    for(int i=0;i<gridColSize[0];i++)
    {
        dfs(grid,0,i,gridSize,gridColSize[0]);
        dfs(grid,gridSize-1,i,gridSize,gridColSize[0]);
    }

    //up,down bounds set to water
    for(int i=0;i<gridSize;i++)
    {
        dfs(grid,i,0,gridSize,gridColSize[0]);
        dfs(grid,i,gridColSize[0]-1,gridSize,gridColSize[0]);
    }
    
    int res = 0;
    for(int i=0;i<gridSize;i++)
    { 
        for(int j=0;j<gridColSize[i];j++)
        {printf("%d ",grid[i][j]);
            if(grid[i][j] == 1)
            {
                //dfs(grid,i,j,gridSize,gridColSize[i]);
                res++;
            }
        }
        printf("\n");
    }
    return res;
}

//from [row,column] ,SET adjacent land cells to Water.
// Fillover all adjacent land cells to water.
void dfs(int** gird,int row,int column,int row_bounds,int column_bounds)
{
    //out of bounds
    if( row < 0 || row >= row_bounds || column < 0 || column >=column_bounds)
        return ;
    
    //if water just return
    if(gird[row][column] == 0)
        return ;

    //set water
    gird[row][column] = 0;

    //flood fill left ,right ,up, down lands
    dfs(gird,row,column-1,row_bounds,column_bounds);
    dfs(gird,row,column+1,row_bounds,column_bounds);
    dfs(gird,row-1,column,row_bounds,column_bounds);
    dfs(gird,row+1,column,row_bounds,column_bounds);
}
// @lc code=end

