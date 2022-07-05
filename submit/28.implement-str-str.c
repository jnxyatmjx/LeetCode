/*
 * @lc app=leetcode id=28 lang=c
 *
 * [28] Implement strStr()
 */

// @lc code=start


int strStr(char * haystack, char * needle){
    if (strlen(needle) == 0 ) return 0;

    int m = strlen(haystack), n = strlen(needle);

    if (m < n) return -1;
    for (int i = 0; i <= m - n; ++i) {
        int j = 0;
        for (j = 0; j < n; ++j) {
            if (haystack[i + j] != needle[j]) break;
        }
        if (j == n) return i;
    }
    return -1;
}
// @lc code=end

