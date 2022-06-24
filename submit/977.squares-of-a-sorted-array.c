/*
 * @lc app=leetcode id=977 lang=c
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize){
    if(nums == NULL) return NULL;

    int * res = (int*)calloc(sizeof(int),numsSize);
    int i=0, j=numsSize-1;

    for(int k=numsSize-1; k>=0; k--)
    {
        if(abs( nums[i] ) > abs( nums[j] )){
            res[k] = nums[i]*nums[i];
            i++;
        }
        else{
            res[k] = nums[j]*nums[j];
            j--;
        }
    }
    *returnSize = numsSize;
    return res;
}
// @lc code=end

