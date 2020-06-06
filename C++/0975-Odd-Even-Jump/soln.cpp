class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        // j > i
        // odd: A[i] <= A[j] smallest possible value
        // even: A[i] >= A[j]
        // how to compute candidates
        const int n = A.size();
        vector<vector<int>> nxts(2, vector<int>(n, -1));
        map<int, int> rights;
        for(int i = n - 1; i >= 0; --i) {
            auto it = rights.lower_bound(A[i]);
            if (it != rights.end()) {
                nxts[1][i] = it->second;
            }
            if (it != rights.end() && it->first == A[i]) {
                nxts[0][i] = it->second;
            } else {
                if (it != rights.begin()) {
                    nxts[0][i] = prev(it)->second;
                }
            }            
            rights[A[i]] = i;
        }
        vector<vector<int>> memo(2, vector<int>(n, -1));
        memo[0][n - 1] = memo[1][n - 1] = 1;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if (dfs(i, memo, nxts, 1)) {
                ++cnt;
            }
        }
        return cnt;
    }
private:
    bool dfs(int idx, vector<vector<int>> & memo, const vector<vector<int>> & cands, int t) {
        if (memo[t][idx] != -1) return memo[t][idx];
        int nxt = cands[t][idx];
        bool ans = false;
        if (nxt != -1 && dfs(nxt, memo, cands, 1 - t)) ans = true;
        memo[t][idx] = ans;
        return ans;
    }
};
