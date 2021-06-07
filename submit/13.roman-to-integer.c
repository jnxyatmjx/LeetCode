/*
 * @lc app=leetcode id=13 lang=c
 *
 * [13] Roman to Integer
 */

// @lc code=start

/*

    similar to  67.add-binary.c
*/
int romanToInt(char * s){
    int symbolVal[26];memset(symbolVal,0,26);
    symbolVal['I' - 'A'] = 1;
    symbolVal['V' - 'A'] = 5;
    symbolVal['X' - 'A'] = 10;
    symbolVal['L' - 'A'] = 50;
    symbolVal['C' - 'A'] = 100;
    symbolVal['D' - 'A'] = 500;
    symbolVal['M' - 'A'] = 1000;

    int ans = 0;
    int n = strlen(s);
    for(int i = 0;i < n; i++)
    {
        int val = symbolVal[s[i] - 'A'];
        if(i < n-1 && val < symbolVal[s[i+1] - 'A'])
            ans -= val;
        else
            ans += val;
    }
    return ans;
}
// @lc code=end

