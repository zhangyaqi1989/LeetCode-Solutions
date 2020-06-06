class Solution {
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        vector<vector<int>> tree(nodes);
        for(int i = 0; i < nodes; ++i) {
            if (parent[i] != -1)
                tree[parent[i]].push_back(i);
        }
        int removed = 0;
        PostOrder(tree, value, 0, &removed);
        return nodes - removed;
    }
private:
    pair<int, int> PostOrder(const vector<vector<int>> & tree, const vector<int> & value, int node, int * removed) {
        int count = 1, sum = value[node];
        for(int child : tree[node]) {
            auto p = PostOrder(tree, value, child, removed);
            count += p.first;
            sum += p.second;
        }
        if (sum == 0) {
            *removed += count;
            count = 0;
        }
        return {count, sum};
    }
};
