/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() <=0 ) return "";
        std::string prefx = strs[0];
        
        for(const auto &ss:strs)
        {
            prefx = longestCommonPrefix(prefx,ss);
            if(prefx.size() <=0 ) break;
        }
        return std::move(prefx);
    }

private:

    #define minl(a,b)\
    ({ __typeof__ (a) a_ = (a);\
       __typeof__ (b) b_ = (b);\
       a_ < b_ ? a_ : b_;})

    string longestCommonPrefix(const std::string& str1,const std::string& str2) {
        
        size_t le = minl(str1.length(),str2.length());
        size_t idx = 0;

        while(idx < le && str1[idx] == str2[idx])
        {
            idx++;
        }
        //printf("idx:%td  substr:%s\n",idx,str1.substr(0,idx).c_str());
        return std::move(str1.substr(0,idx));

    }
};
// @lc code=end

