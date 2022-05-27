/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
//https://mp.weixin.qq.com/s/XVnoX-lBzColVvVXNkGc5g
    vector<string> generateParenthesis(int n) {
        std::vector<string> res;
        std::string out;

        bt(res,out,n,n);
        
        return res;
    }

    /*
        lftremain: remaining number of left parenthesis
        rgtremain: remaining number of right parenthesis
    */
    void bt(std::vector<string>& res, std::string& out, int lftremain, int rgtremain)
    {
        if(lftremain<0 || rgtremain<0)
            return;

        // so lftremain allways less than or equal to rgtremain is valid
        if(lftremain > rgtremain)
            return ;

        if(lftremain==0 && rgtremain==0)
        {
            res.push_back(out);
            return;
        }

        // left parenthesis
        out.push_back('(');
        bt(res,out,lftremain-1,rgtremain);
        out.pop_back();

        // right parenthesis
        out.push_back(')');
        bt(res,out,lftremain,rgtremain-1);
        out.pop_back();
    }
};
// @lc code=end

