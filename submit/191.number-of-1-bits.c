/*
 * @lc app=leetcode id=191 lang=c
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
//this still applies to negative value
int hammingWeight(uint32_t n) {
    int num = 0;  
    while(n > 0)
    {
        n &= n-1;
        num++;
    }
    return num;
}
// @lc code=end

