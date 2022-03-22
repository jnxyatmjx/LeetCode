/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
//simillar to 78
    //Iterate
    vector<vector<int>> subsetsWithDup1(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // sort the numbers to handle duplicates

        vector<vector<int>> subsets;
        subsets.push_back(vector<int>()); //start from empty subsets

        std::size_t startIndex = 0, endIndex = 0;
        for (std::size_t i = 0; i < nums.size(); i++) {
            startIndex = 0;
            // if current and the previous elements are same, create new subsets only from the subsets
            // added in the previous step
            if (i > 0 && nums[i] == nums[i - 1]) {
                startIndex = endIndex + 1;
            }
            endIndex = subsets.size() - 1;
            //printf("startIndex:%td,endIndex:%td,resSize:%td\n",startIndex,endIndex,subsets.size());
            for (int j = startIndex; j <= endIndex; j++) {
                // create a new subset from the existing subset and add the current element to it
                vector<int> set(subsets[j]);
                set.push_back(nums[i]);
                subsets.push_back(set);
            }
        }
        return subsets;
    }

    //Recursive
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        std::vector<vector<int>> res;
        std::vector<int> out;
        std::sort(nums.begin(),nums.end());//sort array
        bt(nums,res,out,0);
        return res;
    }

    void bt(vector<int>& nums, vector<vector<int>>& res, vector<int>& out, size_t  start)
    {
        res.push_back(out);//start from empty subset

        for(size_t i=start; i<nums.size(); i++)
        {
            //Preorder Position
            if(i>start && nums[i]==nums[i-1])  continue;

            out.push_back(nums[i]);
            bt(nums,res,out,i+1);
            out.pop_back();

            //Postorder Position
            //while (i+1 < nums.size() && nums[i] == nums[i+1]) i++;
        }
    }

    void print_out(vector<int>& out)
    {
        for(const auto& aa : out)
            printf(" %d",aa);
        printf("\n");
    }
};
// @lc code=end

 