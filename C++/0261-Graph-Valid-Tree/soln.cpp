class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n - 1) return false;
        int parents[n] = {0};
        for(int i = 0; i < n; ++i) parents[i] = i;
        for(auto & edge : edges) {
            int a = edge.first, b = edge.second;
            int ra = find(a, parents);
            int rb = find(b, parents);
            if (ra == rb) return false;
            parents[ra] = parents[rb];
        }
        return true;
        
    }
    
    int find(int x, int parents[]) {
        if (x == parents[x]) return x;
        else {
            parents[x] = find(parents[x], parents);
            return parents[x];
        }
    }
};
