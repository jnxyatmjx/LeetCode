/*
 * @lc app=leetcode id=1254 lang=c
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start

//from [row,column] SET adjacent lands to Water
//Fillover all adjacent land cells to water
void dfs(int** gird,int row,int column,int row_bounds,int column_bounds)
{
    //out of bounds
    if( row < 0 || row >= row_bounds || column < 0 || column >=column_bounds)
        return ;
    
    if(gird[row][column] == 1)
        return ;

    //set water
    gird[row][column] = 1;

    //flood fill left ,right ,up, down lands
    dfs(gird,row,column-1,row_bounds,column_bounds);
    dfs(gird,row,column+1,row_bounds,column_bounds);
    dfs(gird,row-1,column,row_bounds,column_bounds);
    dfs(gird,row+1,column,row_bounds,column_bounds);
}
/*
    [[1,1,1,1,0,1,1,0],[1,0,0,1,0,1,0,0],[1,0,1,0,1,1,1,0],[1,0,0,1,0,0,1,1],[1,0,1,1,0,1,1,0]]\n
*/
int closedIsland(int** grid, int gridSize, int* gridColSize){
    
    for(int i=0; i<gridSize/* number of rows*/; i++)
    {   
        //flood fill left ,set to water
        dfs(grid,i,0,gridSize,gridColSize[i]);

        //flood fill right ,set to water
        dfs(grid,i,gridColSize[i]-1,gridSize,gridColSize[i]);
    }

    for(int i=0; i<gridColSize[0]/* number of columns*/; i++)
    {   
        //flood fill up ,set to water
        dfs(grid,0,i,gridSize,gridColSize[0]);

        //flood fill bottom ,set to water
        dfs(grid,gridSize-1,i,gridSize,gridColSize[0]);
    }

    int res = 0;
    for(int i=0;i<gridSize;i++)
        for(int j=0;j < gridColSize[i];j++)
        {
            if(grid[i][j] == 0)
            {   
                res++;
                dfs(grid,i,j,gridSize,gridColSize[i]);
                printf("%d ",grid[i][j]);
            }
            //printf("\n");
        }

    return res;
}
// @lc code=end

