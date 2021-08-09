/*
 * @lc app=leetcode id=34 lang=c
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int findFirst(int*num,int tar,int lef ,int rig)
{   
    while(lef <= rig)
    {
        int mid = lef + (rig-lef)/2;
        if(num[mid] > tar)
            rig = mid -1;
        else if(num[mid] < tar)
            lef = mid + 1;
        else
        {
            if(mid == lef || num[mid-1]!=tar) return mid;
            rig = mid -1;
        }
    }
    return -1;
}

int findLast(int*num,int tar,int lef ,int rig)
{   
    while(lef <= rig)
    {
        int mid = lef + (rig-lef)/2;
        if(num[mid] > tar)
            rig = mid -1;
        else if(num[mid] < tar)
            lef = mid + 1;
        else
        {
            if(mid == rig || num[mid+1]!=tar) return mid;
            lef = mid +1;
        }
    }

    return -1;
}
//[5,7,7,8,8,10]\n6
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* res = (int*)calloc(2,sizeof(int));
    *returnSize = 0;

    if(numsSize <= 0)
    {
        *returnSize = 2;
        res[0] = -1;
        res[1] = -1;
        return res;
    }
    
    res[0] = findFirst(nums,target,0,numsSize-1);(*returnSize)++;
    res[1] = findLast(nums,target,0,numsSize-1);(*returnSize)++;
    printf("f:%d t:%d --%d\n",res[0],res[1],*returnSize);
    return res;
}
// @lc code=end

