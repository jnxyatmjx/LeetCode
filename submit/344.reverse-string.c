/*
 * @lc app=leetcode id=344 lang=c
 *
 * [344] Reverse String
 */

// @lc code=start

void sapw(char *v1, char *v2)
{
    char te = *v1;
    *v1 = *v2;
    *v2 = te;
}

void reverseString(char* s, int sSize)
{
    if(sSize <= 0) return ;
    int l=0, r=sSize-1;

    while(l < r)
    {
        sapw(s+l, s+r);
        l++;
        r--;
    }
}

void reverseString1(char* s, int sSize){
    if(sSize <= 0) return ;
    rev(s,0,sSize-1);
}

void rev(char *s, int lft, int rgt)
{
    if(lft >= rgt) return ;

    sapw(s+lft, s+rgt);
    rev(s,lft+1,rgt-1);
}
// @lc code=end

