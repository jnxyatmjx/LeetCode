/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        //bt(candidates,res,out,target,0,0);
        bt_minus(candidates,res,out,target,0);//prevent sum from overflow
        return res;
    }

    void bt(vector<int>& candidates, vector<vector<int>>& res, vector<int>& out, int target, int sum, int st)
    {
        if(sum == target)
        {
            res.push_back(out);
            return;
        }
        //Missing this condition will result in Time Limited Exceeded
        if(sum > target)
         return;

        for(int i=st; i<candidates.size(); i++)
        {
            sum += candidates[i];
            out.push_back(candidates[i]);
            //printf("i:%d sum:%d\n",i,sum);
            //The same number may be chosen from candidates an unlimited number of times.
            bt(candidates,res,out,target,sum,/*i+1*/ i); //Caution Here.
            out.pop_back();
            sum -= candidates[i];
        }
    }

    void bt_minus(vector<int>& candidates, vector<vector<int>>& res, vector<int>& out, int sum, std::size_t st)
    {
        if(sum == 0)
        {
            res.push_back(out);
            return ;
        }

        //prevent recursive level too deeply
        if(sum < 0)
        {
            return;
        }

        for(std::size_t i=st; i<candidates.size(); i++)
        {
            sum -= candidates[i];
            out.push_back(candidates[i]);

            bt_minus(candidates,res,out,sum,i);
            
            out.pop_back();
            sum += candidates[i];
        }
    }
};
// @lc code=end

