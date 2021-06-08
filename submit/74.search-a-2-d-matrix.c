/*
 * @lc app=leetcode id=74 lang=c
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start


bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    
    //Search from the most left column on the bottom row
    int row = matrixSize - 1; //bottom row
    int colum = 0;            //most left colum
    while(row >= 0 && colum < matrixColSize[row])
    {
        if(matrix[row][colum] > target)
            row--;   //go to a smaller row
        else if(matrix[row][colum] < target)
            colum++; //move to a bigger colum
        else
            return true;
    }
    return false;
}
// @lc code=end

