import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @lc app=leetcode id=15 lang=java
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
Arrays.sort(nums);

        for(int i=0; i<nums.length-1; i++){
            List<List<Integer>> tmp = twsum(nums, i+1, 0-nums[i]);

            for(int j=0; j<tmp.size(); j++){
                tmp.get(j).add(nums[i]);
                res.add(tmp.get(j));
            }

            while(i < nums.length-1 && nums[i]== nums[i+1]) i++;
        }
        return res;
    }

    //lft: index start from in array
    public List<List<Integer>> twsum(int[] nums, int lft, int tar){
        int rgt = nums.length-1;
        List<List<Integer>> res = new ArrayList<>();

        while(lft < rgt){
            int sum = nums[lft] + nums[rgt];
            if(sum > tar)
                rgt--;
            else if(sum < tar)
                lft++;
            else{
                int lfval = nums[lft], rgval = nums[rgt];
                List<Integer> tmp = new ArrayList<>();
                tmp.add(nums[lft++]);tmp.add(nums[rgt--]);
                res.add(tmp);

                while(lft < rgt && nums[lft] == lfval) lft++;
                while(lft < rgt && nums[rgt] == rgval) rgt--;
            }
        }//end while
        return res;
    }
}
// @lc code=end

