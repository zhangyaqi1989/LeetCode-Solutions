class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parents(n + 1, 0);
        for(int i = 0; i < n + 1; ++i) parents[i] = i;
        for(auto e : edges) {
            int x = e[0], y = e[1];
            int rx = find(x, parents), ry = find(y, parents);
            if (rx == ry) return e;
            else parents[rx] = ry;
        }
        return {0, 0};
    }
    
    int find(int x, vector<int> & parents) {
        return parents[x] == x ? parents[x] : parents[x] = find(parents[x], parents);
    }
};
