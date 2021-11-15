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

#define lmin(a,b)\
({ __typeof__ (a) a_ = (a);\
    __typeof__ (b) b_ = (b);\
    a_ < b_ ? a_ : b_;})

int lengthOfLongestSubstring(char * s){
    int n = strlen(s), ans = 0;
    int lookup[128]; memset(lookup,0,sizeof(int) * 128);// current lookup of character ,All ASCII character
    
    // try to extend the range [left, i]
    for (int i = 0, left = 0; i < n; i++) {
        left = lmax(lookup[s[i]], left);
        ans = lmax(ans, i - left + 1);
        lookup[s[i]] = i + 1;
        printf("left:%d i:%d lookup[%d]:%d\n",left,i,s[i],lookup[s[i]]);
    }
    return ans;
}
// @lc code=end

