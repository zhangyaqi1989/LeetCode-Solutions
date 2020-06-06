class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combis;
        vector<int> combi;
        dfs(0, n, k, &combi, &combis);
        return combis;
    }
    
private:
    void dfs(int pre, int n, int k, vector<int> * combi, vector<vector<int>> * combis) {
        if (static_cast<int>(combi->size()) == k) {
            combis->push_back(*combi);
        } else {
            for(int nxt = pre + 1; nxt <= n; ++nxt) {
                combi->push_back(nxt);
                dfs(nxt, n, k, combi, combis);
                combi->pop_back();
            }
        }
    }
};
