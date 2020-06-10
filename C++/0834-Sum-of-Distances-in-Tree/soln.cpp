class Solution {
    vector<vector<int>> tree;
    vector<int> dist;
    vector<int> count;

public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        tree.resize(N);
        dist.assign(N, 0);
        count.assign(N, 1);
        for(auto & edge : edges) {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        dfs1(0, -1, 0, ans);
        dist[0] = ans;
        dfs2(0, -1, N);
        return dist;
    }
    
    
    void dfs1(int node, int parent, int path, int & ans) {
        ans += path;
        for(int nei : tree[node]) {
            if (nei != parent) {
                dfs1(nei, node, path + 1, ans);
                count[node] += count[nei];
            }
        }
    }
    
    void dfs2(int node, int parent, int N) {
        for(int nei : tree[node]) {
            if (nei != parent) {
                dist[nei] = dist[node] - count[nei] + N - count[nei];
                dfs2(nei, node, N);
            }
        }
    }
    
};
