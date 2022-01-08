/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
/*
    [4,9,5]\n[9,4,9,8,4]\n
*/
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int> s1;
        for(auto m:nums1) ++s1[m];
        for(auto m: s1) printf("%d --> %d\n",m.first,m.second);
        
        vector<int> res;

        for(auto m : nums2)
        {
            // if(s1.count(m) > 0)  is error
            if(s1[m] > 0)
            {
                res.push_back(m);
                s1[m]--;
            }
        }

        return res;
    }
};
// @lc code=end

