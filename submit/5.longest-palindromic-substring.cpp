/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        std::string res = "";

        for(size_t i=0; i<s.size(); i++)
        {
            std::string s1 = Palindrome(s,i,i+1);
            std::string s2 = Palindrome(s,i,i);
            res = s1.length() > res.length() ? s1 : res;
            res = s2.length() > res.length() ? s2 : res;
        }
        return res;
    }

    std::string Palindrome(std::string& s, int l, int r)
    {
        int sl = static_cast<int>(s.size());
        while(l>=0 && r<sl && s.at(l) == s.at(r))
        {
           --l; ++r;//Caution From Inside to Outside Search palindromic substring
        }
        return s.substr(l+1,r-l-1);
    }
};
// @lc code=end

