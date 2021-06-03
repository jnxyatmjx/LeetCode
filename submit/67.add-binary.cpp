/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {

        int i = a.length() - 1;
        int j = b.length() -1;
        std::string res = "";

        int carry = 0;
        while(i>=0 || j>=0 || carry>0)
        {
            carry += (i>=0 ? a.at(i--) - '0' : 0);
            carry += (j>=0 ? b.at(j--) - '0' : 0);
            res.insert(0,1,(carry % 2 + '0'));
            carry /= 2;
        }

        return res;
#if 0
        std::reverse(a.begin(),a.end());
        std::reverse(b.begin(),b.end());
        
        int carry = 0;
        std::string ans = "";
        int i = 0;
        /*
            '0'(char) --> 48(int)
            '1'(char) --> 49(int)
            {ans += 1 + '0'} means {ans += (1 + 48)} 
            means {ans += '1' (49) }
        */
        while(i<a.length() && i<b.length()){
            int sum = carry + (a[i] - '0') + (b[i]-'0');
            carry = sum>=2 ? 1 : 0; //进位制中进位像高位加1
            ans += (sum % 2) + '0';
            i++;
        }
        
        while(i < a.length() ){
            int sum = carry + (a[i] - '0');
            carry = sum>=2 ? 1 : 0;
            ans += (sum%2) + '0';
            i++;
        }
    
        while(i < b.length() ){
            int sum = carry + (b[i] - '0');
            carry = sum>=2 ? 1 : 0;
            ans += (sum%2) + '0';
            i++;
        }
          
        if(carry) 
            ans += carry + '0';
        
        std::reverse(ans.begin(),ans.end());
        return ans;
#endif
    }
};
// @lc code=end

