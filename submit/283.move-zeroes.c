/*
 * @lc app=leetcode id=283 lang=c
 *
 * [283] Move Zeroes
 */

// @lc code=start


void moveZeroes(int* nums, int numsSize){
    
    //fist pseudo- remove zero from nums
    int fs=0, sl=0;
    while (fs < numsSize)
    {
        if(nums[fs] != 0)
        {
            nums[sl++] = nums[fs];// the first index may be zero os NOT ++sl
        }
        fs++;
    }
    //printf("sl:%d fs:%d numsSize:%d\n",sl ,fs,numsSize);
    
    //second SET tails to Zero
    while (sl < numsSize)
    {
       nums[sl++] = 0;
    }
    
}
// @lc code=end

