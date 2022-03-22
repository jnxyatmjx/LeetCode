/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        std::sort(candidates.begin(),candidates.end());
        bt(candidates,res,out,target,0,0);
        return res;
    }

    void bt(vector<int>& candidates, vector<vector<int>>& res, vector<int>& out, int target, int sum, std::size_t start)
    {
        if(sum == target)
        {
            res.push_back(out);
            return ;
        }

        //Missing this condition will result in Time Limit Exceeded
        if(sum > target)
            return ;

        for(std::size_t i=start; i<candidates.size(); i++)
        {
            //Remove duplicate elements
            if(i>start && candidates[i] == candidates[i-1]) 
                continue;

            sum += candidates[i];
            out.push_back(candidates[i]);
            bt(candidates,res,out,target,sum,i+1);
            out.pop_back();
            sum -= candidates[i];
        }
    }
};
// @lc code=end

