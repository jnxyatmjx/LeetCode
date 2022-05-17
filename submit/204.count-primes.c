/*
 * @lc app=leetcode id=204 lang=c
 *
 * [204] Count Primes
 */

// @lc code=start


int countPrimes(int n){
    int res = 0;
    bool *prime = (bool*)malloc(sizeof(bool)*n);
    memset(prime,1,n);
    
    for (int i = 2; i < n; ++i) {
        if (!prime[i]) continue;
        ++res;
        for (int j = 2; i * j < n; ++j) {
            prime[i * j] = false;
        }
    }
    return res;
}
// @lc code=end

