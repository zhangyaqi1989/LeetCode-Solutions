class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegrees(n, 0);
        for(const auto & edge : edges) {
            int u = edge[0], v = edge[1];
            ++indegrees[v];
        }
        vector<int> ans;
        for(int u = 0; u < n; ++u) {
            if(!indegrees[u]) ans.push_back(u);
        }
        return ans;
    }
};
