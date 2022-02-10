l/*
 * @lc app=leetcode id=905 lang=c
 *
 * [905] Sort Array By Parity
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize){

    //like one iterator of quick sort

    int i=-1,j=numsSize;// i mean EVEN and j mean ODD
    
    while(1)
    {
        while( (nums[++i] & 0x1) == 0) //even
            if(i >= numsSize-1)
                break;
        
        while ( (nums[--j] & 0x1) == 1) //odd
            if(j <= 0)
                break;
        
        if(i < j)
        {
            int tm = nums[i];
            nums[i] = nums[j];
            nums[j] = tm;
        }
        else
            break;
    }

    *returnSize = numsSize;
    return nums;
}
// @lc code=end

