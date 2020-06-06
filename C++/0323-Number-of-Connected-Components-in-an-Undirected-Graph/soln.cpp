class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        if (n == 0) return 0;
        int parents[n] = {0};
        for(int i = 0; i < n; ++i) parents[i] = i;
        for(auto & p : edges) {
            unite(p.first, p.second, parents);
        }
        for(int i = 0; i < n; ++i) find(i, parents);
        return set<int> (parents, parents + n).size();
    }
    
    int find(int x, int parents[]) {
        return x == parents[x] ? x : parents[x] = find(parents[x], parents);
    }
    
    void unite(int x, int y, int parents[]) {
        int rx = find(x, parents);
        int ry = find(y, parents);
        if (rx != ry) parents[rx] = parents[ry];
    }
};
