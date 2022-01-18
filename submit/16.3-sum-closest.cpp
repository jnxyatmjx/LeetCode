/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    //Time Space (N^2)
    int threeSumClosest(vector<int>& nums, int target) {
        int siz=static_cast<int>(nums.size());
        sort(nums.begin(),nums.end());
        int diff=INT_MAX,res;

        for(int i=0; i<siz-2; i++)
        {
            int lft=i+1,rgt=siz-1;
            while(lft < rgt)
            {
                int sum = nums[i]+nums[lft]+nums[rgt];
                if(abs(sum-target) < diff)
                {
                    diff = abs(sum-target);
                    res = sum;
                }
                if(sum > target)
                    rgt--;
                else 
                    lft++;
            }//end while

        }//end for

        return res;
    }

    //Time Space (N^3)
    int threeSumClosest1(vector<int>& nums, int target) {
        
        int siz=static_cast<int>(nums.size());
        int diff=INT_MAX,res;
        for(int i=0; i<siz-2; i++)
            for(int j=i+1; j<siz-1; j++)
                for(int m=j+1; m<siz; m++)
                {
                    int absv = abs(nums[i]+nums[j]+nums[m]-target);
                    if(absv < diff)
                    {
                        res = nums[i]+nums[j]+nums[m];
                        diff = absv;
                    }
                }
        return res;
    }
};
// @lc code=end

