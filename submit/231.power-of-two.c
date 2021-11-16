/*
 * @lc app=leetcode id=231 lang=c
 *
 * [231] Power of Two
 */

// @lc code=start


bool isPowerOfTwo(int n){
    if(n <= 0) return false;
    //return (n&n-1) == 0;
    //return n > 0 && (n & -n) == n;
    unsigned int idx = 0;
    while(n % 2 == 0) 
    {
        n/=2;
        idx++; //number of power
    }
    printf("idx:%d ",idx);
    return n == 1;
}
// @lc code=end

