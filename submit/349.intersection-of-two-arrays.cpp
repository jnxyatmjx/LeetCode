/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
        
        //Set can remove repeat elements
        set<int> s1(nums1.begin(),nums1.end()),s2;
        
        vector<int> res;
        for(const auto m : nums2)
        {
            if(s1.count(m) == 1 ) s2.insert(m);
        }
        return vector<int>(s2.begin(),s2.end());
    }

     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> s1(nums1.begin(),nums1.end());
        vector<int> res;

        for(const auto m : nums2)
        {
            if(s1.count(m) == 1 )
            {
                res.push_back(m);
                s1.erase(m);
            }
        }
        return res;
    }   
};
// @lc code=end

