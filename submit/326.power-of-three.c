/*
 * @lc app=leetcode id=326 lang=c
 *
 * [326] Power of Three
 */

// @lc code=start


bool isPowerOfThree(int n){

    if(n == 1) return true;
    if(n < 3) return false;
    unsigned int idx = 0;
    while (n % 3 == 0) 
    {
        n /= 3;
        idx++; //number of power degree
    }
    printf("idx:%u",idx);
    return n == 1;
}
// @lc code=end

