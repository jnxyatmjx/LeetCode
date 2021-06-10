/*
 * @lc app=leetcode id=63 lang=c
 *
 * [63] Unique Paths II
 */

// @lc code=start


int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){

    if(obstacleGrid[0][0] == 1) return 0;

    //the number of ways to first cell is 1
    obstacleGrid[0][0] = 1;
    
    //the most left column ,某格子为障碍则此格子下的所有格子可达路径数为0
    for(int row=1; row<obstacleGridSize; row++)
        obstacleGrid[row][0] = obstacleGrid[row][0] == 0 ? 
                (obstacleGrid[row-1][0]+obstacleGrid[row][0]) : 0;

    //the top row ,某格子为障碍则此格子后的所有格子可达路径数为0
    for(int colu=1; colu<obstacleGridColSize[0]; colu++)
        obstacleGrid[0][colu] = obstacleGrid[0][colu] == 0 ? 
                (obstacleGrid[0][colu-1]+obstacleGrid[0][colu]) : 0;

    for(int row=1; row<obstacleGridSize; row++)
        for(int colu=1; colu<obstacleGridColSize[0]; colu++)
            obstacleGrid[row][colu] = obstacleGrid[row][colu]==0 ? 
                            (obstacleGrid[row-1][colu] + obstacleGrid[row][colu-1]) : 0;
    
    return obstacleGrid[obstacleGridSize-1][obstacleGridColSize[0]-1];
    
    //Time Complexity: O(M×N). The rectangular grid given to us is of size M×N and we process each cell just once.    
    //Space Complexity: O(1). We are utilizing the obstacleGrid as the DP array. Hence, no extra space.
}
// @lc code=end

