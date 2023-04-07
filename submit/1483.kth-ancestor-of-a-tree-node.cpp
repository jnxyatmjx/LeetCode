/*
 * @lc app=leetcode id=1483 lang=cpp
 *
 * [1483] Kth Ancestor of a Tree Node
 */

// @lc code=start
class TreeAncestor {
private:
    vector<vector<int>> dp;

public:
    TreeAncestor(int n, vector<int>& parent) : dp(n) {

        for(int i = 0; i < n; i ++)
            dp[i].push_back(parent[i]);

        for(int j = 1; ; j ++){
            bool allneg = true;
            for(int i = 0; i < n; i ++){
                int t = dp[i][j - 1] != -1 ? dp[dp[i][j - 1]][j - 1] : -1;
                dp[i].push_back(t);
                if(t != -1) allneg = false;
            }
            if(allneg) break; // 所有的节点的 2^j 的祖先都是 -1 了，就不用再计算了
        }
    }

    int getKthAncestor(int node, int k) {

        if(k == 0 || node== -1) return node;

        int pos = ffs(k) - 1;//ffs() returns the position of the first (least significant) bit set in the word i. 第一个置位值

        return pos < dp[node].size() ? getKthAncestor(dp[node][pos], k - (1 << pos)) : -1;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
// @lc code=end

