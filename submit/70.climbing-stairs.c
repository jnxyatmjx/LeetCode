/*
 * @lc app=leetcode id=70 lang=c
 *
 * [70] Climbing Stairs
 */

// @lc code=start

int climbStairs(int n){
    if(n<=1) return 1;
    unsigned int * dp = (unsigned int*)calloc(n+1,sizeof(unsigned int));
    dp[0]=1,dp[1]=1;

    for(int i=2; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int climbStairs1(int n){
    
    if(n <= 1) return n;
    
    //the initialize value just associate for dp[2] = dp[0] + dp[1];
    unsigned int f=1,g=1;//dp[0]=1,dp[1]=1;


    //dp[n] = dp[n-1] + dp[n-2]
    while(0<n--)
    {
        g = f + g; //int this maybe overflow
        f = g - f;
    }

    return f;
}
// @lc code=end

