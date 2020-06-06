class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> degrees(n, 0);
        vector<int> graph[n];
        for(auto & p : edges) {
            int a = p.first, b = p.second;
            ++degrees[a];
            ++degrees[b];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        set<int> s;
        for(int i = 0; i < n; ++i) s.insert(i);
        while (s.size() > 2) {
            vector<int> leafs;
            for(int i = 0; i < n; ++i) {
                if(degrees[i] == 1) leafs.push_back(i);
            }
            for(int leaf : leafs) {
                degrees[leaf] = 0;
                for(auto nei : graph[leaf]) --degrees[nei];
                s.erase(leaf);
            }
        }
        vector<int> ans;
        for(int node : s) ans.push_back(node);
        return ans;
    }
};
