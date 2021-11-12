/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        vector<int> out, visited(num.size(), 0);
        backtrack(num, 0, visited, out, res);
        return res;
    }
    
    void backtrack(vector<int>& num, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res) {
        
        //level is recored current number of visited
        if (level == num.size()) {
                res.push_back(out); 
                return;
            }

        for (int i = 0; i < num.size(); ++i) {
            if (visited[i] == 1) //position of num array
                continue;

            visited[i] = 1;
            out.push_back(num[i]); //make choice

            backtrack(num, level + 1, visited, out, res);

            out.pop_back(); //cancel the choice
            visited[i] = 0;
        }//end for
    }
};

// @lc code=end

