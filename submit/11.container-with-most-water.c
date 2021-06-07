/*
 * @lc app=leetcode id=11 lang=c
 *
 * [11] Container With Most Water
 */

// @lc code=start

//CAUTION the ()
#define MAX(a,b) ( ((a) > (b)) ? (a) : (b) )
#define MIN(a,b) ( ((a) < (b)) ? (a) : (b) )

#define maxA(a,b) \
    ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define minA(a,b) \
   ({ __typeof__ (a) _a = (a); \
      __typeof__ (b) _b = (b); \
      _a < _b ? _a : _b; })

int maxArea(int* height, int heightSize){
    int l = 0,r = heightSize - 1;
    int area = 0;
    while(l < r)
    {
        area = maxA( area , MIN(height[l],height[r]) * (r-l) );
        if(height[l] < height[r])
            l++;
        else
            r--;
    }
    return area;
}
// @lc code=end

