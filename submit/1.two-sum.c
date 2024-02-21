/*
 * @lc app=leetcode id=1 lang=c
 *
 * [1] Two Sum
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void quick_swap(int*a,int*b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void quick_sort(int *nums,int lft,int rgt)
{
    if(lft >= rgt) return ;
    int i=lft,j=rgt+1,pivot=nums[lft];
    while(1)
    {
        while(nums[++i] < pivot)
            if(i >= rgt) break;
        
        while(nums[--j] > pivot)
            if(j <= lft) break;
        
        if(i < j)
            quick_swap(nums+i,nums+j);
        else 
            break;
    }
    quick_swap(nums+j,nums+lft);
    quick_sort(nums,lft,j-1);
    quick_sort(nums,j+1,rgt);
}

void help(int* nums,int lft,int rgt,int target,int* res)
{
    while(lft < rgt)
    {
        long sum = nums[lft] + nums[rgt];//prevent overflow
        if(sum > target)
            rgt--;
        else if( sum < target)
            lft++;
        else { //only just one solution
            res[0]=lft; res[1]=rgt;
            return;
        }
    }
}

int* twoSumError(int* nums, int numsSize, int target, int* returnSize)
{
    //sort array
    quick_sort(nums,0,numsSize-1);
    
    int * res = (int*)calloc(2,sizeof(int));
    help(nums,0,numsSize-1,target,res);
    if(res[1] != 0)
        *returnSize=2;
    else
        *returnSize=0;
    return res;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
   
    for(int i = 0; i < numsSize/*numsSize - 1*/; i++)
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

