
auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> sizes (1 + n, 1);
        vector<int> parent (1 + n, 0);
        iota(parent.begin(), parent.end(), 0);
        for(auto & e : edges) {
            int u = e[0], v = e[1];
            int ru = find(u, parent);
            int rv = find(v, parent);
            if (ru == rv) return {u, v};
            unite(ru, rv, parent, sizes);
        }
        return {};
    }
    
    int find(int x, vector<int> & parent) {
        return parent[x] == x ? x : parent[x] = find(parent[x], parent);
    }
    
    void unite(int x, int y, vector<int> & parent, vector<int> & sizes) {
        int rx = find(x, parent);
        int ry = find(y, parent);
        if (rx == ry) return;
        if (sizes[y] < sizes[x]) swap(rx, ry);
        parent[rx] = parent[ry];
        sizes[ry] += sizes[rx];
    }
};
