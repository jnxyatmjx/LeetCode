/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int si=static_cast<int>(nums.size());
        int i=-1, j=si;
        while (1)
        {
            while ( (nums[++i] & 0x1) == 0) //even
            {
                if(i >= si-1)
                    break;  
            }

            while ( (nums[--j] & 0x1) == 1) //odd
            {
                if( j <= 0)
                    break;
            }
            
            if(i < j)
                std::swap(nums[i],nums[j]);
            else
                break;
        }//end while

        return nums;
    }
};
// @lc code=end

