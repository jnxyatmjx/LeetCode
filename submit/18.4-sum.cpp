/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:

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

    //sort original array, remove duplicate elements
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<=0) 
            return vector<vector<int>>();

        vector<vector<int>> res;
        int nSi = static_cast<int>(nums.size());
        sort(nums.begin(),nums.end());

        for(int i=0; i<nSi-3; i++)//caution array boundary check 
        {
            if(i>0 && nums[i]==nums[i-1]) continue; //remove duplicate
            
            for(int j=i+1; j<nSi-2; j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue; //removete duplicate
                
                vector<vector<int>> tval = towsum(nums,j+1,target-nums[i]-nums[j]);
                for(auto ts : tval)
                {
                    ts.push_back(nums[i]);
                    ts.push_back(nums[j]);
                    res.push_back(ts);
                }
            }//end for j
        }//end for i
            

        return res;
    }
};
// @lc code=end

