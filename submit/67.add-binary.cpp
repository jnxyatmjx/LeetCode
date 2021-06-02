/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        std::reverse(a.begin(),a.end());
        std::reverse(b.begin(),b.end());
        
        int carry = 0;
        std::string ans = "";
        int i=0;
        while(i<a.length() && i<b.length()){
            int sum = carry + (a[i] - '0') + (b[i]-'0');
            carry = sum>=2 ? 1 : 0;
            ans += (sum % 2) + '0';
            //ans.append( std::to_string( (sum % 2) + '0') );
            i++;
        }
        

        if(i<a.length()){
            while(i<a.length()){
                int sum = carry + (a[i] - '0');
                carry = sum>=2 ? 1 : 0;
                ans += (sum%2) + '0';
                i++;
            }
        }else{
            while(i<b.length()){
                int sum = carry + (b[i] - '0');
                carry = sum>=2 ? 1 : 0;
                ans += (sum%2) + '0';
                i++;
            }
        }
        
        if(carry) 
            ans += carry + '0';
        
        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};
// @lc code=end

