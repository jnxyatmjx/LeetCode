/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
//simillar to 78
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // sort the numbers to handle duplicates
        vector<vector<int>> subsets;
        subsets.push_back(vector<int>());
        int startIndex = 0, endIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            startIndex = 0;
            // if current and the previous elements are same, create new subsets only from the subsets
            // added in the previous step
            if (i > 0 && nums[i] == nums[i - 1]) {
                startIndex = endIndex + 1;
            }
            endIndex = subsets.size() - 1;
            for (int j = startIndex; j <= endIndex; j++) {
                // create a new subset from the existing subset and add the current element to it
                vector<int> set(subsets[j]);
                set.push_back(nums[i]);
                subsets.push_back(set);
            }
        }
    return subsets;
    }

};
// @lc code=end

 