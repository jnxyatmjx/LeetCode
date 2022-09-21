/*
 * @lc app=leetcode id=202 lang=c
 *
 * [202] Happy Number
 */

// @lc code=start


static int squares(int nums)
{
    int sum = 0;
    while(nums > 0){
        int digs = nums % 10;
        sum += digs *digs;
        nums = nums /10;
    }
    return sum;
}

bool isHappy(int n){

    int s=n, f=n;
    do{
        s = squares(s);
        f = squares(squares(f));
    }while(s != f);
    
    return s == 1;
}
// @lc code=end

