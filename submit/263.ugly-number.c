/*
 * @lc app=leetcode id=263 lang=c
 *
 * [263] Ugly Number
 */

// @lc code=start


bool isUgly(int n){
    if (n <= 0) return false;
    // if is ugly , prime factor is and only is 2,3,5
    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;
    
    return n == 1;
}
// @lc code=end

