/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //nums1 is a subset of nums2 
        vector<int> res;
        stack<int> st;
        unordered_map<int, int> m;
        
        //
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                m[st.top()] = num; st.pop();
            }
            st.push(num);
        }
        for (int num : nums1) {
            res.push_back(m.count(num) ? m[num] : -1);
        }        
        return res;
    }

    // find all elmenets of array nums 's next greater element
   vector<int> GreaterElem(vector<int>& nums)
   {
       stack<int> st;
       vector<int> res(nums.size());

       //reverse nums from end to begin 
       //std::size_t will overflow crash over
       for(int i=nums.size()-1; i>=0; i--)
       {
           // must have Equal and Less than nums[i]
            while(!st.empty() && st.top() <= nums[i])
                st.pop(); //pop the small element

           res[i] = st.empty() ? -1 : st.top();
           st.push(nums[i]); 
       }

       return res;
   } 
};
// @lc code=end

