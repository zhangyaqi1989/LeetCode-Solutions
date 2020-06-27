class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<vector<int>> graph(n);
        vector<int> indegrees(n, 0);
        vector<int> depths(n, -1);
        for(const auto & edge : dependencies) {
            int u = edge[0] - 1, v = edge[1] - 1;
            ++indegrees[v];
            graph[u].push_back(v);
        }
        priority_queue<pair<int, int>> frees;
        for(int u = 0; u < n; ++u) {
            depths[u] = ComputeDepth(u, graph, & depths);
            if (!indegrees[u]) frees.push({depths[u], u});
        }
        int cnt = 0;
        while(!frees.empty()) {
            int ntakes = min(static_cast<int>(frees.size()), k);
            ++cnt;
            vector<pair<int, int>> nxts;
            for(int i = 0; i < ntakes; ++i) {
                auto p = frees.top();
                frees.pop();
                int u = p.second;
                for(int v : graph[u]) {
                    if(--indegrees[v] == 0) {
                        nxts.emplace_back(depths[v], v);
                    }
                }
            }
            for(auto item : nxts) {
                frees.push(item);
            }
        }
        return cnt;
    }
    
    int ComputeDepth(int u, const vector<vector<int>> & graph, vector<int> * depths) {
        if(depths->at(u) == -1) depths->at(u) = 0;
        for(int v : graph[u]) {
            depths->at(u) = max(depths->at(u), 1 + ComputeDepth(v, graph, depths));
        }
        return depths->at(u);
    }
    
    
};
