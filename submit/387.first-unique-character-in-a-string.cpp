/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (char c : s) ++m[c];    //iterate through string and insert character into map
        
        for (int i = 0; i < s.size(); ++i) { //traversing the string again and find the FIRST 1
            if (m[s[i]] == 1) return i;
        }
        return -1;
    }
};
// @lc code=end

