/*
 * @lc app=leetcode id=11 lang=c
 *
 * [11] Container With Most Water
 */

// @lc code=start

//CAUTION the ()
#define MAX(a,b) ( ((a) > (b)) ? (a) : (b) )
#define MIN(a,b) ( ((a) < (b)) ? (a) : (b) )

int maxArea(int* height, int heightSize){
    int l = 0,r = heightSize - 1;
    int area = 0;
    while(l < r)
    {
        area = MAX( area , MIN(height[l],height[r]) * (r-l) );
        if(height[l] < height[r])
            l++;
        else
            r--;
    }
    return area;
}
// @lc code=end

