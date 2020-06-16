class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        height_ = 20;
        table_.assign(n, vector<int>(height_, -1));
        for(int i = 0; i < n; ++i) table_[i][0] = parent[i];
        for(int i = 1; i < height_; ++i) {
            for(int node = 0; node < n; ++node) {
                int j = table_[node][i - 1];
                if (j != -1) table_[node][i] = table_[j][i - 1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < height_; ++i) {
            if(k & (1 << i)) {
                node = table_[node][i];
            }
            if(node == -1) break;
        }
        return node;
    }
    
private:
    vector<vector<int>> table_;
    int height_;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
