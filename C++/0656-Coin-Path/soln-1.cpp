class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        const int n = A.size();
        vector<pair<int, int>> memo(n, {-1, n + 1});
        vector<int> sucs(n, -1);
        if (A[n - 1] != -1) {
            memo[n - 1].first = A[n - 1];
            memo[n - 1].second = 1;
        }
        // cout << A.size() << endl;
        vector<int> path;
        if (dfs(0, A, B, memo, sucs).first == INT_MAX) return path;
        int cur = 0;
        while (cur != -1) {
            path.push_back(cur + 1);
            cur = sucs[cur];
        }
        // reverse(path.begin(), path.end());
        return path;
    }
    
private:
    pair<int, int> dfs(int cur, vector<int> & A, int B, vector<pair<int, int>> & memo, vector<int> & sucs) {
        const int n = A.size();
        if (A[cur] == -1) return {INT_MAX, n + 1};
        if (memo[cur].first != -1) return memo[cur];
        int cost = INT_MAX;
        int length = n + 1;
        for(int step = 1; step <= B; ++step) {
            if (cur + step >= n) break;
            if (A[cur + step] == -1) continue;
            auto temp = dfs(cur + step, A, B, memo, sucs);
            if (temp.first == INT_MAX) continue;
            if (temp.first + A[cur] < cost) {
                sucs[cur] = cur + step;
                cost = temp.first + A[cur];
                length = temp.second + 1;
            }
        }
        memo[cur] = {cost, length};
        return {cost, length};
    }
};
