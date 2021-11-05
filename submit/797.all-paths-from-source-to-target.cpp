/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> res;
        vector<int> path;
        travers(graph,0,res,path);
        return res;
    }

    void travers(vector<vector<int>>& graph,int level,vector<vector<int>>& res,vector<int>& path)
    {
        path.push_back(level);

        if(level == graph.size()-1)
        {
            res.push_back(path);
            path.pop_back();
            return ;
        }

        for(auto const s: graph[level])
        {
            travers(graph,s,res,path);
        }

        path.pop_back();
    }
};
// @lc code=end

