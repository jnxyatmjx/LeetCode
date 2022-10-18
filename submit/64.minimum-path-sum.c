/*
 * @lc app=leetcode id=64 lang=c
 *
 * [64] Minimum Path Sum
 */

// @lc code=start

#define minl(a,b)\
({  __typeof__ (a) a_ = (a);\
    __typeof__ (b) b_ = (b);\
     a_ > b_ ? b_ : a_;})

//[[1,3,1,1],[1,5,1,2],[4,2,1,3]]
int dp(int** grid, int**dp, int row, int col);

//Recursive + dp table
int minPathSum(int** grid, int gridSize, int* gridColSize){
    int m = gridSize;
    int n = gridColSize[0];
    
    //Caution
    //Stack variable can NOT use as Heap variable in recursive fucntion
    int ** dpmem = (int**)malloc(sizeof(int*) * m);
    for(int i=0; i<m; i++){
        dpmem[i] = (int*)malloc(sizeof(int) * n);
        for(int j=0; j<n; j++)
            dpmem[i][j] = -1;
    }
    
    return dp(grid,dpmem,m-1,n-1);
}

//Minimum sum path that from (left top) to (row,col)
int dp(int** grid, int**dpmem, int row, int col){
    
    if(row==0 && col==0) return grid[0][0];
    if(row<0 || col<0) return 1001;//

    if(dpmem[row][col] > 0) return dpmem[row][col];

    dpmem[row][col] = minl(dp(grid,dpmem,row,col-1),
                dp(grid,dpmem,row-1,col)) + grid[row][col];

    return dpmem[row][col];
}

// @lc code=end

