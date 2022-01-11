/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1); //dp[i] means the maximum product value obtained that spliting interger i .
        dp[2] = 1;
        for (int i = 3; i <= n ; i++) {
            for (int j = 1; j < i - 1; j++) {
                /*
                    2 solutions
                    first : Product of two numbers. {e.g. j and (i-j) }
                    second: Product of multiple numbers. {e.g. j and dp[i-j] }
                    dp[i-j] means maximum product value of number (i-j). 
                    So j multiplied dp[i-j] is all possible results
                */
                dp[i] = max(dp[i], max( (i-j)*j, dp[i-j]*j) );
            }
        }
        return dp[n];
    }
};
// @lc code=end

