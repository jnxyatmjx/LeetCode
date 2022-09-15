/*
 * @lc app=leetcode id=442 lang=c
 *
 * [442] Find All Duplicates in an Array
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
// cyclic sort
int* findDuplicates(int* nums, int numsSize, int* returnSize){

    for(int i=0; i<numsSize;)
    {
        if(nums[i]-1 != i /*prevent i+1 overflow*/ 
        && nums[i] != nums[nums[i]-1] /* duplicate element cause of infinite loop*/  ){
            swap(nums+i,nums + nums[i] -1);
        }
        else
            ++i;
    }

    int * res = (int*)calloc(numsSize,sizeof(int));
    *returnSize = 0;

    for(int i=0; i<numsSize; i++)
        if(nums[i]-1 != i)
        {
            
            res[(*returnSize)++] = nums[i];
        }

    return res;
}
// @lc code=end

