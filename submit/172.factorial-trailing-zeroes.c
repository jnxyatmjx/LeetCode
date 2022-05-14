/*
 * @lc app=leetcode id=172 lang=c
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start


int trailingZeroes(int n){

    int res = 0;
    int divisor = 5;
    while(divisor <= n)
    {
        res += n/divisor;
        divisor *= 5;
    }
    return res;
}
// @lc code=end

