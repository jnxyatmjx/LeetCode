/*
 * @lc app=leetcode id=912 lang=c
 *
 * [912] Sort an Array
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int *a, int *b)
{
    int te = *a;
    *a = *b;
    *b = te;
}

void insert_sort(int *nums, int lft, int rgt)
{
    if(lft >= rgt) return ;

    for(int i=lft+1; i<=rgt; i++)
    {
        int tepm = nums[i];//find the first element in second partion
        for( int j=i; j>lft&&nums[j-1]>nums[j]; j--)
        {
            /*  
                num[j-1] = nums[j];
                num[j] = tepm;//ERROR
                because elements from tail to header
            */
            nums[j] = nums[j-1];
            nums[j-1] = tepm;
        }
    }
}

void swap_media3(int *nums, int lft, int rgt)
{
    if(rgt-lft < 3) return ;

    //lft: minimums value position
    //rgt: maximum value positon
    //mid: middle of lft an rgt
    int mid = lft + (rgt-lft)/2;
    if(nums[lft] > nums[rgt]) swap(nums+lft,nums+rgt);
    if(nums[lft] > nums[mid]) swap(nums+lft,nums+mid);
    if(nums[mid] > nums[rgt]) swap(nums+mid,nums+rgt);

    //swap position mid and rgt-1
    swap(nums+mid,nums+rgt-1);
}

void quick_media3(int *nums,int lft, int rgt, int offsets)
{
    if(rgt-lft < offsets)
    {
        insert_sort(nums,lft,rgt);
    }else
    {
        swap_media3(nums,lft,rgt);
        //from now rgt-1 position is the pivot
        int i=lft, j=rgt-1, pivot=nums[rgt-1];
        while (1)
        {
            while(nums[++i] < pivot){}
            while (nums[--j] > pivot){}
            
            if(i < j) swap(nums+i,nums+j);
            else break;
        }//end while

        swap(nums+i,nums+rgt-1);
        quick_media3(nums,lft,i-1,offsets);
        quick_media3(nums,i+1,rgt,offsets);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize){

    quick_media3(nums,0,numsSize-1,20);
    *returnSize = numsSize;
    return nums;
}
// @lc code=end

