class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // need to know how many
        vector<vector<int>> tree(n);
        for(auto & e : edges) {
            int u = e[0], v = e[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        int n_deletes = 0;
        Postorder(tree, hasApple, 0, -1, &n_deletes);
        return (n - n_deletes - 1) * 2;
    }
    
private:
    int Postorder(const vector<vector<int>> & tree, const vector<bool> & hasApple, 
                  int u, int parent, int * n_deletes) {
        int n_apples = 0;
        for(int v : tree[u]) {
            if(v != parent) {
                n_apples += Postorder(tree, hasApple, v, u, n_deletes);
            }
        }
        if (hasApple[u]) ++n_apples;
        if(parent != -1 && n_apples == 0) *n_deletes += 1;
        return n_apples;
    }
};
