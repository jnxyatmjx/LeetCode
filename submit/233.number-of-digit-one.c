/*
 * @lc app=leetcode id=233 lang=c
 *
 * [233] Number of Digit One
 */

// @lc code=start


int countDigitOne(int n){
    int res = 0;
    unsigned int a = 1, b = 1;
    while (n > 0) {
        res += (n + 8) / 10 * a + (n % 10 == 1) * b;
        b += n % 10 * a;
        a *= 10;
        n /= 10;
    }
    return res;
}
// @lc code=end

