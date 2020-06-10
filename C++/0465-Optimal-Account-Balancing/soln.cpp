class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> balances;
        for(const auto & t : transactions) {
            int x = t[0], y = t[1], z = t[2];
            balances[x] -= z;
            balances[y] += z;
        }
        vector<int> arr;
        for(auto & p : balances) {
            if (p.second != 0) arr.push_back(p.second);
        }
        int ans = INT_MAX;
        dfs(0, arr, ans, 0);
        return ans;
    }
private:
    void dfs(int idx, vector<int> & arr, int & ans, int moves) {
        if (moves > ans) return;
        const int n = arr.size();
        while (idx < n && arr[idx] == 0) ++idx;
        if(idx == n) {
            ans = min(ans, moves);
        } else {
            for(int j = idx + 1; j < n; ++j) {
                if (arr[j] * arr[idx] < 0) {
                    int temp = arr[idx];
                    arr[idx] = 0;
                    arr[j] += temp;
                    dfs(idx + 1, arr, ans, moves + 1);
                    arr[idx] = temp;
                    arr[j] -= temp;
                }
            }
        }
    }
};
