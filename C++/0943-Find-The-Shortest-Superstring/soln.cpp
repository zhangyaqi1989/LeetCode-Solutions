class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        const int n = A.size();
        vector<vector<int>> edges(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                edges[i][j] = distance(A, i, j);
                edges[j][i] = distance(A, j, i);
            }
        }
        const int INF = 10000;
        int total = 1 << n;
        vector<vector<int>> dp(total, vector<int>(n, INF));
        for(int i = 0; i < n; ++i) {
            dp[1 << i][i] = A[i].length();
        }
        // parent pointer
        map<pair<int, int>, pair<int, int>> pt;
        for(int i = 1; i < total; ++i) {
            for(int cur = 0; cur < n; ++cur) {
                if ((i & (1 << cur)) == 0) continue;
                int prev = (i ^ (1 << cur));
                for(int j = 0; j < n; ++j) {
                    if ((prev & (1 << j)) == 0) continue;
                    if(dp[i][cur] > dp[prev][j] + edges[j][cur]) {
                        dp[i][cur] = dp[prev][j] + edges[j][cur];
                        pt[{i, cur}] = {prev, j};
                    }
                }
            }
        }
        int end = 0;
        int len = INF;
        int target = (1 << n) - 1;
        for(int i = 0; i < n; ++i) {
            if (dp[target][i] < len) {
                len = dp[target][i];
                end = i;
            }
        }
        pair<int, int> state = {target, end};
        vector<int> idxes;
        while (true) {
            idxes.push_back(state.second);
            auto parent = pt[state];
            if (parent.first == 0) {
                break;
            }
            swap(state, parent);
        }
        reverse(idxes.begin(), idxes.end());
        string ans = A[idxes[0]];
        for(int i = 1; i < (int) idxes.size(); ++i) {
            int len = edges[idxes[i - 1]][idxes[i]];
            ans += A[idxes[i]].substr((int) A[idxes[i]].length() - len);
        }
        return ans;
    }
    

private:
    // added length when jth is appended to ith
    int distance(vector<string> & A, int i, int j) {
        string wi = A[i];
        string wj = A[j];
        int ni = wi.length();
        int nj = wj.length();
        int overlap = min(ni, nj);
        while (overlap > 0 && wi.substr(ni - overlap) != wj.substr(0, overlap)) --overlap;
        return nj - overlap;
    }
};
