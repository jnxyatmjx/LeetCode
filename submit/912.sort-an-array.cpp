/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
class Solution {
public:
    typedef vector<int>::iterator idx;
    vector<int> sortArray(vector<int>& nums) {
        
        /*Normal Quick Sort Time Limit Exceed*/
        //sort1(nums,0,static_cast<int>(nums.size()-1));

        merg_sort(nums.begin(),nums.end());
        return nums;
    }

    template <class Iter> 
    void merg_sort(Iter lft, Iter rgt )
    {
        //if(lft >= rgt) return; //Merge consecutive sorted [first,last) exclude the last one
        if(rgt - lft <= 1) return ;

        Iter mid = lft + (rgt-lft)/2;
        merg_sort(lft,mid);//[lft,mid)
        merg_sort(mid,rgt);//[mid,rgt) so NOT (mid+1,rgt),Caution
        std::inplace_merge(lft, mid, rgt);
    }

    //Time Limit Exceeded. if nums allread sorted will time limit exceed
    void sort1(vector<int>& nums, int lft, int rgt)
    {
        if(lft >= rgt) return ;

        int i=lft, j=rgt+1;
        int pivot = nums[lft];
        while(1)
        {
            while(nums[++i] < pivot)
                if(i >= rgt)
                    break;
            while (nums[--j] > pivot)
                if(j <= lft)
                    break;
            
            if(i < j)
                std::swap(nums[i],nums[j]);
            else
                break;
        }
        std::swap(nums[j],nums[lft]);

        sort1(nums,lft,j-1);
        sort1(nums,j+1,rgt);
    }//end function
};
// @lc code=end

