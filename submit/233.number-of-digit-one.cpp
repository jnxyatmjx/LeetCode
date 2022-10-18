/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 */

// @lc code=start
class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for(int i=1; i<=n; i++){
            std::string cmd = std::to_string(i);
            res += std::count(cmd.begin(),cmd.end(),'1');
        }

        return res;
    }
};
// @lc code=end

