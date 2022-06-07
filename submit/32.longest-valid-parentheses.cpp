/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
class Solution {
private:
#define lmax(a,b) \
({ __typeof__ (a) a_ = (a); \
   __typeof__ (b) b_ = (b); \
   a_ > b_ ? a_ : b_;\
})
public:
    int longestValidParentheses(string s) {
        int res = 0;
        vector<int> stk_;

        stk_.push_back(-1);//If the container is empty, it causes undefined behavior.

        for(size_t i=0; i<s.length(); i++)
        {
            if(s[i] == '(')
                stk_.push_back(i);
            else{
                stk_.pop_back(); //If the container is empty, it causes undefined behavior
                if(stk_.empty()){
                    stk_.push_back(i);
                }else{
                    res = lmax(res,i-stk_.back());
                }
            }
        }//end for
        return res;
    }
};
// @lc code=end

