auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

const int N = 1003;

int parent[N] = {0};
int sizes[N] = {0};

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx == ry) return;
    if (sizes[ry] < sizes[rx]) swap(rx, ry);
    parent[rx] = ry;
    sizes[ry] += sizes[rx];
}

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> candA, candB;
        for(int i = 0; i < N; ++i) parent[i] = 0;
        // check if a node has two parents
        for(auto & edge : edges) {
            int u = edge[0], v = edge[1];
            if (parent[v] != 0) {
                candA = {parent[v], v};
                candB = {u, v};
                edge[1] = 0;
            }
            parent[v] = u;
        }
        
        // union find
        for(int i = 0; i < N; ++i) {
            parent[i] = i;
            sizes[i] = 1;
        }
        
        
        
        for(auto & edge : edges) {
            int u = edge[0], v = edge[1];
            if (v == 0) continue;
            int ru = find(u);
            int rv = find(v);
            if (ru == rv) {
                if (candA.empty()) return {u, v};
                else return candA;
            }
            unite(ru, rv);
        }
        
        return candB;
        
    }
};
