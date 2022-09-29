/*
 * @lc app=leetcode id=509 lang=c
 *
 * [509] Fibonacci Number
 */

// @lc code=start


int fib(int n){
    if(n <= 1) return n;
    int f=0, g=1;//f(0)=0, f(1)=1
    while(0 < n--){
        g = g + f;
        f = g - f;
    }
    return f;
}
// @lc code=end

