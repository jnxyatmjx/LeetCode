/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size() <= 0)
            return {{}};

        vector<vector<int>> res;
        vector<int> out;

        bt(nums,res,out,0);

        return res;
    } //end subsets

    void bt(vector<int>& nums,vector<vector<int>>& res,vector<int>& out,int start)
    {
        //this maybe a NULL set ??
        res.push_back(out); //Why and WF?????
        for(auto const m : out) printf("%d ",m);
        printf("\n ");
        for(int i=start; i<nums.size(); i++)
        {
            out.push_back(nums[i]);
            bt(nums,res,out,i+1);
            out.pop_back();
        }

    }

};
// @lc code=end