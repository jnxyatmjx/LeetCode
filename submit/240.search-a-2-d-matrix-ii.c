/*
 * @lc app=leetcode id=240 lang=c
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start


bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    /*
        m == matrix.length
        n == matrix[i].length
    */
   int row   = matrixSize - 1; // from the last row
   int cloum = 0;              // from the firest colum in the special row
   
   // first verify row  and  then verify cloum second
   while( row >= 0 && cloum < matrixColSize[row])
   {
        if(matrix[row][cloum] > target)
            row--;
        else if(matrix[row][cloum] < target)
            cloum++;
        else
            return true;
   }
   return false;
}
// @lc code=end

