/*
 * @lc app=leetcode id=69 lang=c
 *
 * [69] Sqrt(x)
 */

// @lc code=start


int mySqrt(int x){
    
   if (x <= 1 )return x;//exception divide zero

    int l = 1;
    int r = x/2;
    while(l <= r)
    {
        int mid = l + (r-l)/2;
        int t = x/mid;
        if(t == mid)
            return mid;
        else if(t > mid)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}
// @lc code=end

