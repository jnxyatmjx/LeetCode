/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> res;
        vector<int> out;
        backtrack(res,out,1,n,k);//start from 1, [1,....,n]
        return res;
    }

    //Have n select options(n width of decision tree), 
    //k heigh of decision tree
    void backtrack(vector<vector<int>>&res ,vector<int>&out,int start, int n,int k)
    {
        if(static_cast<int>(out.size()) == k)//bottom of decision tree
        {
            res.push_back(out);
            return ;
        }

        for(int i=start; i<=n; i++)
        {
            out.push_back(i);//make a choice
            backtrack(res,out,i+1,n,k);
            out.pop_back();
        }
    }//end backtrack;
};
// @lc code=end

