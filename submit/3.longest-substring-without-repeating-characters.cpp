/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start

#define lmax(a,b)\
({ __typeof__ (a) a_ = (a);\
    __typeof__ (b) b_ = (b);\
    a_ > b_ ? a_ : b_;})

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (lookup.find(s[i]) != lookup.end())
            {
                lookup.erase(s[left]);// erase left element NOT i
                left++;
            }//end while
            maxStr = lmax(maxStr,i-left+1);
            lookup.insert(s[i]);
    } //end for
        return maxStr;
        
    }
};
// @lc code=end

