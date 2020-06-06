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
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return;
    if (sizes[y] < sizes[x]) swap(x, y);
    parent[rx] = parent[ry];
    sizes[ry] += sizes[rx];
}

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 0; i < N; ++i) {
            parent[i] = i;
            sizes[i] = 1;
        }
        for(auto & edge : edges) {
            int u = edge[0], v = edge[1];
            int ru = find(u), rv = find(v);
            if (ru == rv) return {u, v};
            unite(ru, rv);
        }
        return {};
    }
};
