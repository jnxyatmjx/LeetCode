/*
 * @lc app=leetcode id=405 lang=c
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start

void reverse(char*res,int l,int r)
{
    if (l >= r) return ;
    char temp = res[l];
    res[l] = res[r];
    res[r] = temp;
    reverse(res,l+1,r-1);
}

char * toHex(int num){
    
    char* res = (char*)calloc(sizeof(int)*8,sizeof(char));
    if(num == 0) 
    {
        res[0] = '0';
        return res;
    }
    int idx = 0,numsd=0;

    char symbol[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
    
    while(num != 0 && numsd++ < (sizeof(int)*8)/4 ) /*num>=0 is ERROR ,when negative*/
    {   
        res[idx++] = symbol[num&15]; //num%16 (取余)is error, because -1 % 16 = -1(取余), we need -1 % 16 = 15(取模)
        num = num >> 4;// num = num / 16 is error
    }
    reverse(res,0, strlen(res)-1);
    return res;
}
// @lc code=end

