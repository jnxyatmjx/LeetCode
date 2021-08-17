/*
 * @lc app=leetcode id=80 lang=c
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start


int removeDuplicates(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    int slow = 0;
    int count = 0;
    for(int fast=1; fast < numsSize; fast++)
    {
        if(nums[fast] == nums[slow])
        {
            count++; // the equal element must be adjacent 
            if(count < 2)
                nums[++slow] = nums[fast];
        }else
        {
            count = 0;
            nums[++slow] = nums[fast];
        }
    }
    return slow+1;
}
// @lc code=end

