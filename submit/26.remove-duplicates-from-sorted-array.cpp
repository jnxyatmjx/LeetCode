/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;

        std::size_t fast=0, slow=0;
        while(fast < nums.size())
        {
            if(nums[fast] != nums[slow])
            {
                nums[++slow] = nums[fast];
            }
            fast++;
        }

        return slow+1;
    }
};
// @lc code=end

