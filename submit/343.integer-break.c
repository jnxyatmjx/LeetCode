/*
 * @lc app=leetcode id=343 lang=c
 *
 * [343] Integer Break
 */

// @lc code=start

#define lmax(a,b)\
({ __typeof__ (a) a_ = (a);\
    __typeof__ (b) b_ = (b);\
    a_ > b_ ? a_: b_; })

int integerBreak(int n)
{
    int * dp = (int *)calloc(n+1,sizeof(int));
    dp[0] = 1; //not usefull
    dp[1] = 1; //not usefull
    dp[2] = 1;
    //dp[i] means the maximum value obtained of split number i
    for(int i=3; i<=n; i++)
        for(int j=1; j<i; j++)
        /*
            j multiplied i-j and
            j multiplied multiple numbers dp[i-j]
        */
            dp[i] = lmax(dp[i], lmax(dp[i-j]*j, (i-j)*j) );
    
    return dp[n];
}

int integerBreak1(int n){
    if(n==2) return 1;
    if(n==3) return 2;
    if(n==4) return 4;
    int result=1;

    while( n > 4)
    {
        result *= 3;
        n -= 3;
    }
    result *= n;

    return result;
}
// @lc code=end

