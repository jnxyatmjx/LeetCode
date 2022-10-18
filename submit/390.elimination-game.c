/*
 * @lc app=leetcode id=390 lang=c
 *
 * [390] Elimination Game
 */

// @lc code=start


int lastRemaining(int n){
   return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
}
// @lc code=end

