/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start
class Solution {
public:
/*
    N : number of nodes this graph
    Time:  O(N * 2^N)
    Space: O(N)
*/
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> res;
        vector<int> path;
        travers(graph,0,res,path);
        return res;
    }

    void travers(vector<vector<int>>& graph,int nodes,vector<vector<int>>& res,vector<int>& path)
    {
        path.push_back(nodes);

        if(nodes == graph.size()-1) //reach end node of this graph
        {
            res.push_back(path);
            path.pop_back(); //backforward previous node
            return ;
        }

        for(auto const s: graph[nodes])
        {
            travers(graph,s,res,path);
        }

        path.pop_back();
    }
};
// @lc code=end

