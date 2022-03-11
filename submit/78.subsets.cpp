/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets1(vector<int>& nums) {
        if(nums.size() <= 0)
            return vector<vector<int>>();

        vector<vector<int>> res;
        vector<int> out;

        bt(nums,res,out,0);

        return res;
    } //end subsets

    void bt(vector<int>& nums,vector<vector<int>>& res,vector<int>& out,int start)
    {
        //this maybe a NULL set ??
        res.push_back(out); //Why and WF?????
        
        for(int i=start; i<nums.size(); i++)
        {
            out.push_back(nums[i]);
            bt(nums,res,out,i+1);
            out.pop_back();
        }

    }

    //Iteration  BFS
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;

        //start by adding empty res
        res.push_back(vector<int>());

        for(const auto& ns : nums)
        {
            //take all existing subsets and insert the current number in them to create new subsets
            std::size_t n = res.size();
            for(std::size_t i=0; i<n; i++)
            {
                vector<int> sets = res[i];
                sets.push_back(ns);//insert the current number in them to create new subsets
                res.push_back(sets);
            }
        }
        return res;
    }

};
// @lc code=end