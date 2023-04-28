/*
 * @lc app=leetcode id=136 lang=c
 *
 * [136] Single Number
 */

// @lc code=start
int singleNumber(int* nums, int numsSize){
    int res = 0;
    for(int i=0; i<numsSize; i++){
        res = res ^ nums[i];
    }
    return res;
}
// @lc code=end

