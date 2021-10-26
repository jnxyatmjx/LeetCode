/*
 * @lc app=leetcode id=695 lang=c
 *
 * [695] Max Area of Island
 */

// @lc code=start


#define maxl(a,b)\
	({ __typeof__ (a) a_ = (a);\
	 __typeof__ (b) b_ = (b);\
	 a_ > b_ ? a_ : b_;})
    
#define minl(a,b)\
    ({__typeof__ (a) a_ = (a);\
        __typeof__ (b) b_ = (b);\
        a_ < b_ ? a_ : b_;})


int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){

    // //set left ,right cells to water
    // for(int i=0;i<gridSize;i++)
    // {
    //     dfs(grid,i,0,gridSize,gridColSize[0]);
    //     dfs(grid,i,gridColSize[0]-1,gridSize,gridColSize[0]);
    // }

    //  //set up ,down cells to water
    // for(int i=0;i<gridColSize[0];i++)
    // {
    //     dfs(grid,0,i,gridSize,gridColSize[0]);
    //     dfs(grid,gridSize-1,i,gridSize,gridColSize[0]);
    // }

    int res=0;
    for(int i=0;i <gridSize;i++)
        for(int j=0;j<gridColSize[i];j++)
        {
            res = maxl(res,dfs(grid,i,j,gridSize,gridColSize[i]));
        }

    return res;
}

int dfs(int** grid, int row, int col,int row_max,int col_max)
{
    if(row < 0 || row >= row_max || col <0 || col >= col_max)
        return 0;
    
    if(grid[row][col] == 0)
        return 0;

    //set [row][col] to water , prevent from recursive repeatlly
    grid[row][col] = 0;

    //return number of cells in a island
    return  1 + dfs(grid,row,col+1,row_max,col_max) + 
            dfs(grid,row,col-1,row_max,col_max) +
            dfs(grid,row+1,col,row_max,col_max) +
            dfs(grid,row-1,col,row_max,col_max);
}
// @lc code=end

