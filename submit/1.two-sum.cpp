/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int,int> mp;
        std::vector<int> res;
        for(int i = 0; i < (int)(nums.size()); i++)
        {
            int comp = target - nums[i];
            if(mp.count(comp) > 0)
            {
                res.push_back(mp[comp]);
                res.push_back(i);
                break;
            }
            mp[nums[i]] = i;//put nums[i] into map , if target-nums[i] in map ,so we find the result
        }

        return res;
    }
};
// @lc code=end

