/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        //Initialize two pointers slow and fast as nums[0].
        int slow = nums[0], fast = nums[0];
        
        // Do slow = nums[slow] and fast = nums[nums[fast]] while slow and fast are not equal.
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        
        // assign slow as nums[0]    
        slow = nums[0];
        // Move slow and fast by one step each while slow and fast are not equal
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        // Both slow and fast points to the duplicate element
        return fast;
    }
};
// @lc code=end

