/*
 * @lc app=leetcode id=66 lang=c
 *
 * [66] Plus One
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void revers(int* a,int lft,int rgt)
{
    if (lft >= rgt) return;
    int tem = a[lft];
    a[lft] = a[rgt];
    a[rgt] = tem;

    revers(a,lft+1,rgt-1);
}

int* plusOne(int* digits, int digitsSize, int* returnSize){

    if(digits==NULL || digitsSize<=0) return NULL;
    
    int * res = (int*)calloc(digitsSize + 1,sizeof(int));

    int carry = 0;
    int i = digitsSize-1;
    int j = 1-1;//for the plus one
    int idx = 0;
    while(i>=0 || j>=0 || carry==1)
    {
        carry += (i>=0? digits[i--] : 0);
        carry += (j>=0? 1: 0); j--;//plus one only once
        res[idx++] = (carry%10);
        carry /= 10;
    }
    *returnSize = idx;

    revers(res,0,idx-1);
    
    return res;
}
// @lc code=end

