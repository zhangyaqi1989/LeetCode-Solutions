class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        return dfs(n, 2);
    }
    
private:
    vector<vector<int>> dfs(int n, int lo) {
        vector<vector<int>> factors;
        for(int factor = lo; factor * factor <= n; ++factor) {
            if (n % factor == 0) {
                factors.push_back({factor, n / factor});
                vector<vector<int>> tail = dfs(n / factor, factor);
                for(auto & item : tail) {
                    item.insert(item.begin(), factor);
                    factors.push_back(item);
                }
            }
        }
        return factors;
    }
};
