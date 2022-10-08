/*
 * @lc app=leetcode id=9 lang=c
 *
 * [9] Palindrome Number
 */

// @lc code=start


bool isPalindrome(int x){
    if(x<0 || (x%10==0 && x!=0)) return false;
    int invt = 0;
    while(x > invt){
        invt = invt*10 + x%10;
        x /= 10;
    }

    return x == invt || x == invt/10;
}
// @lc code=end

