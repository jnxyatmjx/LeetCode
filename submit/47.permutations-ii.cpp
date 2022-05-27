/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visited(nums.size(),false);
        vector<int> out;
        sort(nums.begin(),nums.end());
        bt(nums,res,out,visited,0);
        return res;
    }

    void bt(vector<int>& nums, vector<vector<int>>& res, vector<int>& out, vector<bool>& visi, size_t leve)
    {
        if(leve == nums.size())
        {
            res.push_back(out);
            return;
        }

        for(size_t i=0; i<nums.size(); i++)
        {
            if(visi[i]) continue;

            //The relative position of the same elements in the arrangement remain unchanged
            if(i>0 && nums[i]==nums[i-1] && visi[i-1] == false) continue;

            visi[i] = true;
            out.push_back(nums[i]);
            bt(nums,res,out,visi,leve+1);
            out.pop_back();
            visi[i] = false;
        }
    }
};
// @lc code=end

