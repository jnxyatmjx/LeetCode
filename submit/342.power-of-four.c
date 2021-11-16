/*
 * @lc app=leetcode id=342 lang=c
 *
 * [342] Power of Four
 */

// @lc code=start


bool isPowerOfFour(int n){
    if(n == 1) return true;
    if(n < 4) return false;
    
    while(n % 4 == 0) n/=4;
    return n == 1;
}
// @lc code=end

