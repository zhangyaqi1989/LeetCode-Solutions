class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path = {0};
        vector<vector<int>> ans;
        dfs(graph, path, ans);
        return ans;
    }
    
    void dfs(vector<vector<int>>& graph, vector<int> & path, vector<vector<int>>& ans) {
        if (path.back() == graph.size() - 1) {
            ans.push_back(path);
        } else {
            int node = path.back();
            for(int nei : graph[node]) {
                path.push_back(nei);
                dfs(graph, path, ans);
                path.pop_back();
            }
        }
    }
    
    
};
