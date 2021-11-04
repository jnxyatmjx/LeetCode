/*
 * @lc app=leetcode id=415 lang=c
 *
 * [415] Add Strings
 */

// @lc code=start

//like 67 add-binary and  similar to 13 roman-to-integer

void reverse(char*res,int l,int r)
{
    /*
        //recursive
        if(l >= r) return ;
        char tep = res[l];
        res[l] = res[r];
        res[r] = tep;
        reverse(res,l+1,r-1);
    */

    //iterator
    size_t len = strlen(res);
    for (int i = 0; 2 * i < len; i++) 
    {
        char t = res[i];
        res[i] = res[len - i - 1];
        res[len - i - 1] = t;
    }
}

char * addStrings(char * num1, char * num2){

    int aLen = strlen(num1),bLen = strlen(num2);
    int maxLen = aLen > bLen ? aLen + 1 + 1 : bLen + 1 + 1; // 2 is for the last '\0' in char* c language
    
    char * res = (char *)calloc(maxLen, sizeof(char));
    
    int i = aLen-1, j = bLen-1;
    int carry = 0,residx = 0;
    while(i>=0 || j>=0 || carry > 0)
    {
        carry += (i>=0 ? num1[i--] - '0': 0 );
        carry += (j>=0 ? num2[j--] - '0': 0 );
        res[residx++] = (carry % 10 + '0');
        carry = carry / 10; //reset the carry number
    }
    reverse(res,0,strlen(res)-1);
    return res;
}
// @lc code=end

