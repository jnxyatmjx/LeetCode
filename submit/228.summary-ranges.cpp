/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<std::string> res;
        if(nums.size() <= 0) return res;

        //double pointers to array nums
        std::size_t curr=0,prev=0;
        
        std::size_t nlen = nums.size();
        while(curr < nlen)
        {
            if(curr +1 < nlen && nums[curr]+1 == nums[curr+1])
            {
                curr++;
            }
            else{
                if(prev == curr)
                    res.push_back(std::to_string(nums[prev]));
                else{
                    std::string reva = std::to_string(nums[prev]);
                    reva.append("->").append(std::to_string(nums[curr]));
                    res.push_back(reva);
                }
                curr++;
                prev = curr;
            }

        }
        return res;
    }
};
// @lc code=end

