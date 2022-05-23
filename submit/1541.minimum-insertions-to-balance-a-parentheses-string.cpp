/*
 * @lc app=leetcode id=1541 lang=cpp
 *
 * [1541] Minimum Insertions to Balance a Parentheses String
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        vector<char> stack;
        
        int cnt = 0;
        int len = s.size();
        for (int i=0; i<len; i++) {
            
            if ( s[i] == '(' ) {
                stack.push_back( s[i] );
                continue;
            }
            // if s[i] is ')'
            if (stack.size() > 0)  {
                stack.pop_back();
            } else {
                cnt++; // missed the '('
            }
            
            // if  s[i+1] is ')', need to skip
            if ( i < len -1 && s[i+1] == ')' ) {
                i++;
            }else{
                cnt++; //missed the ')'
            }
         
        }
        
        // if the stack still has '(', which means need double of ')'
        return cnt + stack.size()*2;
    }
};
// @lc code=end

