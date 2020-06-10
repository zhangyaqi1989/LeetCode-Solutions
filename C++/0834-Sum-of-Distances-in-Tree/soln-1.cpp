class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<int> dists(N, 0);
        vector<int> count(N, 0);
        vector<unordered_set<int>> tree(N);
        for(const auto & edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].insert(v);
            tree[v].insert(u);
        }
        int dist = 0;
        postorder(0, -1, tree, count, 0, dist);
        dists[0] = dist;
        preorder(0, -1, tree, count, dists, N);
        return dists;
    }
    
private:
    void preorder(int node, int parent, const vector<unordered_set<int>> & tree, vector<int> & count, vector<int> & dists, int n) {
        if (parent != -1) dists[node] = dists[parent] - count[node] + n - count[node];
        for(int child : tree[node]) {
            if (child == parent) continue;
            preorder(child, node, tree, count, dists, n);
        }
    }

    void postorder(int node, int parent, const vector<unordered_set<int>> & tree, vector<int> & count, int path, int & dist) {
        dist += path;
        int cnt = 0;
        for(int child : tree[node]) {
            if (child == parent) continue;
            postorder(child, node, tree, count, path + 1, dist);
            cnt += count[child];
        }
        count[node] = cnt + 1;
    }
};
