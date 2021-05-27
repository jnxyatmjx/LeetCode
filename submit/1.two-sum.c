/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    // int * res = (int *)malloc(sizeof(int) * 2);
    // memset(res,0,sizeof(int)*2);
    for(int i = 0; i < numsSize - 1; i++)
        {
            for(int j = i + 1; j < numsSize; j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    int * res = (int *)malloc(sizeof(int) * 2);
                    res[0] = i;res[1] = j; *returnSize = 2;
                    return res;
                }
            }
        }
    *returnSize = 0;
    return NULL;
}
// @lc code=end

