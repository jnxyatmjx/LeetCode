/*
 * @lc app=leetcode id=41 lang=c
 *
 * [41] First Missing Positive
 */

// @lc code=start
void swap(int*a ,int *b)
{
    int ts = *a;
    *a = *b;
    *b = ts;
}
//cyclic sort [ˈsaɪklɪk]
int firstMissingPositive(int* nums, int numsSize){

    for(int i=0; i<numsSize;)
    {
        if(nums[i]>0 && nums[i]-1 != i 
        && nums[i]-1 < numsSize /*prevent array overflow*/
        && nums[i] != nums[nums[i]-1]/*remove duplicate element, prevent infinite loop*/){
            swap(nums+i,nums+nums[i]-1);
        }else
            ++i;
    }
    
    for(int i=0; i<numsSize;i++){
        if(nums[i]!= i+1 /*[-2147483648] over flow*/)
        {
            return i+1;
        }
    }
    return numsSize+1;
}
// @lc code=end

