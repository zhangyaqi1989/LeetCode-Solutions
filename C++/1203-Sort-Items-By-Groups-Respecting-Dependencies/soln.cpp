class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // two levels of topological sort
        // need to know which group it belongs to
        int cur = m;
        m += count(group.begin(), group.end(), -1); // m is number of groups
        vector<vector<int>> members(m);
        for(int i = 0; i < n; ++i) {
            if(group[i] == -1) group[i] = cur++;
            members[group[i]].push_back(i);
        }
        vector<vector<pair<int, int>>> edges(m);
        vector<int> gindegrees(m, 0);
        vector<vector<int>> outs(m);
        for(int v = 0; v < n; ++v) {
            // cout << v << endl;
            const auto & befores = beforeItems[v];
            for(int u : befores) {
                int gu = group[u];
                int gv = group[v];
                if (gu == gv) {
                    edges[gu].emplace_back(u, v);
                } else {
                    ++gindegrees[gv];
                    outs[gu].push_back(gv);
                }
            }
        }
        // sort groups
        int cnt = 0;
        vector<int> gorder;
        vector<int> frees;
        for(int i = 0; i < m; ++i) {
            if(!gindegrees[i]) frees.push_back(i);
        }
        // cout << " Hello " << endl;
        while (!frees.empty()) {
            int u = frees.back();
            frees.pop_back();
            gorder.push_back(u);
            for(int v : outs[u]) {
                if (--gindegrees[v] == 0) frees.push_back(v);
            }
        }
        // cout << gorder.size() << endl;
        if (gorder.size() != m) return {};
        vector<int> order;
        for(int gidx : gorder) {
            if (!topological_sort(edges[gidx], members[gidx], order)) return {};
        }
        return order;
    }
private:
    bool topological_sort(const vector<pair<int, int>> & edges, const vector<int> & member, vector<int> & order) {
        int cnt = 0;
        unordered_map<int, int> indegrees;
        unordered_map<int, vector<int>> outs;
        for(const auto & edge : edges) {
            int u, v;
            tie(u, v) = edge;
            ++indegrees[v];
            outs[u].push_back(v);
        }
        vector<int> frees;
        for(int u : member) {
            if (indegrees[u] == 0) frees.push_back(u);
        }
        while(!frees.empty()) {
            int u = frees.back();
            frees.pop_back();
            order.push_back(u);
            ++cnt;
            for(int v : outs[u]) {
                if (--indegrees[v] == 0) frees.push_back(v);
            }
        }
        return cnt == member.size();
        
    }
};
