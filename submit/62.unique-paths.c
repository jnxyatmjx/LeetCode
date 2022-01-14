/*
 * @lc app=leetcode id=62 lang=c
 *
 * [62] Unique Paths
 */

// @lc code=start


int uniquePaths(int m, int n){
    //1 -- m: number of rows  n: number of columns.
    //2 -- DP TABLE 当前格子中的值:为从上一个格子到当前格子的不同到达方法!!!!
    //3 -- because of JUST CAN move DOWN or RIGHT so the value of top row and value of most left column in the DP TABLE is 1
    int dp[m][n];

    if(m <= 0 || n <= 0) return 0;
    
    /* --3-- */
    for(int i=0;i<m;i++) /*most left column*/
        dp[i][0] = 1;
        
    for(int i=0;i<n;i++)/*top row*/
        dp[0][i] = 1;
    
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];/*表格内部当前格子值是 -- 当前格子的左侧格子走法 + 当前格子的上侧格子走法*/
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
            
    return dp[m-1][n-1];
}
// @lc code=end

