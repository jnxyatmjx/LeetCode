/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string res;

        int i = num1.length()-1;
        int j = num2.length()-1;

        int carry = 0;

        while(i>=0 || j>=0 || carry>0)
        {
            carry += (i>=0? num1[i--]-'0': 0);
            carry += (j>=0? num2[j--]-'0': 0);
            res.insert(0,1,(carry % 10 + '0'));
            carry /= 10;
        }

        return res;
    }
};
// @lc code=end

