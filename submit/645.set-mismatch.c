/*
 * @lc app=leetcode id=645 lang=c
 *
 * [645] Set Mismatch
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
int* findErrorNums(int* nums, int numsSize, int* returnSize){
    *returnSize = 0;
    int *res = (int*)calloc(numsSize,sizeof(int));

    for(int i=0; i<numsSize;)
    {
        if(nums[i]-1 != i 
        && nums[i] != nums[nums[i]-1] /*duplicate element cause infinite loop*/)
        {
            swap(nums+i,nums + nums[i]-1);
        }
        else
         ++i;
    }

    for(int i=0; i<numsSize;i++)printf(" %d",nums[i]);
    printf("\n");

    for(int i=0; i<numsSize;i++)
    {
        if(nums[i]-1 != i)
        {
            *returnSize = 2;
            res[0] = nums[i];
            res[1] = i+1;
        }
    }

    return res;
}
// @lc code=end

