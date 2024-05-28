/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum1(vector<int> &nums)
    {
        if (nums.size() <= 0)
            return vector<vector<int>>();

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for (size_t i = 0; i < nums.size() - 2; i++)
        {
            vector<vector<int>> tepval = towsum(nums, i + 1, 0 - nums[i]);

            for (auto twos : tepval)
            {
                twos.push_back(nums[i]);
                res.push_back(twos);
            }

            // remove duplicate elements in nums
            while (i < nums.size() - 2 && nums[i] == nums[i + 1])
                i++;
        } // end for

        return res;
    }

    vector<vector<int>> towsum(vector<int> &nums, int lft, int target)
    {
        int rgt = nums.size() - 1; // array index
        vector<vector<int>> res;
        while (lft < rgt)
        {
            long sum = nums[lft] + nums[rgt]; // prevent to overflow
            if (sum > target)
                rgt--;
            else if (sum < target)
                lft++;
            else
            { // Caution remove Duplicate Elements
                res.push_back({nums[lft], nums[rgt]});
                int lftval = nums[lft], rgtval = nums[rgt];

                // below to remove duplicate elements
                while (lft < rgt && nums[lft] == lftval)
                    lft++;
                while (lft < rgt && nums[rgt] == rgtval)
                    rgt--;
            }
        } // end while
        return res;
    }

    vector<vector<int>> threeSum2(vector<int> &nums)
    {
        if (nums.size() < 3)
            return vector<vector<int>>();

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (size_t i = 0; i < nums.size() - 2; i++)
        {
            size_t lft = i + 1, rgt = nums.size() - 1;
            while (lft < rgt)
            {
                int sum = nums[i] + nums[lft] + nums[rgt];
                if (sum == 0)
                {
                    // vector<int> tmp{nums[i],nums[lft],nums[rgt]};
                    // res.push_back(tmp);

                    int lfv = nums[lft], rgv = nums[rgt];
                    while (lft < rgt && nums[lft] == lfv)
                        lft++;
                    while (lft < rgt && nums[rgt] == rgv)
                        rgt--;

                    res.push_back({nums[i], lfv, rgv});
                }
                else if (sum > 0)
                    rgt--;
                else if (sum < 0)
                    lft++;
            } // end while

            // remove duplicate i
            while (i < nums.size() - 2 && nums[i] == nums[i + 1])
                i++;
        } // end for

        return res;
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size() - 2; i++)// the last third number
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1]) // remove duplicate i
                continue;
            size_t lft = i + 1, rgt = nums.size() - 1;
            int target = 0 - nums[i];
            while (lft < rgt)
            {
                if (nums[lft] + nums[rgt] > target)
                {
                    rgt--;
                }
                else if (nums[lft] + nums[rgt] < target)
                {
                    lft++;
                }
                else if (nums[lft] + nums[rgt] == target)
                {
                    res.emplace_back(
                        std::vector<int>{nums[lft], nums[rgt], nums[i]});
                    int lfv = nums[lft], rgv = nums[rgt];
                    while (lft < rgt && nums[lft] == lfv)
                        lft++;
                    while (lft < rgt && nums[rgt] == rgv)
                        rgt--;
                }
            }
        }
        return std::move(res);
    }
};
// @lc code=end
