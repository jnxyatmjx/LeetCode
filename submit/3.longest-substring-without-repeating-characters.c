/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start

#define lmax(a,b) \
({ __typeof__ (a) a_ = (a); \
   __typeof__ (b) b_ = (b); \
   a_ > b_ ? a_ : b_;\
})

int lengthOfLongestSubstring(char * s){
    int n = strlen(s), ans = 0;
    int lookup[128]; memset(lookup,0,sizeof(int) * 128);// current lookup of character ,All ASCII character
    
    // try to extend the range [i, j]
    for (int j = 0, i = 0; j < n; j++) {
        i = lmax(lookup[s[j]], i);
        ans = lmax(ans, j - i + 1);
        lookup[s[j]] = j + 1;
    }
    return ans;
}
// @lc code=end

