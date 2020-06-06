auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// ALG
// 1. DFS
// 2. retrive the path

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> pre[n];
        stack<int> s;
        s.push(0);
        int visited[n] = {0};
        visited[0] = 1;
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            for(auto nei : graph[node]) {
                pre[nei].push_back(node);
                if (!visited[nei]) {
                    s.push(nei);
                    visited[nei] = 1;
                }
            }
        }
        
        vector<int> path = {n - 1};
        vector<vector<int>> ans;
        computePath(n - 1, path, pre, ans);
        for(auto & path : ans) {
            reverse(path.begin(), path.end());
        }
        return ans;
    }
    
    void computePath(int i, vector<int> & path, vector<int> pre[], vector<vector<int>> & ans ){
        if(i == 0) {
            ans.push_back(path);
        } else {
            for(auto parent : pre[i]) {
                path.push_back(parent);
                computePath(parent, path, pre, ans);
                path.pop_back();
            }
        }
    }
};
