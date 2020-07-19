class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> tree(n);
        for(const auto & e : edges) {
            int u = e[0], v = e[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        vector<int> ans(n, 1);
        Postorder(0, -1, labels, tree, & ans);
        return ans;
    }
    
    vector<int> Postorder(int node, int parent, const string & labels, 
                          const vector<vector<int>> & tree, vector<int> * ans) {
        vector<int> counter(26, 0);
        for(int nei : tree[node]) {
            if(nei == parent) continue;
            vector<int> temp = Postorder(nei, node, labels, tree, ans);
            for(int i = 0; i < 26; ++i) {
                counter[i] += temp[i];
            }
        }
        ans->at(node) = ++counter[labels[node] - 'a'];
        return counter;
    }
};
