/*
 * @lc app=leetcode id=35 lang=c
 *
 * [35] Search Insert Position
 */

// @lc code=start

//Binary search -- Divide and Conquer
int searchInsert(int* nums, int numsSize, int target){
    if(nums[numsSize-1] < target) return numsSize;

    int lft=0,rgt=numsSize-1;
    while(lft <= rgt)
    {
        int mid = lft + (rgt-lft)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > target)
            rgt = mid-1;
        else if(nums[mid] < target)
            lft = mid+1;
    }
    return rgt+1; //not find target and need insert position
}
//O(n) line search
int searchInsert1(int* nums, int numsSize, int target){

    for(int i=0; i<numsSize; i++)//ascending sort
    {
        if(nums[i] >= target) return i;
    }

    return numsSize;
}

// @lc code=end

