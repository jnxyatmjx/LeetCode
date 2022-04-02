/*
 * @lc app=leetcode id=27 lang=c
 *
 * [27] Remove Element
 */

// @lc code=start


int removeElement(int* nums, int numsSize, int val){
    int fast=0, slow=0;
    while(fast < numsSize)
    {
        if(nums[fast] != val)
        {
            nums[slow++] = nums[fast];//Caution NOT ++slow NOT
        }
        fast++;
    }

    return slow;
}
// @lc code=end

