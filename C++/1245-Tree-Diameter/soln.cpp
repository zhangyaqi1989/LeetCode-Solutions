class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        const int n = edges.size();
        if (n == 0) return 0;
        vector<vector<int>> tree(n + 1);
        for(const auto & edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        int ans = 0;
        postorder(0, -1, tree, ans);
        return ans - 1;
    }
    
private:
    int postorder(int node, int parent, const vector<vector<int>> & tree, int & ans) {
        vector<int> hs;
        for(int nei : tree[node]) {
            if (nei != parent) {
                int h = postorder(nei, node, tree, ans);
                hs.push_back(h);
            }
        }
        sort(hs.rbegin(), hs.rend());
        int first = 0, second = 0;
        if (hs.size() == 1) {
            first = hs[0];
        } else if (hs.size() >= 2) {
            first = hs[0];
            second = hs[1];
        }
        ans = max(ans, first + second + 1);
        return first + 1;
    }
};
