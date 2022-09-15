/*
 * @lc app=leetcode id=268 lang=c
 *
 * [268] Missing Number
 */

// @lc code=start


int missingNumber(int* nums, int numsSize){
    int sum1 = 0;
    int sum2 = 0;
    for(int i=0; i<numsSize; i++) 
    {
        sum1 += nums[i];
        sum2 += i;
    }
    sum2 += numsSize;

    return sum2 - sum1;
}
// @lc code=end

