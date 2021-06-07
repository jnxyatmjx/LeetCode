/*
 * @lc app=leetcode id=67 lang=c
 *
 * [67] Add Binary
 */

// @lc code=start

void reverse(char * res,int l,int r)
{
    if(l >= r) return ;
    
    char tm = res[l];
    res[l] = res[r];
    res[r] = tm;

    reverse(res,l+1,r-1);
}

/*
    similar to 13.roman-to-integer.c
*/
char * addBinary(char * a, char * b){

    int aLen = strlen(a),bLen = strlen(b);
    int maxLen = aLen > bLen ? aLen + 2 : bLen + 2; // 2 is for the last '\0' in char* c language
    
    char * res = (char *)malloc(maxLen * sizeof(char)); memset(res,0,maxLen * sizeof(char));

    int carry = 0;
    //travers from last element
    int i = aLen - 1;
    int j = bLen - 1;
    int resIdx = 0;
    
    while (i >= 0 || j >= 0 || carry == 1) 
    {
        carry += (i >= 0 ? a[i--] - '0' : 0);
        carry += (j >= 0 ? b[j--] - '0' : 0);
        res[resIdx++] = (carry % 2 + '0');
        carry = carry / 2; //reset the carry number
    }
    
    reverse(res,0,strlen(res)-1);

    return res;
}
// @lc code=end

