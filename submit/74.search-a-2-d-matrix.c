/*
 * @lc app=leetcode id=74 lang=c
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start


bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row = matrixSize - 1;
    int colum = 0;
    while(row >= 0 && colum < matrixColSize[row])
    {
        if(matrix[row][colum] > target)
            row--;
        else if(matrix[row][colum] < target)
            colum++;
        else
            return true;
    }
    return false;
}
// @lc code=end

