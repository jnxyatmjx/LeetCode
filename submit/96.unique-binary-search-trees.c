/*
 * @lc app=leetcode id=96 lang=c
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
//https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247490696&idx=1&sn=798a350fcca16c89572caf65323dbec7&scene=21#wechat_redirect
//Catalan number
int numTrees(int n){
    int * dp = (int*)calloc(n+1,sizeof(int));
    dp[0] = dp[1] = 1;

    for(int i=2; i<=n; i++)
        for(int j=0; j<i; j++)
        {
            dp[i] += dp[j]*dp[i-j-1];
        }

        return dp[n];
}
// @lc code=end

