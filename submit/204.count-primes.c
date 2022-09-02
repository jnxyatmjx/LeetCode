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

bool isPri(int n){
    for(int i=2; i*i<=n; i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

int countPrimes1(int n){
    int res = 0;
    
    for (int i = 2; i < n; ++i) {
        if (isPri(i)) ++res;
    }
    return res;
}
// @lc code=end

