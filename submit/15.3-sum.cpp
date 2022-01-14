/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() <=0) return {};

        sort(nums.begin(),nums.end());

        vector<vector<int>> res;
        for(size_t i=0; i<nums.size()-1;i++)
        {
            vector<vector<int>> tepval = towsum(nums,i+1,0-nums[i]);

            for(auto twos: tepval)
            {
                twos.push_back(nums[i]);
                res.push_back(twos);
            }

            //remove duplicate elements in nums
            while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
        }//end for
        
        return res;
    }

    vector<vector<int>> towsum(vector<int>& nums,int lft,int target)
    {
        int rgt=nums.size()-1; //array index
        vector<vector<int>> res;
        while(lft < rgt)
        {
            long sum = nums[lft] + nums[rgt];//prevent to overflow
            if(sum > target)
                rgt--;
            else if(sum < target)
                lft++;
            else { //Caution remove Duplicate Elements
                res.push_back({nums[lft],nums[rgt]});
                int lftval=nums[lft], rgtval=nums[rgt];

                //below to remove duplicate elements
                while(lft<rgt && nums[lft]==lftval) lft++;
                while(lft<rgt && nums[rgt]==rgtval) rgt--;
            }
        }//end while
        return res;
    }
};
// @lc code=end

