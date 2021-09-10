/*
 * @lc app=leetcode id=53 lang=c
 *
 * [53] Maximum Subarray
 */

// @lc code=start

#define tsmax(a,b)\
({ __typeof__ (a) a_ = (a);\
__typeof__ (b) b_ = (b);\
 a_ > b_ ? a_:b_; }) 

int maxSubArray(int* nums, int numsSize){

    if (numsSize == 0) return 0;
    // base case
    int dp_0 = nums[0];
    int dp_1 = 0, res = dp_0;

    for (int i = 1; i < numsSize; i++) {
        // dp[i] = max(nums[i], nums[i] + dp[i-1])
        dp_1 = tsmax(nums[i], nums[i] + dp_0);
        dp_0 = dp_1;
        
        // calculate the maximum value
        res = tsmax(res, dp_1);
    }

    return res;
}
// @lc code=end

