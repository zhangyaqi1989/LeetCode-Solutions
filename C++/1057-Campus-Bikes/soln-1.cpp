class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // N, M
        // smallest
        const int N = workers.size(), M = bikes.size();
        vector<tuple<int, int, int>> candidates;
        vector<int> ans(N, -1);
        vector<bool> used(M, false);
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                const auto & w = workers[i];
                const auto & b = bikes[j];
                candidates.push_back({-abs(w[0] - b[0]) - abs(w[1] - b[1]), -i, -j});
            }
        }
        make_heap(candidates.begin(), candidates.end());
        int assigned = 0;
        while (assigned < N) {
            int d, i, j;
            tie(d, i, j) = candidates.front();
            i = -i;
            j = -j;
            pop_heap(candidates.begin(), candidates.end());
            candidates.pop_back();
            if (ans[i] == -1 && !used[j]) {
                used[j] = true;
                ans[i] = j;
                ++assigned;
            }
        }
        return ans;
    }
};
