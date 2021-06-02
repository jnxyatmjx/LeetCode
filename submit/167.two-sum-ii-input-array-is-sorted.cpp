/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::vector<int> res;
        size_t l = 0,r = numbers.size()-1;
        while(l < r)
        {
            if(numbers[l] + numbers[r] == target)
            {
                res.push_back(l+1);
                res.push_back(r+1);
                return std::move(res);
            }else if(numbers[l] + numbers[r] > target)
                r = r - 1;
            else
                l = l + 1;
        }//end while

        return std::move(res);
    }
};
// @lc code=end

