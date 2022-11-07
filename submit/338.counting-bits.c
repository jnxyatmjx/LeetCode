/*
 * @lc app=leetcode id=338 lang=c
 *
 * [338] Counting Bits
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    
    int *res = (int*)calloc(sizeof(int),n+1);
    *returnSize = n+1;

    if(n==0) {*returnSize = 1; res[0]=0; return res;}

    //start from 1 NOT 0
    for(int i=1; i<=n ;i++){
        
        res[i] = res[i & i-1] + 1;
    }
    return res;
}
// @lc code=end

