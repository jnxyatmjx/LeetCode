/*
 * @lc app=leetcode id=448 lang=c
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int*a ,int *b)
{
    int ts = *a;
    *a = *b;
    *b = ts;
}
//cyclic sort
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    *returnSize = 0;
    int * res = (int*)calloc(numsSize,sizeof(int));

    for(int i=0; i<numsSize;){
        if(nums[i]-1 != i && nums[i]!=nums[nums[i]-1]){
            swap(nums+i,nums+nums[i]-1);
        }else
            ++i;
    }
    for(int i=0; i<numsSize;i++)
    {
        if(nums[i]-1 != i)
        {
            res[(*returnSize)++] = i+1;
        }
    }
    return res;
}
// @lc code=end

